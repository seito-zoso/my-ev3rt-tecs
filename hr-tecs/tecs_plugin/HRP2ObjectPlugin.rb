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
require_tecsgen_lib "HRP2KernelObjectPlugin"


class HRP2ObjectPlugin < HRP2KernelObjectPlugin
    # @@ep = [:eSignalSemaphore, :eWaitSemaphore, :eManageSemaphore, :eReferSemaphore ]
    @@api = {
        "SEMAPHORE"=>["SEM", :id, :attribute, :count, :max],
        "EVENTFLAG"=>["FLG", :id, :attribute, :flagPattern],
        "DATAQUEUE"=>["DTQ", :id, :attribute, :count, :dtqmb],
        "PRIORITY_DATAQUEUE"=>["PDQ", :id, :attribute, :count, :maxDataPriority, :pdqmb],
        "FIXED_SIZE_MEMORYPOOL"=>["MPF", :id, :attribute, :blockCount, :blockSize, :mpf, :mpfmb],
        "KERNEL"=>["SYS"],
        "MESSAGE_BUFFER"=>["MBF", :id, :attribute, :maxSize, :bufferSize, :mbfmb],
    }

    #=== HRP2SemaphorePlugin#print_cfg_cre
    # CRE_SEM�ν���
    # file:: FILE:     ������ե�����
    # val :: string:   �����ͥ륪�֥������Ȥ�°���β��Ϸ��
    # tab :: string:   ����ǥ���Ѥ�tab
    def print_cfg_cre(file, cell, val, tab)
        if @@api.has_key?(@plugin_arg_str) == false
            raise "#{@plugin_arg_str} is unknown"
        elsif @plugin_arg_str != "KERNEL"
            arg_list = []
            @@api[@plugin_arg_str].slice(2..-1).each { |attr|
                arg_list << "#{val[attr]}"
            }
            file.print tab
            file.puts "CRE_#{@@api[@plugin_arg_str].at(0)}(#{val[:id]}, { #{arg_list.join(", ")} });"
        end
    end
    #=== HRP2SemaphorePlugin#print_cfg_sac
    # SAC_SEM�ν���
    # file:: FILE:     ������ե�����
    # val :: string:   �����ͥ륪�֥������Ȥ�°���β��Ϸ��
    # acv :: string:   ���������٥���    
    def print_cfg_sac(file, val, acv)
        if @@api.has_key?(@plugin_arg_str) == false
            raise "#{@plugin_arg_str} is unknown"
        elsif @plugin_arg_str != "KERNEL"
            file.puts "SAC_#{@@api[@plugin_arg_str].at(0)}(#{val[:id]}, { #{acv[0]}, #{acv[1]}, #{acv[2]}, #{acv[3] }});"
        else
            file.puts "SAC_#{@@api[@plugin_arg_str].at(0)}({ #{acv[0]}, #{acv[1]}, #{acv[2]}, #{acv[3]} });"
        end
    end

=begin
    #tSemaphore�μ������ꥹ�� 
    def get_entry_ports_name_list()
        @@ep
    end
=end
end


  
