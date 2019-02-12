# -*- coding: utf-8 -*-
#
#  TECS Generator
#      Generator for TOPPERS Embedded Component System
#  
#   Copyright (C) 2017 by TOPPERS Project
#--
#   上記著作権者は，以下の(1)〜(4)の条件を満たす場合に限り，本ソフトウェ
#   ア（本ソフトウェアを改変したものを含む．以下同じ）を使用・複製・改
#   変・再配布（以下，利用と呼ぶ）することを無償で許諾する．
#   (1) 本ソフトウェアをソースコードの形で利用する場合には，上記の著作
#       権表示，この利用条件および下記の無保証規定が，そのままの形でソー
#       スコード中に含まれていること．
#   (2) 本ソフトウェアを，ライブラリ形式など，他のソフトウェア開発に使
#       用できる形で再配布する場合には，再配布に伴うドキュメント（利用
#       者マニュアルなど）に，上記の著作権表示，この利用条件および下記
#       の無保証規定を掲載すること．
#   (3) 本ソフトウェアを，機器に組み込むなど，他のソフトウェア開発に使
#       用できない形で再配布する場合には，次のいずれかの条件を満たすこ
#       と．
#     (a) 再配布に伴うドキュメント（利用者マニュアルなど）に，上記の著
#         作権表示，この利用条件および下記の無保証規定を掲載すること．
#     (b) 再配布の形態を，別に定める方法によって，TOPPERSプロジェクトに
#         報告すること．
#   (4) 本ソフトウェアの利用により直接的または間接的に生じるいかなる損
#       害からも，上記著作権者およびTOPPERSプロジェクトを免責すること．
#       また，本ソフトウェアのユーザまたはエンドユーザからのいかなる理
#       由に基づく請求からも，上記著作権者およびTOPPERSプロジェクトを
#       免責すること．
#  
#   本ソフトウェアは，無保証で提供されているものである．上記著作権者お
#   よびTOPPERSプロジェクトは，本ソフトウェアに関して，特定の使用目的
#   に対する適合性も含めて，いかなる保証も行わない．また，本ソフトウェ
#   アの利用により直接的または間接的に生じたいかなる損害に関しても，そ
#   の責任を負わない．
#  
#   $Id: CelltypePlugin.rb 2061 2014-05-31 22:15:33Z okuma-top $
#++

#== CelltypePlugin for tTECSInfo
class TECSInfoPlugin < CelltypePlugin

  @@cell_list = []
  #@celltype::Celltype
  #@plugin_arg_str::String
  #@plugin_arg_list::{argNameString=>argOptionString}
  #@cell_list::[Cell]

  #celltype::     Celltype        セルタイプ（インスタンス）
  def initialize( celltype, option )
    super
  end

  #=== 新しいセル
  #cell::        Cell            セル
  #
  # celltype プラグインを指定されたセルタイプのセルが生成された
  # セルタイププラグインに対する新しいセルの報告
  def new_cell( cell )
    @@cell_list << cell

    # AppFile は、重ね書きようなので、やめる
    # p "import: cell nTECSInfo::tTECSInfoSub TECSInfoSub under #{cell.get_region.get_name}"
    # TECSInfoSub セルのプロトタイプ宣言
    fn = "#{$gen}/tmp_#{cell.get_region.get_global_name}_TECSInfoSub.cdl"
    File.open( fn, "w" ){ |f|
      f.print "/* prototype declaration of TECSInfoSub */\n"
      nest = cell.get_region.gen_region_str_pre f
      indent = "    " * nest
      f.print <<EOT
#{indent}[in_through()]
#{indent}region rTECSInfo {
#{indent}    cell nTECSInfo::tTECSInfoSub TECSInfoSub;
#{indent}}; /* rTECSInfo} */
EOT
      cell.get_region.gen_region_str_post f
    }
    Import.new fn

    # セルに cTECSInfo の結合があるか？
    if cell.get_join_list.get_item( :cTECSInfo ) == nil then
      # cTECSInfo = rTECSInfo::TECSInfosub.eTECSInfo; の追加
      nsp = NamespacePath.new( :rTECSInfo, false )
      nsp.append! :TECSInfoSub
      rhs = Expression.create_cell_join_expression nsp, nil, :eTECSInfo
      join = Join.new :cTECSInfo, nil, rhs
      cell.new_join join
    end
  end

  #=== 後ろの CDL コードを生成
  #プラグインの後ろの CDL コードを生成
  #file:: File: 
  def self.gen_post_code( file )
    # 複数のプラグインの post_code が一つのファイルに含まれるため、以下のような見出しをつけること
    file.print <<EOT
