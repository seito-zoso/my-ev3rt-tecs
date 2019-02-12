# -*- coding: utf-8 -*-
#
#  TECS Generator
#      Generator for TOPPERS Embedded Component System
#  
#   Copyright (C) 2008-2011 by TOPPERS Project
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
#   $Id: celltypePlugin.rb 1540 2011-08-12 14:04:37Z okuma-top $
#++

#== celltype プラグインの共通の親クラス
class MrubyBridgeCelltypePlugin < CelltypePlugin

  # プラグイン引数名 => Proc
  MrubyBridgePluginArgProc = { 
      "ignoreUnsigned" => Proc.new { |obj,rhs| obj.set_ignoreUnsigned rhs },
      "exclude_cell" => Proc.new { |obj,rhs| obj.set_exclude_cell rhs },
      "include_port" => Proc.new { |obj,rhs| obj.set_include_port rhs },
      "exclude_port" => Proc.new { |obj,rhs| obj.set_exclude_port rhs },
      "include_port_func" => Proc.new { |obj,rhs| obj.set_include_port_func rhs },
      "exclude_port_func" => Proc.new { |obj,rhs| obj.set_exclude_port_func rhs },
  }

  require_tecsgen_lib( "MrubyBridgeCellPlugin.rb" )
  @@plugin_list = []
  @@count = 1

  #celltype::     Celltype        セルタイプ（インスタンス）
  def initialize( celltype, option )
    super
    @celltype = celltype
    @cell_list = []
    # @plugin_arg_str = option.gsub( /\A"(.*)/, '\1' )    # 前後の "" を取り除く
    # @plugin_arg_str.sub!( /(.*)"\z/, '\1' )
    @plugin_arg_str = CDLString.remove_dquote option
    @plugin_arg_list = {}
    dbgPrint "#{self.class.name}: initialzie: #{celltype.get_name}\n"
    @@plugin_list << self
    MrubyBridgeCellPlugin.set_gen_post_code_by_dependent
#    fn2 = "#{$gen}/tmp_MrubyBridgeCelltypePlugin_#{@celltype.get_name}_0.cdl"
#    f2 = File.open( fn2, "w" )
#    # 複数のプラグインの post_code が一つのファイルに含まれるため、以下のような見出しをつけること
#    dbgPrint "MrubyBridgeCelltypePlugin: gen_post_code\n"
#    f2.print <<EOT
#/* MrubyBridgeCelltypePlugin: celltype=#{celltype.get_name}
# *
# *    cell's generate before celltype's generate
# */
#
#EOT
#    @celltype.get_cell_list.each { |cell|
#      @cell_list << cell
#      # mikan option, region
#      p "MrubyBridgeCelltypePlugin: Cell=#{cell.get_name}"
#      f2.print <<EOT
#generate( MrubyBridgeCellPlugin, #{cell.get_namespace_path}, "" );
#EOT
#    }
#    f2.close
#    p "MrubyBridgeCelltypePlugin: pre:#{celltype.get_name}"
#    p "MrubyBridgeCelltypePlugin: import:#{fn2}"
#    Import.new "#{fn2}"
  end

  #=== 新しいセル
  #cell::        Cell            セル
  #
  # celltype プラグインを指定されたセルタイプのセルが生成された
  # セルタイププラグインに対する新しいセルの報告
  def new_cell( cell )
    dbgPrint "MrubyBridgeCelltypePlugin: new_cell: #{cell.get_name}\n"
    @cell_list << cell
    # mikan option, region
#    fn2 = "#{$gen}/tmp_MrubyBridgeCelltypePlugin_#{@celltype.get_name}_#{@@count}.cdl"
#    f2 = File.open( fn2, "w" )
#    f2.print <<EOT
#/* MrubyBridgeCelltypePlugin: celltype=#{celltype.get_name} */
# *
# *    cell's generate after celltype's generate
# */
#
#    f2.print <<EOT
#generate( MrubyBridgeCellPlugin, #{cell.get_namespace_path}, "" );
#EOT
#    f2.close
#    p Import "MrubyBridgeCelltypePlugin: pre:#{celltype.get_name}"
#    Import.new "#{fn2}"
#    @@count += 1
  end

### 意味解析段階で呼び出されるメソッド ###
  #===  CDL ファイルの生成
  #      typedef, signature, celltype, cell のコードを生成
  #      重複して生成してはならない
  #      すでに生成されている場合は出力しないこと。
  #      もしくは同名の import により、重複を避けること。
  #file::        FILE       生成するファイル
  def gen_cdl_file file
    dbgPrint "MrubyBridgeCelltypePlugin: gen_cdl_file: #{@celltype.get_name}\n"
    file.print <<EOT
/* MrubyBridgeCelltypePlugin: celltype=#{@celltype.get_name}
 *
 *    cell's generate before celltype's generate
 */

EOT
    @celltype.get_cell_list.each { |cell|
      @cell_list << cell
      # mikan option, region
      dbgPrint "MrubyBridgeCelltypePlugin: cell=#{cell.get_name}\n"
      file.print <<EOT
generate( MrubyBridgeCellPlugin, #{cell.get_namespace_path}, "" );
EOT
    }

  end

  #=== tCelltype_factory.h に挿入するコードを生成する
  # file 以外の他のファイルにファクトリコードを生成してもよい
  # セルタイププラグインが指定されたセルタイプのみ呼び出される
  def gen_factory file
  end

  def get_celltype
    @celltype
  end

  #=== 後ろの CDL コードを生成
  #プラグインの後ろの CDL コードを生成
  #file:: File: 
  def self.gen_post_code( file )
    dbgPrint "#{self.name}: gen_post_code_body\n"

#    # MrubyBridgeCelltypePlugin の生成する generate 文は、
#    fn2 = "#{$gen}/tmp_MrubyBridgeCelltypePlugin_post.cdl"
#    f2 = File.open( fn2, "w" )
#    # 複数のプラグインの post_code が一つのファイルに含まれるため、以下のような見出しをつけること
#    dbgPrint "MrubyBridgeCelltypePlugin: gen_post_code\n"
#    f2.print "/* '#{self.name}' post code */\n"
#    @@plugin_list.each{ |plugin|
#      plugin.get_celltype.get_cell_list.each{ |cell|
#        # mikan option, region
#        f2.print <<EOT
#generate( MrubyBridgeCellPlugin, #{cell.get_namespace_path}, "" );
#EOT
#      }
#    }
#    f2.close
#    p Import
#    Import.new "#{fn2}"

    MrubyBridgeCellPlugin.gen_post_code_body file
  end
end

