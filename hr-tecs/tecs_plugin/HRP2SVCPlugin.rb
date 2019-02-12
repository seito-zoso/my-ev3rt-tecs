#
#  TECS Generator
#      Generator for TOPPERS Embedded Component System
#  
#   Copyright (C) 2008-2014 by TOPPERS Project
#--
#   �嵭����Ԥϡ��ʲ���(1)��(4)�ξ������������˸¤ꡤ�ܥ��եȥ���
#   �����ܥ��եȥ���������Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ������
#   �ѡ������ۡʰʲ������ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
#   (1) �ܥ��եȥ������򥽡��������ɤη������Ѥ�����ˤϡ��嵭������
#       ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ��꤬�����Τޤޤη��ǥ���
#       ����������˴ޤޤ�Ƥ��뤳�ȡ�
#   (2) �ܥ��եȥ������򡤥饤�֥������ʤɡ�¾�Υ��եȥ�������ȯ�˻�
#       �ѤǤ�����Ǻ����ۤ�����ˤϡ������ۤ�ȼ���ɥ�����ȡ�����
#       �ԥޥ˥奢��ʤɡˤˡ��嵭�����ɽ�����������Ѿ�浪��Ӳ���
#       ��̵�ݾڵ����Ǻܤ��뤳�ȡ�
#   (3) �ܥ��եȥ������򡤵�����Ȥ߹���ʤɡ�¾�Υ��եȥ�������ȯ�˻�
#       �ѤǤ��ʤ����Ǻ����ۤ�����ˤϡ����Τ����줫�ξ�����������
#       �ȡ�
#     (a) �����ۤ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭����
#         �ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
#     (b) �����ۤη��֤��̤�������ˡ�ˤ�äơ�TOPPERS�ץ������Ȥ�
#         ��𤹤뤳�ȡ�
#   (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»
#       ������⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ����դ��뤳�ȡ�
#       �ޤ����ܥ��եȥ������Υ桼���ޤ��ϥ���ɥ桼������Τ����ʤ���
#       ͳ�˴�Ť����ᤫ��⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ�
#       ���դ��뤳�ȡ�
#  
#   �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ�
#   ���TOPPERS�ץ������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����λ�����Ū
#   ���Ф���Ŭ������ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ���
#   �������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤��
#   ����Ǥ�����ʤ���
#  
#++

# mikan through plugin: namespace ����θ����Ƥ��ʤ�
# ��������Ѥ����硢�ʲ��Τ褦�� toppers_jsp.cdl sChannel.cdl ����ꤹ��ɬ�פ�����
# tecsgen toppers_jsp.cdl sChannel.cdl your_description.cdl

# �ʲ���������»����
#  �ƤӸ����Ƥ���Υ���ǥ�����char, short, int_t, long_t, intptr_t �Υ�������Ʊ��
#  ͭ��桢̵���ǥ�������Ʊ��

class SVCManage
    # TODO: �ǥե���Ȥγ�ĥ�����ӥ�������ʬ��ͽ�󤷤Ƥ���
    # �ǥե���Ȥγ�ĥ�����ӥ��������syslog�ʤɡˤ⥳��ݡ��ͥ�Ȳ�����ޤ�
    @@id = 20
    @@func_ids = {}
    def self.get_func_id func_name
        return @@func_ids[ func_name ]
    end
    def self.set_func_id func_name
        @@func_ids[ func_name ] = self.assign_id
        puts @@func_ids[ func_name ]
    end
    def self.include_func_id? func_name
        return @@func_ids.has_key?( func_name )
    end
    def self.get_id
        return @@id
    end
    def self.set_id id
        @@id = id
    end
    def self.assign_id
        @@id += 1
        return @@id
    end
end

#
# ��ĥ�����ӥ���������Ѥ����ɥᥤ����̿���
# through�ץ饰����
# HRP2�ɥᥤ��ץ饰����ˤ�ä����������
#
class HRP2SVCPlugin < ThroughPlugin

  #=== RPCPlugin �� initialize
  #  ������ ThroughPlugin (plugin.rb) �򻲾�
  @@generated_celltype_header = {}

  def initialize( cell_name, plugin_arg, next_cell, next_cell_port_name, signature, celltype, caller_cell )
    super
    @ct_name_body = "#{@ct_name}SVCBody_#{@next_cell.get_name}_#{@next_cell_port_name}".to_sym
    @ct_name = "#{@ct_name}SVCCaller_#{@next_cell.get_name}_#{@next_cell_port_name}".to_sym
    @cell_name_body = "#{@cell_name}SVCBody".to_sym
    @cell_name = "#{@cell_name}SVCCaller".to_sym
    puts "%%%% "
    p @next_cell.get_name
    p @caller_cell.get_name
  end

  #=== NamespacePath ������
  # �������륻��� namespace path ����������
  def get_cell_namespace_path