/*------------ #{self.name} post code ------------*/
EOT
    @@cell_list.each{|cell|
      root = cell.get_region # .get_link_root
      TECSInfo.print_info file, root
    }
  end

  #=== tCelltype_factory.h に挿入するコードを生成する
  # file 以外の他のファイルにファクトリコードを生成してもよい
  # セルタイププラグインが指定されたセルタイプのみ呼び出される
  def gen_factory file
    File.open( "#{$gen}/include_all_signature_header.h", "w" ){ |f|
      f.print <<EOT
#ifndef include_all_signature_header_h
#define include_all_signature_header_h

EOT
      Namespace.get_root.travers_all_signature{ |sig|
        f.print "#include \"#{sig.get_global_name}_tecsgen.h\"\n"
      }
      f.print <<EOT

#endif /* include_all_signature_header_h */
EOT
    }

    undefs2 = [ :INITIALIZE_CB, :FOREACH_CELL, :END_FOREACH_CELL ]
    f = AppFile.open( "#{$gen}/nTECSInfo_tVarDeclInfo_factory.h" )
    Namespace.get_root.print_struct_define f

    undefs = [ :VALID_IDX, :GET_CELLCB, :CELLCB, :CELLIDX,
               :tVarDeclInfo_IDX, :ATTR_name, :ATTR_sizeIsExpr,
               :ATTR_declType, :ATTR_offset ]

    f.print <<EOT

/***** Offset of attr & var of celltype  *****/
#define TOPPERS_CB_TYPE_ONLY

/* In case a celltype has 'inline' entry,
 * some macros are temprally defined
 * even if TOPPERS_CB_TYPE_ONLY is defined.
 * To avoid redefinition warning, undef these macros.
 */
#{ str=""; undefs.each{|u| str += "#undef #{u}\n" }; str }
EOT
    if $ram_initializer then
      undefs2.each{|u|
        f.print "#undef #{u}\n"
      }
    end
    Namespace.get_root.print_celltype_define_offset f
    f.print <<EOT

/* redefine macros */
#define tVarDeclInfo_IDX  nTECSInfo_tVarDeclInfo_IDX

EOT
    if $ram_initializer then
      f.print <<EOT
#define FOREACH_CELL(i,p_cb)   { (void)(i);
#define END_FOREACH_CELL   }
#define INITIALIZE_CB(p_that)   (void)(p_that);
#define SET_CB_INIB_POINTER(i,p_that)
EOT
    end
    f.close

    f = AppFile.open( "#{$gen}/nTECSInfo_tCelltypeInfo_factory.h" )
    f.print "\n"
    Namespace.get_root.print_celltype_define f
    f.print "\n"
    f.close
    
    undefs = [ :VALID_IDX, :GET_CELLCB, :CELLCB, :CELLIDX,
               :tCallInfo_IDX, :ATTR_name, :ATTR_offset, :ATTR_b_inCB,
               :ATTR_b_optional, :ATTR_b_omit, :ATTR_b_dynamic,
               :ATTR_b_ref_desc, :ATTR_b_allocator_port,
               :ATTR_b_require_port, :ATTR_b_VMT_useless,
               :ATTR_b_skelton_useless, :ATTR_b_cell_unique,
               :cSignatureInfo_getName, :cSignatureInfo_getNameLength,
               :cSignatureInfo_getNFunction,
               :cSignatureInfo_getFunctionInfo,
               :cSignatureInfo_refer_to_descriptor,
               :cSignatureInfo_ref_desc, :eCallInfo_getName,
               :eCallInfo_getNameLength, :eCallInfo_getSignatureInfo,
               :eCallInfo_getArraySize, :eCallInfo_isOptional,
               :eCallInfo_isDynamic, :eCallInfo_isRefDesc,
               :eCallInfo_isOmit ]

    f = AppFile.open( "#{$gen}/nTECSInfo_tCallInfo_factory.h" )
    f.print <<EOT

/***** Offset of attr & var of celltype  *****/
#define TOPPERS_CB_TYPE_ONLY

/* In case a celltype has 'inline' entry,
 * some macros are temprally defined
 * even if TOPPERS_CB_TYPE_ONLY is defined.
 * To avoid redefinition warning, undef these macros.
 */
#{ str=""; undefs.each{|u| str += "#undef #{u}\n" }; str }
EOT
    if $ram_initializer then
      undefs2.each{|u|
        f.print "#undef #{u}\n"
      }
    end

    Namespace.get_root.print_call_define f
    f.print <<EOT

/* redefine macros */
#define tCallInfo_IDX  nTECSInfo_tCallInfo_IDX

EOT
    if $ram_initializer then
      f.print <<EOT
#define FOREACH_CELL(i,p_cb)   { (void)(i);
#define END_FOREACH_CELL   }
#define INITIALIZE_CB(p_that)   (void)(p_that);
#define SET_CB_INIB_POINTER(i,p_that)

EOT
    end
    f.close
  end

  #=== 後ろの CDL コードを生成
  #プラグインの後ろの CDL コードを生成
  #file:: File:
  def self.gen_post_code( file )
    # 複数のプラグインの post_code が一つのファイルに含まれるため、以下のような見出しをつけること
    file.print <<EOT
/*------------ #{self.name} post code ------------*/
EOT
    @@cell_list.each{|cell|
      root = cell.get_region # .get_link_root
      TECSInfo.print_info file, root
    }
  end
end

