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

require_tecsgen_lib "GenHRP2Marshaler.rb"

# require_tecsgen_lib "GenParamCopy.rb"

#= Transparent RPC �ץ饰����
# Transparent RPC �����ͥ����������
# �ץ饰��������ϰʲ��� RPCPluginArgProc �򻲾�

# mikan through plugin: namespace ����θ����Ƥ��ʤ�
# ��������Ѥ����硢�ʲ��Τ褦�� toppers_jsp.cdl sChannel.cdl ����ꤹ��ɬ�פ�����
# tecsgen toppers_jsp.cdl sChannel.cdl your_description.cdl

# �ʲ���������»����
#  �ƤӸ����Ƥ���Υ���ǥ�����char, short, int_t, long_t, intptr_t �Υ�������Ʊ��
#  ͭ��桢̵���ǥ�������Ʊ��

#
# RPC���Ѥ����ɥᥤ����̿���
# through�ץ饰����
# HRP2�ɥᥤ��ץ饰����ˤ�ä����������
#
class HRP2RPCPlugin < ThroughPlugin

  include GenTransparentMarshaler
  # include GenParamCopy

  # RPCPlugin ���ѤΥ��ץ����
  TransparentRPCPluginArgProc = RPCPluginArgProc.dup  # ʣ�����äƸ����ѹ����ʤ��褦�ˤ���
  TransparentRPCPluginArgProc[ "noClientSemaphore"  ] = Proc.new { |obj,rhs| obj.set_noClientSemaphore rhs }
  TransparentRPCPluginArgProc[ "semaphoreCelltype"  ] = Proc.new { |obj,rhs| obj.set_semaphoreCelltype rhs }

  #=== RPCPlugin �� initialize
  #  ������ ThroughPlugin (plugin.rb) �򻲾�
  def initialize( cell_name, plugin_arg, next_cell, next_cell_port_name, signature, celltype, caller_cell )
    super
    @b_noClientSemaphore = false
    @semaphoreCelltype = "tSemaphore"
    initialize_transparent_marshaler cell_name

    # ���ץ����GenTransparentMarshaler ����
    @plugin_arg_check_proc_tab = TransparentRPCPluginArgProc
    parse_plugin_arg

    @rpc_channel_celltype_name = "tRPCPlugin_#{@TDRCelltype}_#{@channelCelltype}_#{@signature.get_name}"
    @rpc_channel_celltype_file_name = "#{$gen}/#{@rpc_channel_celltype_name}.cdl"

    if @signature.need_PPAllocator? then
      if @PPAllocatorSize == nil then
        cdl_error( "PPAllocatorSize must be speicified for oneway [in] array" )
        # @PPAllocatorSize = 0   # ���� 0 �Ȥ��Ƥ��� (cdl �ι�ʸ���顼���򤱤뤿��)
      end
    end

#    @signature.each_param{ |func_decl, param_decl|
#      if func_decl.get_type.is_oneway? then
#        if ( param_decl.get_size || param_decl.get_count ) && param_decl.get_string then
#          cdl_error( "array of string not supported for oneway function in Transparent RPC" )  # mikan ʸ���������
#        elsif param_decl.get_string == -1 then
#          cdl_error( "length unspecified string is not permited for oneway function in Transparent RPC" )  # mikan Ĺ��̤����ʸ����
#        end
#      end
#    }
  end

  #=== plugin ����������� (celltype �����) ����
  def gen_plugin_decl_code( file )

    ct_name = "#{@ct_name}_#{@channelCelltype}"

    # ���Υ��륿���ס�Ʊ�������˥���ˤϴ�����������Ƥ��뤫��
    if @@generated_celltype[ ct_name ] == nil then
      @@generated_celltype[ ct_name ] = [ self ]
    else
      @@generated_celltype[ ct_name ] << self
      return
    end

    gen_marshaler_celltype

    if @PPAllocatorSize then
      alloc_cell = "  cell tPPAllocator PPAllocator {\n    heapSize = #{@PPAllocatorSize};\n  };\n"
      alloc_call_port_join = "    cPPAllocator = PPAllocator.ePPAllocator;\n"
    else
      alloc_cell = ""
      alloc_call_port_join = ""
    end

    if @b_noClientSemaphore == false then
      semaphore1 = <<EOT
  // Semaphore for Multi-task use ("specify noClientSemaphore" option to delete this)
  cell #{@semaphoreCelltype} Semaphore {
    count = 1;
    attribute = C_EXP( "TA_NULL" );
  };
EOT
      semaphore2 = "    cLockChannel = Semaphore.eSemaphore;\n"
    else
      semaphore1 = ""
      semaphore2 = ""
    end

    f = CFile.open( @rpc_channel_celltype_file_name, "w" )
    # Ʊ�����Ƥ����ٽ񤯲�ǽ������ (AppFile ���Բ�)

    f.print <<EOT
import( "#{@marshaler_celltype_file_name}" );

composite #{@rpc_channel_celltype_name}Client {
  /* Interface */
  entry #{@signature.get_name} eThroughEntry;
  //call sTDR       cTDR;
  call sEventflag cEventflag;
  call sSemaphore cSemaphore;
  call sMessageBuffer cMessageBuffer;

  /* Implementation */
#{semaphore1}
  cell #{@marshaler_celltype_name} #{@signature.get_name}_marshaler{
    //cTDR         => composite.cTDR;
    cEventflag   => composite.cEventflag;
    cSemaphore   => composite.cSemaphore;
    cMessageBuffer => composite.cMessageBuffer;
#{semaphore2}  };
  composite.eThroughEntry => #{@signature.get_name}_marshaler.eClientEntry;
};

