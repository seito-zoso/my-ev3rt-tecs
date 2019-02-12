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
#== celltype �ץ饰����ζ��̤οƥ��饹
class HRP2TaskPlugin < HRP2KernelObjectPlugin
    # @@ep = [:eActivateTask, :eControlTask, :eManageTask, :eReferTask ]
    # ATT_MOD�������Ѥߤ��ɤ���
    @@generate_memory_module = false

    ##
    #
    # file : output file (ex.tecsgen.cfg)
    # cell : 
    # val  : 
    # tab  : 
    def print_cfg_cre(file, cell, val, tab)
        val[:id] = val[:id].gsub( /(^|[^\$])\$id\$/, "\\1#{@celltype.get_name.to_s}_#{cell.get_name.to_s}" )
        # $cbp$������
        index = cell.get_id - @celltype.get_id_base
        #cell_CB_name = "#{@celltype.get_global_name}_pCB_tab[#{index}]"
        cell_CB_name = "#{index}"
        # CRE_XXX/DEF_XXX������
        print "assign task plugin\n"
        domainOption = cell.get_region.get_domain_root.get_domain_type.get_option
        # if cell.get_region.get_region_type == :DOMAIN
        if domainOption != "OutOfDomain"
            # �ݸ�ɥᥤ���°������
            if domainOption == "trusted"
                # �����ͥ�ɥᥤ��
                if val[:userStackSize] != "OMIT"
                    raise "system task cannot have user stack."
                end
                file.print <<EOT
#{tab}CRE_TSK(#{val[:id]}, { #{val[:taskAttribute]}, #{cell_CB_name}, tTask_start_task, #{val[:priority]}, #{val[:systemStackSize]}, NULL });
EOT
            else
                # �桼���ɥᥤ��
                if val[:userStackSize] == "OMIT"
                    raise "user task must have user stack."
                end
                if val[:systemStackSize] == "OMIT"
                    file.print <<EOT
#{tab}CRE_TSK(#{val[:id]}, { #{val[:taskAttribute]}, #{cell_CB_name}, tTask_start_task, #{val[:priority]}, #{val[:userStackSize]}, NULL });
EOT
                else
                    file.print <<EOT
#{tab}CRE_TSK(#{val[:id]}, { #{val[:taskAttribute]}, #{cell_CB_name}, tTask_start_task, #{val[:priority]}, #{val[:userStackSize]}, NULL, #{val[:systemStackSize]}, NULL });
EOT
                end
            end
        else
            # ̵��°�ξ��
            raise "task #{val[:id]} must belong to a domain."
        end
   
        # �㳰�ѤΤ�����
        file.print <<EOT
#{tab}DEF_TEX(#{val[:id]}, { #{val[:exceptionAttribute]}, tTask_start_exception });
EOT
    end

    def print_cfg_sac(file, val, acv)
       file.puts "SAC_TSK(#{val[:id]}, { #{acv[0]}, #{acv[1]}, #{acv[2]}, #{acv[3]} });"
    end

=begin
    #tTask�μ������ꥹ�� 
    def get_entry_ports_name_list()
        @@ep
    end
=end
    # 
    #  ATT_MOD������
    #  gen_factory�¹Ի��ˤϡ����٤ƤΥ��륿���ץץ饰����������ѤߤΤϤ��ʤΤǡ�
    #  �����ͥ�API�����ɤΥ����ݸ���ά�Ǥ��롥
    #
    def gen_factory file
        super
        if @@generate_memory_module == false
            check_celltype_list = []

            Cell.get_cell_list2.each { |cell|
                # ���٤ƤΥ�����������ƥ��륿���פ�����å�
                ct = cell.get_celltype
                if ct.class == Celltype && check_celltype_list.include?( ct ) == false
                    # �����å��Ѥߥ��륿���פ���Ͽ
                    check_celltype_list << ct

                    # ̤�����å��Υ��륿���פ��ä����
                    # puts "check for ATT_MOD : #{ct.classget_global_name}"
                    puts "check for ATT_MOD : #{ct.get_global_name}"
                        
                    # �����ͥ�API�Υ����ɡ��ǡ����ϥ����ݸ�ʤ�
                    next if HRP2KernelObjectPlugin.include_celltype?( ct )

                    # ɬ�פΤʤ����륿���פΥ����ɡ��ǡ����ϥ����ݸ�ʤ�
                    next if ! ct.need_generate?

                    # HRP2�Υɥᥤ��꡼���������
                    regions = ct.get_domain_roots
                    regions_hrp2 = regions[ :HRP2 ]
                    print "HRP2 domain in #{ct.get_name}: "
                    regions_hrp2.each { |reg|
                        print reg.get_name
                    }
                    puts ""

                    # ��������֥�å��ȥ�����ȥ�Υ����ݸ�
                    # gen_celltype_names_domain �����ν���
                    if regions_hrp2.include?( Region.get_root ) == false && regions_hrp2.length > 1
                        # �ɥᥤ��ʣ���ǡ�OutOfDomain�˥��뤬¸�ߤ��ʤ����륿���פξ��
                        # ��ͭ�Υ�������֥�å��ȥ�����ȥ󥳡��ɤ���Ͽ����
                        file = AppFile.open( "#{$gen}/tecsgen.cfg" )
                        file.print "ATT_MOD(\"#{ct.get_global_name}_tecsgen.o\");\n"
                        file.close
                    end

                    regions_hrp2.each { |reg|
                        if reg.is_root? 
                            nsp = ""
                        else
                            nsp = "_#{reg.get_namespace_path.get_global_name}"
                        end
                        file = AppFile.open( "#{$gen}/tecsgen#{nsp}.cfg" )
                        file.print "ATT_MOD(\"#{ct.get_global_name}#{nsp}_tecsgen.o\");\n"
                        file.close
                    }

                    # ���륿���ץ����ɤ��ʤ����ϥ����å�
                    next if ct.is_all_entry_inline? && ! ct.is_active?

                    # ���륿���ץ����ɤΥ����ݸ�
                    # gen_celltype_names_domain2 �����ν���
                    if regions_hrp2.include?( Region.get_root ) == true || regions_hrp2.length > 1
                        # OutOfDomain�˥��뤬¸�ߤ��륻�륿���פξ��
                        # �ޤ��ϡ�ʣ���Υɥᥤ��˥��뤬¸�ߤ��륻�륿���פξ��
                        # ���륿���ץ����ɤ�ͭ����褦����Ͽ����
                        file = AppFile.open( "#{$gen}/tecsgen.cfg" )
                    else
                        # OutOfDomain�Ǥʤ�ñ��Υɥᥤ��˥��뤬¸�ߤ��륻�륿���פξ��
                        # ���륿���ץ����ɤ���ͭ����褦����Ͽ����
                        file = AppFile.open( "#{$gen}/tecsgen_#{regions_hrp2[0].get_namespace_path.get_global_name}.cfg" )
                    end

                    file.print "ATT_MOD(\"#{ct.get_global_name}.o\");\n"
                    file.close
                else
                    # ���⤷�ʤ�
                end
            }

            @@generate_memory_module = true
        else
            # ���⤷�ʤ�
        end
    end
    
end

