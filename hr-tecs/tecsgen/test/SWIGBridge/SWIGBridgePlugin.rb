# -*- coding: utf-8 -*-
#== SWIG を使って Ruby ⇒ TECS コンポーネントを生成するシグニチャプラグイン
class SWIGBridgePlugin < SignaturePlugin

  @@instances = { }        # @signature => [ SWIGBridgePlugin のインスタンスの配列 ]
  @@b_written = false      # ファイル .i, .cxx, .hxx 出力済み

  def initialize( signature, option )
    super
    signature.each_param{ |func_decl, param_decl|
      case param_decl.get_direction
      when :INOUT, :OUT, :SEND, :RECEIVE
        Generator.error( "#{param_decl.get_direction.to_s.downcase} parameter cannot be used in Ruby Bridge" )
      end
      if param_decl.get_size
      elsif param_decl.get_count
      elsif param_decl.get_string
      end
    }
    @celltype_name = "tSWIG#{@signature.get_name}Bridge"
    @class_name = "C#{@signature.get_name}"
    if @@instances[signature] then
      @@instances[signature] << self
    else
      @@instances[signature] = [ self ]
    end

  end

  #===  CDL ファイルの生成
  #      typedef, signature, celltype, cell コードを生成
  #file::        FILE       生成するファイル
  def gen_cdl_file(file)

    # ブリッジセルタイプの生成
    file.print <<EOT
/// Ruby ⇒ TECS ブリッジセルタイプ ///
[idx_is_id]
celltype #{@celltype_name} {
    call #{@signature.get_name} cTECS;
};
EOT

  end

  #file::        FILE       生成するファイル
  #===  受け口関数の postamble (C言語)を生成する
  def gen_postamble( file, b_singleton, ct_name, global_ct_name )

    # mikan namespace
    ct = Namespace.find( ["::", ct_name ] )
    gen_cxx ct
    gen_hxx ct
    if @@b_written == false then
      @@b_written = true
      @@instances.each{ |signature, instances|
        ct = Namespace.find( [ "::", instances[0].get_celltype_name.to_sym ] )
        instances[0].gen_i ct
      }
    end
  end

  def gen_cxx ct

    file = CFile.open( "#{$gen}/#{@class_name}.cxx", "w" )

    file.print <<EOT
#include  <stdlib.h>
#include  <memory.h>
#include  <stdio.h>
#include  "#{@celltype_name}_tecsgen.h"
#include  "#{@class_name}.hxx"

EOT

    ct.get_cell_list.each{ |cell|
      if cell.is_generate?
        file.print "char    CELL_#{cell.get_name}[] = \"#{cell.get_name}\";\n"
      end
    }

    file.print <<EOT
struct tagName2ID { char *name; ID id; } Name2ID[] = {
EOT
    ct.get_cell_list.each{ |cell|
      if cell.is_generate?
        file.print "    { CELL_#{cell.get_name}, #{cell.get_id} },\n"
      end
    }

    file.print <<EOT
    { (char*)0, 0 }
};

#{@class_name} *
#{@class_name}::join( const char *CellName )
{
	#{@class_name} *cell = new #{@class_name}( CellName );
	return cell;
}

#{@class_name}::#{@class_name}( const char *CellName )
{
    m_CellName = (char *)malloc( strlen( CellName ) + 1 );
    if( m_CellName )
       strcpy( m_CellName, CellName );
    else
       m_CellName = 0;

    int   i;
    for( i = 0; Name2ID[i].name; i++ )
        if( strcmp( CellName, Name2ID[i].name ) == 0 )
             break;

    if( Name2ID[i].name )
         m_id = Name2ID[i].id;
    else
         m_id = 0;
}
	
#{@class_name}::~#{@class_name}()
{
    if( m_CellName )
        free( m_CellName );
    m_CellName = 0;
    m_id = 0;
}

