# coding: utf-8

#== restrict テスト用ドメインプラグイン
class MyDomainPlugin < DomainPlugin
  def add_through_plugin( join, current_region, next_region, through_type )
    return [:MyTracePlugin, ""]
  end

  # require の結合
  def joinable?(current_region, next_region, through_type )
    if next_region.get_name == "::" then
      return true
    end
  end

  def self.gen_post_code f
  end
end
