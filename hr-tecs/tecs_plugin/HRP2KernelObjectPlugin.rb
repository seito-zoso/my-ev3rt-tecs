#
#  TECS Generator
#      Generator for TOPPERS Embedded Component System
#  
#   Copyright (C) 2008-2012 by TOPPERS Project
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

# Region���饹�˥᥽�åɤ��ɲ�
=begin
class Region
    def get_params
        return @region_type_param
    end

    def get_param
        return @region_type_param[0]
    end

    def is_root
        return self == @@root_namespace
    end
end
=end

# Cell���饹�˥��󥹥����ѿ��ȥ᥽�åɤ��ɲ�
=begin
class Cell
    def set_referenced_region( region )
        if @referenced_regions.nil?
            @referenced_regions = Array.new
        end
        if !@referenced_regions.include?(region)
            @referenced_regions << region
        end
    end

    def get_referenced_regions
        return @referenced_regions
    end

    # set_referenced_cell�ˤ����ۤ����褤
    # def set_referenced_region( region, port_name )
    def set_referenced_cell( cell, port_name )
        if @referenced_cells.nil?
            @referenced_cells = Hash.new
        end
        if !@referenced_cells.include?(port_name)
            @referenced_cells[port_name] = Array.new
        end
        if !@referenced_cells[port_name].include?(cell)
            @referenced_cells[port_name] << cell
        end

        region = cell.get_region
        puts "***** set_referenced_regions *****"
        puts "region=#{region.get_name}, port=#{port_name}(#{port_name.class})"
        if @referenced_regions.nil?
            @referenced_regions = Hash.new
        end
        if !@referenced_regions.include?(port_name)
            @referenced_regions[port_name] = Array.new
        end
        if !@referenced_regions[port_name].include?(region)
            @referenced_regions[port_name] << region
        end
        puts "#{@referenced_regions[port_name]}"
    end

    def get_referenced_cells( port_name )
        if !@referenced_cells.nil? && @referenced_cells.include?(port_name)
            return @referenced_cells[port_name]
        else
            return nil
        end
    end

    def get_referenced_regions( port_name )
        if !@referenced_regions.nil? && @referenced_regions.include?(port_name)
            return @referenced_regions[port_name]
        else
            return nil
        end
    end

    def self.get_cell_list
        return @@cell_list
    end

    def self.get_cell_list2
        return @@cell_list2
    end
end
=end

