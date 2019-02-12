# ドメインプラグインの実例 MyDomainPlugin
#
# 各メソッドの役割りは、DomainPlugin.rb を参照のこと
class MyDomainPlugin < DomainPlugin

  def initialize( region, domain_type_name, option )
    print "MyDomainPlugin: initialize: region=#{region.get_name}, domainTypeName=#{domain_type_name}, option=#{option}\n"
  end

  def add_through_plugin( join, current_region, next_region, through_type )
    # join.get_owner:Cell  左辺のセル
    # join.get_definition:Port 呼び口
    # join.get_subscript:Integer or nil 呼び口配列の添数 (Join::@subscript の説明参照)
    # join.get_cell:Cell 右辺のセル
    # join.get_port_name:Symbol 受け口
    # get_rhs_subscript:Integer or nil 受け口配列の添数 (Join::@rhs_subscript の説明参照)
    # return []
    print "MyDomainPlugin: add_through_plugin: #{current_region.get_name}=>#{next_region.get_name}, #{join.get_owner.get_name}.#{join.get_definition.get_name}=>#{join.get_cell.get_name}.#{join.get_port_name}, #{through_type}\n"
    return [ :TracePlugin, "" ]
  end

  def joinable?(current_region, next_region, through_type )
    print "MyDomainPlugin: joinable? from #{current_region.get_name} to #{next_region.get_name} (#{through_type})\n"
    return true
  end

  def self.gen_post_code file
  end
end
