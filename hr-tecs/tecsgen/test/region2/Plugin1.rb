class Plugin1 < ThroughPlugin

  @@generated_celltype = {}

  def initialize( cell_name, plugin_arg, next_cell_name, next_cell_port_name, signature, celltype )
    super
    @cell_name = cell_name
    @next_cell_name = next_cell_name
    @next_cell_port_name = next_cell_port_name
    @signature = signature
    @entry_port_name = "throughEntry"
    # print( "Plugin1.new( '#{cell_name}', '#{plugin_arg}', '#{next_cell_name}', '#{next_cell_port_name}', #{celltype.get_name} )\n" )
  end

  def get_cell_name
    @cell_name
  end

  def get_through_entry_port_name
    @entry_port_name
  end

#  def gen_plugin_decl_code( file )
#
#    ct_name = "Plugin1_#{@signature.get_name}"
#
#    if @@generated_celltype[ ct_name ] == nil then
#      @@generated_celltype[ ct_name ] = [ self ]
#    else
#      @@generated_celltype[ ct_name ] << self
#    end
#
#    file.print <<EOT
#celltype tPlugin1 {
#  entry #{@signature.get_name} #{@entry_port_name};
#  call #{@signature.get_name} cCall;
#};
#EOT
#
#  end

  def gen_through_cell_code( file )

    gen_plugin_decl_code( file )

    file.print <<EOT
cell tPlugin1_#{@signature.get_name} #{@cell_name} {
  cCall = #{@next_cell_name}.#{@next_cell_port_name};
};
EOT

  end
end