#== celltype �ץ饰����ζ��̤οƥ��饹
class HRP2KernelObjectPlugin < CelltypePlugin
    # @@obj_hash = {}

    #@celltype:: Celltype
    #@option:: String     :���ץ����ʸ����
    def initialize( celltype, option )
        super
        # ���줾��Υ����ͥ륪�֥������Ȥ�����оݥ��륿���פ��ɲ�
        HRP2KernelObjectPlugin.set_celltype(celltype)
    end
  
    #=== HRP2KernelObjectPlugin#print_cfg_cre
    # �Ƽ參���ͥ륪�֥������Ȥ�CRE_*�ν���
    # file:: FILE:     ������ե�����
    # val :: string:   �����ͥ륪�֥������Ȥ�°���β��Ϸ��
    # tab :: string:   ����ǥ���Ѥ�tab
    def print_cfg_cre(file, cell, val, tab)
        raise "called virtual method print_cfg_cre in #{@celltype.get_name} plugin"
    end
  
    #=== HRP2KernelObjectPlugin#print_cfg_sac
    # �Ƽ參���ͥ륪�֥������Ȥ�SAC_*�ν���
    # file:: FILE:     ������ե�����
    # val :: string:   �����ͥ륪�֥������Ȥ�°���β��Ϸ��
    # acv :: string:   ���������٥���
    def print_cfg_sac(file, val, acv)
        raise "called virtual method print_cfg_sac in #{@celltype.get_name} plugin"
    end
  
    #=== HRP2KernelObjectPlugin#get_entry_ports_name_list
    # �����ͥ륪�֥������ȤγƼ異�������μ��̤μ�����̾�����
    def get_entry_ports_name_list()
        raise "called virtual method get_entry_ports_name_list in #{@celltype.get_name} plugin"
    end

    def string_cfg_cre(cell, val)
        raise "called virtual method string_cfg_cre in #{@celltype.get_name} plugin"
    end

    def gen_factory file
        puts "===== begin #{@celltype.get_name.to_s} plugin ====="

        # �оݤȤʤ뤹�٤ƤΥ���ˤĤ��ơ��������˷�礵��Ƥ���
        # ����ν�°�ɥᥤ������
        if !HRP2KernelObjectPlugin.isChecked()
            HRP2KernelObjectPlugin.check_referenced_cells()
        else
            puts "***** already checked"
        end

        # �ɵ����뤿��� AppFile ��Ȥ���ʸ���������Ѵ�����ʤ���
        file2 = AppFile.open( "#{$gen}/tecsgen.cfg" )
        file2.print "\n/* Generated by #{self.class.name} */\n\n"

        @celltype.get_cell_list.each { |cell|
            if cell.is_generate?
                puts "===== begin check my domain #{cell.get_name} ====="
                # attr���ͤ�ϥå���������
                val = {}
                @celltype.get_attribute_list.each{ |a|
                    p a.get_name
                    if a.get_type.kind_of?( ArrayType )
                        val[a.get_name] = []
                        if j = cell.get_join_list.get_item(a.get_name)
                            # �����������˽����������
                            j.get_rhs.each { |elem|
                                val[a.get_name] << elem.to_s
                            }
                        elsif i = a.get_initializer
                            # ���륿���פν�����ͤ�Ȥ����
                            i.each { |elem|
                                val[a.get_name] << elem.to_s
                            }
                        else
                            raise "attribute is not initialized"
                        end
                    else
                        if j = cell.get_join_list.get_item(a.get_name)
                            # �����������˽����������
                            val[a.get_name] = j.get_rhs.to_s
                        elsif i = a.get_initializer
                            # ���륿���פν�����ͤ�Ȥ����
                            val[a.get_name] = i.to_s
                        else
                            raise "attribute is not initialized"
                        end
                    end
                }
                # generate.rb�򻲹ͤ�
                # $id$���ִ�
                if val[:id].nil? != true
                    puts val[:id]
                    val[:id] = val[:id].gsub( /(^|[^\$])\$id\$/, "\\1#{@celltype.get_name.to_s}_#{cell.get_name.to_s}" )
                end
                # $cbp$������
                index = cell.get_id - @celltype.get_id_base
                cell_CB_name = "#{@celltype.get_global_name}_CB_tab[#{index}]"
                cell_domain_root = cell.get_region.get_domain_root
                cell_domain_type = cell.get_region.get_domain_root.get_domain_type

                # CRE_XXX/DEF_XXX������
                if cell_domain_type.get_option.to_s != "OutOfDomain"
                    # �ݸ�ɥᥤ���°������
                    if !HRP2KernelObjectPlugin.include_region(cell_domain_root.get_name.to_s)
                        # �����ݸ�ɥᥤ���.cfg����������Ƥ��ʤ����
                        HRP2KernelObjectPlugin.set_region_list(cell_domain_root.get_name.to_s)
                        puts "~~~~~ #{cell_domain_root.get_name.to_s} is registered!"

                        # if cell.get_region.get_param == :KERNEL_DOMAIN
                        if cell_domain_type.get_option.to_s == "trusted"
                            # file2.print "#{cell.get_region.get_name.to_s}{\n"
                            file2.print "KERNEL_DOMAIN{\n"
                        else
                            file2.print "DOMAIN(#{cell_domain_root.get_name.to_s}){\n"
                        end
                        file2.puts "\tINCLUDE(\"#{$gen}/tecsgen_#{cell_domain_root.get_name.to_s}.cfg\");" 
                        file2.puts "}\n"
                    else
                        print "~~~~~ #{cell.get_region.get_name.to_s} is included in"
                        p @@region_list
                    end
                    file3 = AppFile.open( "#{$gen}/tecsgen_#{cell_domain_root.get_name.to_s}.cfg" )
                    print_cfg_cre(file3, cell, val,"")
                    file3.close
                else
                    # ̵��°�ξ��
                    puts "~~~~~ #{cell_domain_root.get_name.to_s} is OutOfDomain"
                    print_cfg_cre(file2, cell, val, "")
                end

                puts "===== end check my domain #{cell.get_name} ====="
                # SAC_XXX������
                if !val[:accessPattern].nil?
                    puts "===== begin check regions #{cell.get_name} ====="
                    p val[:accessPattern]
                    p val[:accessPattern].class

                    #ep = [ :eTaskActivate, :eTaskControl, :eTaskManage, :eTaskRefer ]
                    #�ƥ����ͥ륪�֥������Ȥμ�����̾�����
                    # ep = get_entry_ports_name_list()
                    i = 0
                    acv = []
                    # �����������ĥ٥���������
                    val[:accessPattern].each { |acptnx|
                        # �����������ĥѥ����������
                        if acptnx != "OMIT"
                            acv << acptnx
                            p acv[i]
                        elsif cell_domain_type.get_option.to_s == "trusted"
                            acv << "TACP_KERNEL"
                            p acv[i]
                        elsif cell_domain_type.get_option.to_s != "OutOfDomain"
                            acv << "TACP(#{cell_domain_root.get_name.to_s})"
                        else
                            acv << "TACP_SHARED"
                        end

                        i += 1
                    }

                    print "acv = "
                    p acv

                    #�Ƽ�SAC������
                    domainOption = cell_domain_type.get_option
                    # if cell.get_region.get_region_type == :DOMAIN
                    if domainOption != "OutOfDomain"
                        # �ݸ�ɥᥤ���°������
                        file3 = AppFile.open( "#{$gen}/tecsgen_#{cell.get_region.get_name.to_s}.cfg" )
                        print_cfg_sac(file3, val, acv)
                        file3.close
                    else
                        # ̵��°�ξ��
                        print_cfg_sac(file2, val, acv)
                    end

                    puts "===== end check regions #{cell.get_name} ====="
                end
            end
        }

        puts "===== end #{@celltype.get_name.to_s} plugin ====="
        file2.close
    end

    # �����ͥ륪�֥������ȥ��륿���פδ���
    # HRP2KernelObjectPlugin���饹���Ф��ƥ᥽�åɸƽФ���Ԥ����Ȥ�����
    @@checked = false
    @@celltype_list = []
    @@region_list = []

    def self.isChecked()
        return @@checked
    end

    def self.check_referenced_cells()
        puts "===== begin check registered celltype ====="
        self.get_celltype_list.each { |ct|
            p ct.get_name.to_s
        }
        puts "===== end check registered celltype ====="

=begin
        Cell.get_cell_list2.each { |cell|
            cell.get_celltype.get_port_list.each{ |p|
                next if p.get_port_type != :CALL
                j = cell.get_join_list.get_item(p.get_name)
                printf "===== check call port : "
                p p.get_name.to_s
                next if j.nil? # ̤���ξ��
                if @@celltype_list.include?(j.get_celltype)
                    # j.get_cell.set_referenced_region(cell.get_region)
                    # j.get_cell.set_referenced_region(cell.get_region, j.get_port_name)
                    j.get_cell.set_referenced_cell(cell, j.get_port_name)
                    printf "===== check joined rhs cell : "
                    p j.get_cell.get_name.to_s
                    printf "===== check joined rhs port_name : "
                    p j.get_port_name
                end
            }
        }
=end
        @@checked = true
    end

    def self.set_celltype( celltype )
        @@celltype_list << celltype
    end

    def self.get_celltype_list
        return @@celltype_list
    end

    def self.set_region_list( region )
        @@region_list << region
    end

    def self.include_region( region )
        return @@region_list.include?(region)
    end

    def self.include_celltype?( celltype )
        return @@celltype_list.include?(celltype)
    end

end

