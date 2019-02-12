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

#require "HRP2KernelObjectPlugin"
require_tecsgen_lib "HRP2KernelObjectPlugin.rb"

#== celltype �ץ饰����ζ��̤οƥ��饹
class HRP2HandlerPlugin < HRP2KernelObjectPlugin
    @@ep = [:eStartAlarm, :eStopAlarm, :eManageAlarm, :eReferAlarm ]
    ##
    #
    # file : output file (ex.tecsgen.cfg)
    # cell : 
    # val  : 
    # tab  : 
    def print_cfg_cre(file, cell, val, tab)
        if !val[:id].nil?
            val[:id] = val[:id].gsub( /(^|[^\$])\$id\$/, "\\1#{@celltype.get_name.to_s}_#{cell.get_name.to_s}" )
        end
        # $cbp$������
        index = cell.get_id - @celltype.get_id_base
        cell_CB_name = "#{@celltype.get_global_name}_CB_tab[#{index}]"
        # CRE_XXX������
        domainOption = cell.get_region.get_domain_root.get_domain_type.get_option
        # if (cell.get_region.get_region_type != :DOMAIN) || (cell.get_region.get_param != :KERNEL_DOMAIN)
        if (domainOption == "OutOfDomain") || (domainOption != "trusted")
            # ̵��° or �桼���ɥᥤ���°������
                raise "#{@plugin_arg_str.to_s.downcase} handler #{val[:id]} must belong to kernel domain."
        elsif @plugin_arg_str == "ALARM"
            file.print <<EOT
#{tab}CRE_ALM(#{val[:id]}, { #{val[:attribute]}, &#{cell_CB_name}, tAlarmHandler_start });
EOT
        elsif @plugin_arg_str == "CYCLIC"
            file.print <<EOT
#{tab}CRE_CYC(#{val[:id]}, { #{val[:attribute]}, &#{cell_CB_name}, tCyclicHandler_start, #{val[:cyclicTime]}, #{val[:cyclicPhase]} });
EOT
        elsif @plugin_arg_str == "CONFIG_INT"
            file.print <<EOT
#{tab}CFG_INT( #{val[:interruptNumber]}, { #{val[:attribute]}, #{val[:interruptPriority]} });
EOT
        elsif @plugin_arg_str == "ISR"
            file.print <<EOT
#{tab}ATT_ISR({ #{val[:attribute]}, &#{cell_CB_name}, #{val[:interruptNumber]}, tISR_start, #{val[:priority]} });
EOT
        elsif @plugin_arg_str == "INIT_ROUTINE"
            file.print <<EOT
#{tab}ATT_INI({ #{val[:attribute]}, &#{cell_CB_name}, tInitializeRoutine_start });
EOT
        elsif @plugin_arg_str == "TERM_ROUTINE"
            file.print <<EOT
#{tab}ATT_TER({ #{val[:attribute]}, &#{cell_CB_name}, tTerminateRoutine_start });
EOT
        else
            raise "#{@plugin_arg_str} is unknown option"
        end
    end

    def print_cfg_sac(file, val, acv)
        if @plugin_arg_str == "ALARM"
            file.puts "SAC_ALM(#{val[:id]}, { #{acv[0]}, #{acv[1]}, #{acv[2]}, #{acv[3]} });"
        elsif @plugin_arg_str == "CYCLIC"
            file.puts "SAC_CYC(#{val[:id]}, { #{acv[0]}, #{acv[1]}, #{acv[2]}, #{acv[3]} });"
        elsif @plugin_arg_str == "CONFIG_INT"
            # nothing to do
        elsif @plugin_arg_str == "ISR"
            # nothing to do
        elsif @plugin_arg_str == "INIT_ROUTINE"
            # nothing to do
        elsif @plugin_arg_str == "TERM_ROUTINE"
            # nothing to do
        else
            raise "#{@plugin_arg_str} is unknown option"
        end
    end

=begin
    #tAlarm�μ������ꥹ�� 
    def get_entry_ports_name_list()
        @@ep
    end
=end

end

