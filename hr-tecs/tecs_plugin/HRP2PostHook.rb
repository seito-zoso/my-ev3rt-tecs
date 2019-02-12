#
#  TECS Generator
#      Generator for TOPPERS Embedded Component System
#  
#   Copyright (C) 2012 by TOPPERS Project
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

#require "HRP2KernelObjectPlugin"
require_tecsgen_lib "HRP2KernelObjectPlugin"

class HRP2PostHook
    #@celltype:: Celltype
    def initialize( celltype )
        puts "new post hook #{celltype.get_name}"
        @celltype = celltype
    end

    def generate
        # �����ͥ륪�֥������ȤΥ��륿���פϥ����ݸ�ʤ�
#=begin
        # TODO: �ƥ��ȤΤ����̵����
        if HRP2KernelObjectPlugin.include_celltype?( @celltype )
            puts "nothing is generated for kernel object component"
            return
        end
#=end

        rlist = @celltype.get_region_list
        if @celltype.is_singleton?
            # singleton�ξ��
            puts "<singleton>"

            if rlist.length == 0
                file = AppFile.open( "#{$gen}/tecsgen.cfg" )
            else
                file = AppFile.open( "#{$gen}/tecsgen_#{rlist[0].get_param.to_s}.cfg" )
            end
            # ��������֥�å��ȥ�����ȥ�Υ����ݸ�
            file.print "ATT_MOD(\"#{@celltype.get_global_name}_tecsgen.o\");\n"
            if !@celltype.is_all_entry_inline?
                # ���륿���ץ����ɤΥ����ݸ�
                file.print "ATT_MOD(\"#{@celltype.get_global_name}.o\");\n"
            end

            file.close

        else
            # singleton�Ǥʤ����
            puts "<non-singleton>"

            # ������ȥ�ȥ��륿���ץ����ɤ��ݸ�
            if (rlist.length == 1) && 
                (@celltype.get_n_cell_gen == @celltype.get_n_cell_gen_r( rlist[0] ))
                # ��°�����ݸ�ɥᥤ��1�Ĥξ��
                puts "<private celltype>"
                file = AppFile.open( "#{$gen}/tecsgen_#{rlist[0].get_param.to_s}.cfg" )
            else
                # ̵��° or ��°�����ݸ�ɥᥤ��ʣ���ξ��
                puts "<shared celltype>"
                file = AppFile.open( "#{$gen}/tecsgen.cfg" )
            end

            # ������ȥ�Υ����ݸ�
            file.print "ATT_MOD(\"#{@celltype.get_global_name}_tecsgen.o\");\n"
            if !@celltype.is_all_entry_inline?
                # ���륿���ץ����ɤΥ����ݸ�
                file.print "ATT_MOD(\"#{@celltype.get_global_name}.o\");\n"
            end
            file.close

            # ��������֥�å����ݸ�
            rlist.each { |reg|
                file = AppFile.open( "#{$gen}/tecsgen_#{reg.get_param.to_s}.cfg" )
                file.print "ATT_MOD(\"#{@celltype.get_global_name}_#{reg.get_name.to_s}_tecsgen.o\");\n"
                file.close
            }

        end
    end
end