#    nsp = @region.get_namespace.get_namespace_path
    nsp = @start_region.get_namespace_path
    return nsp.append( @cell_name )
  end

  def gen_plugin_decl_code( file )

    # ���Υ��륿���ס�Ʊ�������˥���ˤϴ�����������Ƥ��뤫��
    if !HRP2KernelObjectPlugin.include_celltype?(@next_cell.get_celltype)
    if @@generated_celltype[ @ct_name_body ] == nil then
        @@generated_celltype[ @ct_name_body ] = [ self ]
        file2 = CFile.open( "#{$gen}/#{@ct_name_body}.cdl", "w" )
        file2.print <<EOT
[active]
celltype #{@ct_name_body} {
    call #{@signature.get_name} #{@call_port_name};
};
EOT
        file2.close
    else
      @@generated_celltype[ @ct_name_body ] << self
    end
    file.print "import( \"#{$gen}/#{@ct_name_body}.cdl\" );\n"
    end

    # ���Υ��륿���ס�Ʊ�������˥���ˤϴ�����������Ƥ��뤫��
    if @@generated_celltype[ @ct_name ] == nil then
        @@generated_celltype[ @ct_name ] = [ self ]
        file2 = CFile.open( "#{$gen}/#{@ct_name}.cdl", "w" )
        if !HRP2KernelObjectPlugin.include_celltype?(@next_cell.get_celltype)
        file2.print <<EOT
celltype #{@ct_name} {
    entry #{@signature.get_name} #{@entry_port_name};
};
EOT
        else
            # TODO inline�ˤ���������Ψ���褤����tecsgen�����������إå��ե������
            # �ɹ���Τ���˥��顼�Ȥʤ�
        file2.print <<EOT
celltype #{@ct_name} {
    //[inline] entry #{@signature.get_name} #{@entry_port_name};
    entry #{@signature.get_name} #{@entry_port_name};
    call #{@signature.get_name} #{@call_port_name};
};
EOT
        end
        
        file2.close
    else
      @@generated_celltype[ @ct_name ] << self
    end
    file.print "import( \"#{$gen}/#{@ct_name}.cdl\" );\n"

=begin
    # TODO: send. receive �б�
    send_receive = []
    if @signature != nil then
      @signature.each_param{ |fd,param|
        dir =param.get_direction
        case dir
        when :SEND, :RECEIVE
          send_receive << [ dir, fd, param ]
        end
      }
    end
=end

=begin
composite #{@ct_name} {
    entry #{@signature.get_name} #{@entry_port_name};
    call #{@signature.get_name} #{@call_port_name};

    cell #{@ct_name}Client #{@cell_name}Client{
    };

    [active]
    cell #{@ct_name}Server #{@cell_name}Server{
        #{@call_port_name} => composite.#{@call_port_name};
    };

    composite.#{@entry_port_name} => #{@cell_name}.#{@entry_port_name};
};
=end

  end

  #===  through cell �����ɤ�����
  #
  #
  def gen_through_cell_code( file )
    #require "HRP2Cache"

    gen_plugin_decl_code( file )

    if !HRP2KernelObjectPlugin.include_celltype?(@next_cell.get_celltype)
    # �����õ��
    # path =["::",@next_cell.get_name]  # mikan namespace
    # cell = Namespace.find( path )
    # cell = Namespace.find( @next_cell.get_namespace_path )

    ##### ���饤�����¦�Υ�������� #####
    # file.print "[domain(HRP2, \"trusted\")]"
    nest = @start_region.gen_region_str_pre file
    nest_str = "  " * nest

    # ���饤�����¦�����ͥ������
    # ��ĥ�����ӥ�������ƽФ�
    file.print <<EOT
#{nest_str}  //  Client Side Channel
#{nest_str}  cell #{@ct_name} #{@cell_name}{
#{nest_str}  };

