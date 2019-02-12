
#== cell を count 個繰り返すセルプラグイン
# 不完全点：
#    指定子に対応していない
#       cell の指定子 (allocator, id)
#       結合の指定子 (through)
class RepeatCellPlugin < CellPlugin

  @@plugin_list = []
  RepeatCellPluginArgProc = {
    "count" => Proc.new { |obj,rhs| obj.set_count rhs }
  }

  def initialize( cell, option )
    super
    @@plugin_list << self
    print "RepeatCellPlugin: #{@cell.get_name}\n"
    # cell.show_tree 0
    # @cell.get_join_list.get_items.each{ |j|
    #  print "Join: #{j.get_name} = #{j.get_rhs.to_s}\n"
    # }
    @count = 0
    @plugin_arg_check_proc_tab = RepeatCellPluginArgProc
    parse_plugin_arg
  end

  def gen_cdl_file( file )
    if $verbose then
      print "#{self.class}: repeat #{@cell.get_name} #(num} times\n"
    end

    nest = @cell.get_region.gen_region_str_pre file
    indent_str = "  " * nest
    @cell.get_name.to_s =~ /.*[^0-9]([0-9]+)\z/
    if $1 then
      tail_zero = $1
      bname = @cell.get_name.to_s.gsub( /[0-9]+\z/, "" )
    else
      cdl_error( "#{self.class}: #{@cell.get_name}'s name ends without '0-9'")
      return
    end
    base_count = tail_zero.to_i

    count = 1
    num = @count
    file.print "/*  #{num} times repeat of '#{@cell.get_name}' */\n"
    while count < num

      # セル名のカウント
      count_str = (count + base_count).to_s
      if tail_zero.length > count_str.length then
        leading_zero = "0" * ( tail_zero.length - count_str.length )
      else
        leading_zero = ""
      end
      cname = bname + leading_zero + count_str

      #   "cell tCelltype Cell {" 
      file.print "#{indent_str}cell #{@cell.get_celltype.get_name} #{cname}{\n"

      # Join の CDL 文字列生成
      @cell.get_join_list.get_items.each{ |j|

        # Join の右辺の解析
        res = j.get_rhs.analyze_cell_join_expression
        if res then
          nsp, subscript, port_name = res[0], res[1], res[2]
        else
          nsp = j.get_rhs.analyze_single_identifier
          if nsp then
            subscript, port_name = nil, nil
          else
            file.print "#{indent_str}  #{j.get_name} = #{j.get_rhs.to_s};\n"
            next
          end
        end

        # 右辺のセル名 (末尾の数字をカウントアップ)
        nsp.get_name.to_s =~ /(.*[^0-9])([0-9]+)\z/
        if $2 then
          rhs_tail_num = $2
          rhs_name_count = count + rhs_tail_num.to_i
          if rhs_tail_num.length > rhs_name_count.to_s.length then
            leading_zero = "0" * ( rhs_tail_num.length - rhs_name_count.to_s.length )
          else
            leading_zero = ""
          end
          rhs_cname = $1 + leading_zero + rhs_name_count.to_s
          nsp = nsp.change_name_clone rhs_cname
        end

        # Join 文字列の出力
        if port_name then
          # 右辺は セルの結合
          if subscript then
            file.print "#{indent_str}  #{j.get_name} = #{nsp.get_path_str}.#{port_name}[#{(count+subscript).to_s}];\n"
          else
            file.print "#{indent_str}  #{j.get_name} = #{nsp.get_path_str}.#{port_name};\n"
          end
        else
          # 右辺は単一の識別子
          file.print "#{indent_str}  #{j.get_name} = #{nsp.get_path_str};\n"
        end
      }

      file.print "#{indent_str}};\n\n"
      count += 1
    end

    @cell.get_region.gen_region_str_post file
  end

  #=== count オプションの解析
  def set_count rhs
    if rhs =~ /\A\d+\z/
      @count = rhs.to_i
    else
      nsp = NamespacePath.new( rhs.to_sym, true )
      expr = Expression.create_single_identifier( nsp, nil )
      res = expr.eval_const( nil )
      if res == nil then
        cdl_error( "count value ($1): not single identifier or integer number", rhs.to_s )
        @count = 0
      else
        @count = res
      end
    end
  end

end