EOT

    @signature.get_function_head_array.each { |fh|  # fh: FuncHead
      fd = fh.get_declarator                 # fd: Decl (ここで fd が関数以外のことはない)
      ft = fd.get_type                       # ft: FuncType
      ret_type = ft.get_type

      # 関数頭部の出力
      file.printf( "%s\n%s::%s(",
                   ft.get_type_str,
                   @class_name,
                   fd.get_name )
      delim = ""
      ft.get_paramlist.get_items.each { |p| # p:  ParamDecl
        # size_is, count_is, string, send, receive には対応しない
        pd = p.get_declarator                # pd: Decl
        file.printf( "%s %s %s%s",
                     delim,
                     pd.get_type.get_type_str,
                     pd.get_name,
                     pd.get_type.get_type_str_post )
        delim = ", "
      }
      file.print( " )\n{\n" )

      # 戻り値を記憶する変数の定義を出力
      if ret_type.get_original_type.kind_of? VoidType
        retval = ""
        retnul = ""
      else
        file.printf( "\t%s\tretval%s;\n", ft.get_type.get_type_str, ft.get_type.get_type_str_post )
        retval = "retval = "
        retnul = "0"
      end

      file.print <<EOT
    if( ! VALID_IDX( m_id ) )
         return #{retnul};
    CELLCB *p_cellcb = (CELLCB*)GET_CELLCB( m_id );
EOT

      file.printf( "\t%scTECS_%s( ", retval, fd.get_name )
      delim = ""
      ft.get_paramlist.get_items.each { |p| # p:  ParamDecl
        # size_is, count_is, string, send, receive には対応しない
        pd = p.get_declarator                # pd: Decl
        file.printf( "%s%s", delim, pd.get_name )
        delim = ", "
      }
      file.print( " );\n" )
      if ! ret_type.get_original_type.kind_of? VoidType
        file.print( "\treturn\tretval;\n")
      end
      file.print( "}\n\n" )
    }

    file.close
  end

  def gen_hxx ct
    file = CFile.open( "#{$gen}/#{@class_name}.hxx", "w" )
    gen_class file
    file.close
  end

  def gen_i ct

    file = CFile.open( "#{$gen}/SWIGBridge.i", "w" )

    file.print <<EOT
%module SWIGBridge
%{
#include <stdint.h>
#include "global_tecsgen.h"
EOT

    @@instances.each{ |signature, instances|
      file.print "#include \"#{@class_name}.hxx\"\n"
    }

    file.print <<EOT
%}

typedef  int int_t;
typedef  char char_t;
%import stdint.h
%import global_tecsgen.h
EOT

    @@instances.each{ |signature, instances|
      instances[0].gen_class file
    }
    file.close
  end

  def gen_class file
    file.print <<EOT
class #{@class_name} {
public:
    static #{@class_name} *join( const char *CellName );
EOT

    @signature.get_function_head_array.each { |fh|  # fh: FuncHead
      fd = fh.get_declarator                 # fd: Decl (ここで fd が関数以外のことはない)
      ft = fd.get_type                       # ft: FuncType
      ret_type = ft.get_type

      # 関数頭部の出力
      file.printf( "    %s %s(",
                   ft.get_type_str,
                   fd.get_name )
      delim = ""
      ft.get_paramlist.get_items.each { |p| # p:  ParamDecl
        # size_is, count_is, string, send, receive には対応しない
        pd = p.get_declarator                # pd: Decl
        file.printf( "%s %s %s%s",
                     delim,
                     pd.get_type.get_type_str,
                     pd.get_name,
                     pd.get_type.get_type_str_post )
        delim = ", "
      }
      file.print( " );\n" )

    }


    file.print <<EOT

private:
    #{@class_name}( const char *CellName );
    #{@class_name}();
    ~#{@class_name}();

    ID    m_id;
    char  *m_CellName;
};

EOT
  end

  def get_celltype_name
    @celltype_name
  end

end