EOT

    @start_region.gen_region_str_post file
    file.print "\n\n"

    ##### �����С�¦�Υ�������� #####
    nest = @end_region.gen_region_str_pre file
    nest_str = "  " * nest

    # �����С�¦�����ͥ������ 
    # ��ĥ�����ӥ�����������
    file.print <<EOT

#{nest_str}  //  Server Side Channel
#{nest_str}  cell #{@ct_name_body} #{@cell_name_body}{
#{nest_str}    #{@call_port_name} = #{@next_cell.get_namespace_path.get_path_str}.#{@next_cell_port_name};
#{nest_str}  };
EOT

    @end_region.gen_region_str_post file

    file2 = AppFile.open( "#{$gen}/tecsgen.cfg" )
    file2.print "\n/* Generated by HRP2SVCPlugin */\n\n"
    file2.print <<EOT
#include "#{@ct_name_body}_factory.h"
EOT
    file2.close
    else

    ##### ���饤�����¦�Υ�������� #####
    nest = @start_region.gen_region_str_pre file
    nest_str = "  " * nest

    # ���饤�����¦�����ͥ������
    # ��ĥ�����ӥ�������ƽФ�
    file.print <<EOT
#{nest_str}  //  Client Side Channel
#{nest_str}  cell #{@ct_name} #{@cell_name}{
#{nest_str}    #{@call_port_name} = #{@next_cell.get_namespace_path.get_path_str}.#{@next_cell_port_name};
#{nest_str}  };

EOT

    @start_region.gen_region_str_post file
    file.print "\n\n"

    end
   end

  #===  �������ؿ�������(C����)����������
  #     �̾�Ǥ���С������ͥ졼���ϼ������ؿ��Υƥ�ץ졼�Ȥ���������
  #     �ץ饰����ξ�硢�ѹ�����ɬ�פΤʤ����륿���ץ����ɤ���������
  #file::           FILE        ������ե�����
  #b_singleton::    bool        true if singleton
  #ct_name::        Symbol
  #global_ct_name:: string
  #sig_name::       string
  #ep_name::        string
  #func_name::      string
  #func_global_name:: string
  #func_type::      class derived from Type
  def gen_ep_func_body( file, b_singleton, ct_name, global_ct_name, sig_name, ep_name, func_name, func_global_name, func_type, params )
      puts "generate ep_func for #{ct_name}"

    if !HRP2KernelObjectPlugin.include_celltype?(@next_cell.get_celltype)
        # ��ĥ�����ӥ�������ƽФ�
        if ! func_type.get_type.kind_of?( VoidType ) then
            file.print( "  #{func_type.get_type_str}  retval;\n" )
        end

        if ! b_singleton then

            file.print <<EOT
  #{ct_name}_CB    *p_cellcb;
  if( VALID_IDX( idx ) ){
    p_cellcb = #{global_ct_name}_GET_CELLCB(idx);
  }else{
     /* ���顼���������ɤ򤳤��˵��� */
  }

EOT
        end

        # p "celltype_name, sig_name, func_name, func_global_name"
        # p "#{ct_name}, #{sig_name}, #{func_name}, #{func_global_name}"

        delim = ""
        if ! func_type.get_type.kind_of?( VoidType ) then
            file.print( "  retval = (#{func_type.get_type_str})" )
        else
            file.print( "  " )
        end

        #file.print( "#{@call_port_name}_#{func_name}(" )
        # svcid = SVCManage.assign_id
        new_func = false
        if SVCManage.include_func_id?( "#{@ct_name_body}_#{func_name}" ) == false
            new_func = true
            SVCManage.set_func_id( "#{@ct_name_body}_#{func_name}" )
        end
        svcid = SVCManage.get_func_id( "#{@ct_name_body}_#{func_name}" )
        #file.print( "cal_svc( #{@ct_name_body}_#{func_name}" )
        file.print( "cal_svc( #{svcid.to_s}" )

        #    if ( ! b_singleton ) then
        #      file.print( " tecs_this" )
        #      delim = ","
        #    end

        i = 0
        params.each{ |param|
            delim = ","
            file.printf( "#{delim} #{param.get_name}" )
            i += 1
        }

        while(i < 5) do
            delim = ","
            file.printf( "#{delim} 0" )
            i += 1
        end

        file.print( " );\n" )

        if ! func_type.get_type.kind_of?( VoidType ) then
            file.print( "  return retval;\n" )
        end

        # ��ĥ�����ӥ�����������
        if new_func
            file2 = AppFile.open( "#{$gen}/#{@ct_name_body}.c" )