[active]
composite #{@rpc_channel_celltype_name}Server {
  /* Interface */
  attr {
    PRI taskPriority;
  };
  call #{@signature.get_name} #{@call_port_name};
  //call sTDR       cTDR;
  call sEventflag cEventflag;
  call sSemaphore cSemaphore;
  call sMessageBuffer cMessageBuffer;

  /* Implementation */
#{alloc_cell}  cell #{@unmarshaler_celltype_name} #{@signature.get_name}_unmarshaler{
    //cTDR        => composite.cTDR;
    cEventflag  => composite.cEventflag;
    cSemaphore  => composite.cSemaphore;
    cMessageBuffer => composite.cMessageBuffer;
    cServerCall => composite.#{@call_port_name};
#{alloc_call_port_join}  };
  cell tRPCDedicatedTaskMain RPCTaskMain{
    cMain = #{@signature.get_name}_unmarshaler.eUnmarshalAndCallFunction;
  };
  cell tTask Task {
    cBody     = RPCTaskMain.eMain;
    priority  = taskPriority;
    taskAttribute = C_EXP( "TA_ACT" );  /* mikan : marshaler starts at the beginning */
    //stackSize     = 4096;
    userStackSize     = 4096;
  };
};
EOT
    # mikan stackSize option & �ǿ� tecs_package �б�

    f.close
  end

  #===  through cell �����ɤ�����
  #
  #
  def gen_through_cell_code( file )

    gen_plugin_decl_code( file )

    # �����õ��
    # path =["::",@next_cell.get_name]
    # cell = Namespace.find( path )
    cell = Namespace.find( @next_cell.get_namespace_path )

    file.print <<EOT
import( "#{@rpc_channel_celltype_file_name}" );
EOT

    #nest = @end_region.gen_region_str_pre file
    indent_str = ""

    file.print <<EOT
#{indent_str}// one way channel cell
#{indent_str}cell #{@channelCelltype} #{@channelCellName} {
#{indent_str}};

#{indent_str}// RPC channel cell
EOT

    nest = @start_region.gen_region_str_pre file
    indent_str = "  " * nest

    # #473 ����褵�줿��硢composite ��졼�����������ѹ����٤�
    # ���������λ��꤬���뤫��
    if cell.get_allocator_list.length > 0 then

      dbgPrint "make allocator"
      file.print "#{indent_str}[allocator("

      delim = ""
      cell.get_allocator_list.each do |type, eport, subsc, func, buf, alloc|

        file.print delim
        delim = ",\n#{indent_str}           "        # �ǽ��ԤˤϽФ��ʤ�

        if subsc then        # ����ź��
          subsc_str = '[#{subsc}]'
        else
          subsc_str = ""
        end

        eport = "eThroughEntry" #RPC�μ�����̾���ѹ�
        file.print  "#{eport}#{subsc_str}.#{func}.#{buf} = #{alloc}"
      end

      file.puts ")]"
    end

    file.print <<EOT
#{indent_str}cell #{@rpc_channel_celltype_name}Client #{@cell_name} {
#{indent_str}  //cTDR         = #{@channelCellName}.eTDR;
#{indent_str}  cEventflag   = #{@channelCellName}.eEventflag;
#{indent_str}  cSemaphore   = #{@channelCellName}.eSemaphore;
#{indent_str}  cMessageBuffer   = #{@channelCellName}.eMessageBuffer;
#{indent_str}};
EOT

    @start_region.gen_region_str_post file

    nest = @end_region.gen_region_str_pre file
    indent_str = "  " * nest

    file.print <<EOT
#{indent_str}cell #{@rpc_channel_celltype_name}Server #{@cell_name}Body {
#{indent_str}    #{@call_port_name} = #{@next_cell.get_namespace_path.get_path_str}.#{@next_cell_port_name};
//#{indent_str}    #{@call_port_name} = #{@next_cell.get_name}.#{@next_cell_port_name};
#{indent_str}  //cTDR         = #{@channelCellName}.eTDR;
#{indent_str}  cEventflag   = #{@channelCellName}.eEventflag;
#{indent_str}  cSemaphore   = #{@channelCellName}.eSemaphore;
#{indent_str}  cMessageBuffer  = #{@channelCellName}.eMessageBuffer;
#{indent_str}  taskPriority = #{@task_priority};
#{indent_str}};
EOT

    @end_region.gen_region_str_post file
  end


  #=== �ץ饰������� noClientSemaphore �Υ����å�
  def set_noClientSemaphore rhs
    rhs = rhs.to_sym
    if rhs == :true then
      @b_noClientSemaphore = true
    elsif rhs == :false then
      @b_noClientSemaphore = false
    else
      cdl_error( "RPCPlugin: specify true or false for noClientSemaphore" )
    end
  end

  #=== �ץ饰������� semaphoreCelltype �Υ����å�
  def set_semaphoreCelltype rhs
    @semaphoreCelltype = rhs.to_sym
    nsp = NamespacePath.analyze( @semaphoreCelltype.to_s )
    obj = Namespace.find( nsp )
    if ! obj.instance_of?( Celltype ) && ! obj.instance_of?( CompositeCelltype ) then
      cdl_error( "RPCPlugin: semaphoreCelltype '#{rhs}' not celltype or not defined" )
    end
  end

  #=== NamespacePath ������
  # �������륻��� namespace path ����������
  def get_cell_namespace_path
#    nsp = @region.get_namespace.get_namespace_path
    nsp = @start_region.get_namespace_path
    return nsp.append( @cell_name )
  end

end


