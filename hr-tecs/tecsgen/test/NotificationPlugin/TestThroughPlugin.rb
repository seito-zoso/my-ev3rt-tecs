# ../through/Plugin1.rb より作成。
class TestThroughPlugin < ThroughPlugin

  @@generated_celltype = {}

  def initialize( cell_name, plugin_arg, next_cell, next_cell_port_name, signature, celltype, caller_cell )
    super
    @cell_name = cell_name
    @next_cell = next_cell
    @next_cell_port_name = next_cell_port_name
    @signature = signature
    @entry_port_name = :"throughEntry"
  end

  def get_cell_name
    @cell_name
  end

  def get_through_entry_port_name
    @entry_port_name
  end

  def gen_through_cell_code( file )

    gen_plugin_decl_code( file )

    file.print <<EOT
cell tTestThroughPlugin_#{@signature.get_name} #{@cell_name} {
  cCall = #{@next_cell.get_name}.#{@next_cell_port_name};
};
EOT

  end

end