#             if @@generated_celltype_header[ @ct_name_body ].nil?
#                 @@generated_celltype_header[ @ct_name_body ] = true
#                 p @@generated_celltype_header[ @ct_name_body ]
#                 file2.print <<EOT
# /*
#  * ���Υե������ tecsgen �ˤ�꼫ư��������ޤ���
#  * ���Υե�������Խ����ƻ��Ѥ��뤳�Ȥϡ��տޤ���Ƥ��ޤ���
#  */
# /* #[<PREAMBLE>]#
#  * #[<...>]# ���� #[</...>]# �ǰϤޤ줿�����Ȥ��Խ����ʤ��Ǥ�������
#  * tecsmerge �ˤ��ޡ����˻��Ѥ���ޤ�
#  *
#  * #[</PREAMBLE>]# */
# 
# /* �ץ�ȥ�����������ѿ�������򤳤��˽񤭤ޤ� #_PAC_# */
# #include "#{@ct_name_body}_tecsgen.h"
# 
# #ifndef E_OK
# #define	E_OK	0		/* success */
# #define	E_ID	(-18)	/* illegal ID */
# #endif
# 
# EOT
#             end

            if func_type.get_type.kind_of?( VoidType ) then
                retval_assign = ""
                retval_return = ""
            else
                retval_assign = "retval = (ER_UINT)"
                retval_return = "retval"
            end

            file2.print <<EOT
ER_UINT
#{@ct_name_body}_#{func_name}(intptr_t par1, intptr_t par2, intptr_t par3, intptr_t par4, intptr_t par5, ID cdmid)
{
    #{@ct_name_body}_CB    *p_cellcb;
#if 0
    if( VALID_IDX( idx ) ){
      p_cellcb = #{@ct_name_body}_GET_CELLCB(idx);
    }else{
       /* ���顼���������ɤ򤳤��˵��� */
    }
#else
    p_cellcb = NULL;
#endif

    ER_UINT retval = 0;

EOT

            num = 1
            params.each{ |param|
                if param.get_declarator.get_ptr_level > 0 then
                    if param.get_direction == :IN then
                        file2.print <<EOT
    if(prb_mem((void *)par#{num.to_s}, sizeof(#{param.get_type.get_type_str}), TSK_SELF, TPM_READ) != E_OK){
        return E_MACV;
    }
EOT

                    elsif param.get_direction == :OUT then
                        file2.print <<EOT
    if(prb_mem((void *)par#{num.to_s}, sizeof(#{param.get_type.get_type_str}), TSK_SELF, TPM_WRITE) != E_OK){
        return E_MACV;
    }
EOT

                    end
                end
                num += 1
            }

            file2.print"    #{retval_assign}#{@call_port_name}_#{func_name}("

            delim = ""
            num = 1
            params.each{ |param|
                file2.print "#{delim}"
                delim = ", "
                file2.print "(#{param.get_type.get_type_str})"
                file2.print "par" + num.to_s
                file2.print param.get_type.get_type_str_post
                num += 1
            }

            file2.print ");\n"

            if !func_type.get_type.kind_of?( VoidType ) then
                file2.print "\n    return #{retval_return};\n"
            end
            file2.print "}\n\n"

            file2.close

            file2 = AppFile.open( "#{$gen}/tecsgen.cfg" )
            file2.print "\n/* Generated by HRP2SVCPlugin */\n\n"
            # TODO: �����å���������Ŭ��
            file2.print <<EOT
KERNEL_DOMAIN{
    DEF_SVC( #{svcid.to_s}, { TA_NULL, #{@ct_name_body}_#{func_name}, 256 } );
}
EOT
            file2.close

            file2 = AppFile.open( "#{$gen}/#{@ct_name_body}_factory.h" )
            file2.print "\n/* Generated by HRP2SVCPlugin */\n\n"
            file2.print <<EOT
extern ER_UINT #{@ct_name_body}_#{func_name}(intptr_t par1, intptr_t par2, intptr_t par3, intptr_t par4, intptr_t par5, ID cdmid);
EOT
            file2.close
        end
    else
        # �����ͥ�ɥᥤ��Υ�������̤ʤ��Ȥϲ��⤻�������̤˸ƤӽФ�
        super
    end
  end
end


