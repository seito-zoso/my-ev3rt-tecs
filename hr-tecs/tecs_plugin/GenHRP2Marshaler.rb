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

#�ץ饰���󥪥ץ�������ѿ�
#@task_priority:: Integer
#@channelCelltype:: String
#@channelCellName:: String
#@PPAllocatorSize:: Integer
module GenTransparentMarshaler

  # �ץ饰�������̾�� Proc
  RPCPluginArgProc = {
    "taskPriority"    => Proc.new { |obj,rhs| obj.set_taskPriority rhs },
    "channelCelltype" => Proc.new { |obj,rhs| obj.set_channelCelltype rhs },
    "TDRCelltype"     => Proc.new { |obj,rhs| obj.set_TDRCelltype rhs },
    "channelCell"     => Proc.new { |obj,rhs| obj.set_channelCellName rhs },
    "PPAllocatorSize" => Proc.new { |obj,rhs| obj.set_PPAllocatorSize rhs },
  }

  #=== �ץ饰������� taskPriority �Υ����å�
  def set_taskPriority( rhs )
    @task_priority = rhs
  end

  #=== �ץ饰������� channelCelltype �Υ����å�
  def set_channelCelltype( rhs )
    @channelCelltype = rhs.to_sym
    # path = [ "::", @channelCelltype ]
    # obj = Namespace.find( path )
    nsp = NamespacePath.analyze( @channelCelltype.to_s )
    obj = Namespace.find( nsp )
    if ! obj.instance_of?( Celltype ) && ! obj.instance_of?( CompositeCelltype ) then
      cdl_error( "RPCPlugin: channeclCelltype '#{rhs}' not celltype or not found" )
    end
  end

  #=== �ץ饰������� TDRCelltype �Υ����å�
  def set_TDRCelltype( rhs )
    @TDRCelltype = rhs.to_sym
    # path = [ "::", @TDRCelltype ]
    # obj = Namespace.find( path )
    nsp = NamespacePath.analyze( @TDRCelltype.to_s )
    obj = Namespace.find( nsp )
    if ! obj.instance_of?( Celltype ) && ! obj.instance_of?( CompositeCelltype ) then
      cdl_error( "RPCPlugin: TDRCelltype '#{rhs}' not celltype or not found" )
    end
  end

  #=== �ץ饰������� channelCellName �Υ����å�
  def set_channelCellName( rhs )
    @channelCellName = rhs
    if @channelCellName =~ /\A[a-zA-Z_]\w*/ then
      # OK
    else
      cdl_error( "RPCPlugin: channeclCellName '#{rhs}' unsuitable for identifier" )
    end
  end

  #=== �ץ饰������� PPAllocatorSize �Υ����å�
  def set_PPAllocatorSize( rhs )
    @PPAllocatorSize = rhs
  end

  #=== marshaler �Υ��륿����̾�����ꤹ��
  def initialize_transparent_marshaler cell_name
    @task_priority = 8
    @channelCelltype = "tDataqueueOWChannel"
    @TDRCelltype     = "tTDR"
    @channelCellName = "#{cell_name}_Channel"
    @PPAllocatorSize = nil

    @marshaler_celltype_name = "tMarshaler_#{@signature.get_name}"
    @unmarshaler_celltype_name = "tUnmarshaler_#{@signature.get_name}"
    @marshaler_celltype_file_name = "#{$gen}/#{@marshaler_celltype_name}.cdl"
  end

  def gen_marshaler_celltype 

    if @PPAllocatorSize then
      alloc_call_port = "  call sPPAllocator cPPAllocator;\n"
    else
      alloc_call_port = ""
    end

    f = CFile.open( @marshaler_celltype_file_name, "w" )
    # Ʊ�����Ƥ����ٽ񤯲�ǽ������ (AppFile ���Բ�)

    # modified by ishikawa
    f.print <<EOT

celltype #{@marshaler_celltype_name} {
  entry #{@signature.get_name} eClientEntry;
  call sEventflag  cEventflag;
  call sSemaphore  cSemaphore;
  call sMessageBuffer cMessageBuffer;
  //[optional]
  //  call sSemaphore cLockChannel;  // this port is eliminated by optimize
};
celltype #{@unmarshaler_celltype_name} {
  call #{@signature.get_name} cServerCall;
  call sEventflag  cEventflag;
  call sSemaphore  cSemaphore;
  call sMessageBuffer cMessageBuffer;
  entry sTaskBody  eUnmarshalAndCallFunction;
#{alloc_call_port}
  FACTORY{
    write("$ct$_factory.h", "#include <t_syslog.h>");
  };
};
EOT
    f.close
  end

  #===  �������ؿ������Υ����ɤ�������Ƭ�������������ӽ��ϡ�
  #ct_name:: Symbol    (through �ץ饰������������줿) ���륿����̾ ��Symbol �Ȥ��������Ƥ���ʤ餷����
  def gen_ep_func_body( file, b_singleton, ct_name, global_ct_name, sig_name, ep_name, func_name, func_global_name, func_type, params )

    # unmarshaler ���饹��?
    if ct_name == @unmarshaler_celltype_name.to_sym then
      gen_ep_func_body_unmarshal( file, b_singleton, ct_name, global_ct_name, sig_name, ep_name, func_name, func_global_name, func_type, params )
    else
      gen_ep_func_body_marshal( file, b_singleton, ct_name, global_ct_name, sig_name, ep_name, func_name, func_global_name, func_type, params )
    end
  end

  #===  marshal �����ɤ�����
  def gen_ep_func_body_marshal( file, b_singleton, ct_name, global_ct_name, sig_name, ep_name, func_name, func_global_name, func_type, params )

    b_void = false
    b_ret_er = false

    # �ؿ�������ͤθ��η�������(typedef ����Ƥ�����)
    type = func_type.get_type.get_original_type

    # ����͵����Ѥ��ѿ�����ϡ�void ���δؿ��ǤϽ��Ϥ��ʤ���
    if ! type.kind_of?( VoidType ) then
      if func_type.get_type.kind_of?( DefinedType ) && ( func_type.get_type.get_type_str == "ER" || func_type.get_type.get_type_str == "ER_INT" ) then
        file.print( "    #{func_type.get_type.get_type_str}  retval_ = E_OK;\n" )
        b_ret_er = true
      else
        file.print( "    #{func_type.get_type.get_type_str}  retval_;\n" )
      end
    else
      b_void = true
    end

    file.print( "    ER      ercd_;\n" )
    file.print( "    FLGPTN  flgptn;\n" )

    # �Ƥ���� signature ����Ф�
    signature = @signature

    # �ؿ� ID �������͡�
    func_id = signature.get_id_from_func_name( func_name )
    file.print( "    int16_t  func_id_ = #{func_id};    /* id of #{func_name}: #{func_id} */\n" )

    file.print( "    uint8_t  msg[256];\n" )

    # ���󥰥�ȥ�Ǥʤ�����
    if ! b_singleton then

      # singleton �Ǥʤ���� p_cellcb ���������ɤ����
      file.print <<EOT
    #{ct_name}_CB *p_cellcb;

    if( VALID_IDX( idx ) ){
        p_cellcb = GET_CELLCB(idx);
EOT

      # ���顼���֤�����
      if b_ret_er then
        file.print <<EOT
    }else{
         return ERCD( E_RPC, E_ID );
    }
EOT
      else
        file.print <<EOT
    }else{
        /* ���顼���������ɤ򤳤��˵��� */
    }
EOT
      end
    end

    # channel lock ������
    file.print <<EOT
    ///* Channel Lock */
    //if( is_cLockChannel_joined() )
    //  cLockChannel_wait();

EOT

=begin
    # SOP ������
    file.print "    /* SOP������ */\n"
    file.print "    if( ( ercd_ = cTDR_sendSOP( true ) ) != E_OK )\n"
    file.print "      goto error_reset;\n"
=end

    # func_id ������
    file.print "    /* �ؿ� id ������ */\n"
=begin
    file.print "    if( ( ercd_ = cTDR_putInt16( func_id_ ) ) != E_OK )\n"
    file.print "        goto error_reset;\n"
=end
    file.print "    *((int16_t *)(&msg[0])) = func_id_;\n"   

    # p "celltype_name, sig_name, func_name, func_global_name"
    # p "#{ct_name}, #{sig_name}, #{func_name}, #{func_global_name}"

    b_get = false    # marshal �ʤ� put
    b_marshal = true  # marshal

    # in �����������Ϥ����
    @index = 2
    file.print "    /* ���ϰ������� */\n"
    print_params( params, file, 1, b_marshal, b_get, true, func_type.is_oneway? )
    print_params( params, file, 1, b_marshal, b_get, false, func_type.is_oneway? )
=begin
    if ! b_void && ! func_type.is_oneway? then
      ret_ptr_type = PtrType.new( func_type.get_type )
      print_param_nc( "retval_", ret_ptr_type, file, 1, :RETURN, "&", nil, b_get )
    end
=end

    file.print "    /* EOP�����Сʥѥ��åȤ��ݤ������� */\n"
    if ! func_type.is_oneway? then
      b_continue = "true"
    else
      b_continue = "false"
    end
=begin
    file.print "    if( (ercd_=cTDR_sendEOP(#{b_continue})) != E_OK )\n"
    file.print "        goto error_reset;\n\n"
=end
    file.print "    if( (ercd_=cMessageBuffer_send(msg, #{@index})) != E_OK )\n"
    file.print "        goto error_reset;\n\n"

    file.print "        cSemaphore_signal();\n\n"

    if ! func_type.is_oneway? then
      file.print <<EOT
    if( (ercd_=cEventflag_wait( 0x01, TWF_ANDW, &flgptn )) != E_OK ){
      ercd_ = ERCD(E_RPC,ercd_);
      goto error_reset;
    }
    if( (ercd_=cEventflag_clear( 0x00 ) ) != E_OK ){
      ercd_ = ERCD(E_RPC,ercd_);
      goto error_reset;
    }
EOT
    end # ! func_type.is_oneway?

    file.print <<EOT
    ///* Channel Lock */
    //if( is_cLockChannel_joined() )
    //  cLockChannel_signal();
EOT

    if( b_void == false )then
      # �ƤӸ�������ͤ�꥿����
      file.print( "    cMessageBuffer_receive(&retval_);\n" )
      file.print( "    return retval_;\n" )
    else
      file.print( "    return;\n" )
    end

    file.print <<EOT

error_reset:
#if 0
    if( ercd_ != ERCD( E_RPC, E_RESET ) )
        (void)cTDR_reset();
#endif
EOT

    # channel lock ������
    file.print <<EOT
    ///* Channel Lock */
    //if( is_cLockChannel_joined() )
    //  cLockChannel_signal();

EOT

    if( b_ret_er != false )then
      # �ƤӸ�������ͤ�꥿����
      file.print( "    return ercd_;\n" )
    else
      file.print( "    return;\n" )
    end

  end

  #===  unmarshal �����ɤ�����
  def gen_ep_func_body_unmarshal( file, b_singleton, ct_name, global_ct_name, sig_name, ep_name, func_name, func_global_name, func_type, params )

#    b_ret_er = true
    b_ret_er = false

    # func_id �����륳���ɤ�����
    file.print <<EOT

    int16_t   func_id_;
    ER        ercd_;

    #{ct_name}_CB *p_cellcb;

    if( VALID_IDX( idx ) ){
        p_cellcb = GET_CELLCB(idx);
EOT

    if b_ret_er then
        file.print <<EOT
    }else{
        return ERCD( E_RPC, E_ID );
    }
EOT
    else
        file.print <<EOT
    }else{
        /* ���顼���������ɤ򤳤��˵��� */
    }
EOT
    end

    file.print <<EOT

    cSemaphore_wait();

#if 0
    /* SOP�Υ����å� */
    if( (ercd_=cTDR_receiveSOP( false )) != E_OK )
        goto error_reset;
    /* func_id �μ��� */
    if( (ercd_=cTDR_getInt16( &func_id_ )) != E_OK )
        goto error_reset;
#endif

    if( (ercd_ = cMessageBuffer_receive(msg) < 0 ) )
        goto error_reset;
    func_id_ = ((int16_t *)msg)[0];

#ifdef RPC_DEBUG
    syslog(LOG_INFO, "unmarshaler task: func_id: %d", func_id_ );
#endif
    switch( func_id_ ){
EOT

    # �Ƥ���� signature ����Ф�
    # port = @celltype.find( @next_cell_port_name )
    # signature = port.get_signature
    signature = @signature

    # through �� signature �˴ޤޤ�� ���٤Ƥδؿ��ˤĤ���
    signature.get_function_head_array.each { |f|
      f_name = f.get_name
      f_type = f.get_declarator.get_type
      id = signature.get_id_from_func_name( f_name )

      # �ؿ����֤��ͤ���Ĥ�?
      if f_type.get_type.kind_of?( VoidType ) then
        b_void = true
      else
        b_void = false
      end

      # �ѥ��åȤν���������å���̤�������Υǡ������ĤäƤ��ʤ��������å���
      file.print "    case #{id}:       /*** #{f_name} ***/ \n"
      file.print "        if( tTransparentUnmarshaler_#{@signature.get_name}_#{f_name}() != E_OK )\n"
      file.print "            goto error_reset;\n"
      file.print "        break;\n"

    } # 

    if @PPAllocatorSize then
      ppallocator_dealloc_str = "    /* PPAllocator �Τ��٤Ƥ���� */\n    cPPAllocator_dealloc_all();"
    else
      ppallocator_dealloc_str = ""
    end


    file.print <<EOT
    default:
#if 0 // deleted by ishikawa: tSysLog��̤����
        syslog(LOG_INFO, "unmarshaler task: ERROR: unknown func_id: %d", func_id_ );
#endif /* 0 */
        break;
    };
#{ppallocator_dealloc_str}
    return;

error_reset:
#if 0
    if( ercd_ != ERCD( E_RPC, E_RESET ) )
        (void)cTDR_reset();
#else
    return ercd_;
#endif
#{ppallocator_dealloc_str}
EOT

  end

  # IN b_marshal, b_get
  #  b_marshal = true  && b_get == false   :  �ޡ����������ϰ�������
  #  b_marshal = true  && b_get == true    :  �ޡ������ǽ��ϰ�������
  #  b_marshal = false && b_get == true    :  ����ޡ����������ϰ�������
  #  b_marshal = false && b_get == get     :  ����ޡ������ǽ��ϰ�������
  def print_params( params, file, nest, b_marshal, b_get, b_referenced, b_oneway = false )
    params.each{ |param|
# p "#{param.get_name}:  b_marshal: #{b_marshal} b_get: #{b_get}"
      if ! ( b_referenced == param.is_referenced? ) then
        next
      end

      dir = param.get_direction
      type = param.get_type
      if b_oneway && dir == :IN && type.get_original_type.kind_of?( PtrType ) || type.get_original_type.kind_of?( ArrayType ) then
        # oneway, in, PtrType �ξ�祳�ԡ�
        alloc_cp = "cPPAllocator_alloc"
        alloc_cp_extra = nil
        print_param( param.get_name, type, file, nest, dir, nil, nil, b_get, alloc_cp, alloc_cp_extra )
      else
        if( b_get == false && b_marshal == true || b_get == true && b_marshal == false  )then
          case dir
#          when :IN, :INOUT, :SEND
          when :IN, :INOUT, :OUT, :SEND, :RECEIVE
            print_param_nc( param.get_name, type, file, nest, b_marshal, nil, nil, b_get )
          end
        else
#         case dir
#         when :OUT, :INOUT, :RECEIVE
#         when :RECEIVE
#           print_param_nc( param.get_name, type, file, nest, b_marshal, nil, nil, b_get )
#         end
        end
      end
    }
  end

  #=== ���ԡ����ʤ������Ϥ������ɤν���
  def print_param_nc( name, type, file, nest, b_marshal, outer, outer2, b_get )
    indent = "    " * ( nest + 1 )

    case type
    when DefinedType
      print_param_nc( name, type.get_type, file, nest, b_marshal, outer, outer2, b_get )
    when BoolType, IntType, FloatType, PtrType, ArrayType
      case type
      when BoolType
        type_str = "Int8"
        cast_str = "int8_t"
      when IntType
        bit_size = type.get_bit_size
        case type.get_sign
        when :UNSIGNED
          signC = "U"
          sign  = "u"
        when :SIGNED
          if bit_size == -1 || bit_size == -11 then
            # signed char �ξ�硢signed ����ꤹ��
            signC = "S"
            sign  = "s"
          else
            signC = ""
            sign  = ""
          end
        else
          signC = ""
          sign  = ""
        end

        # p "pn:: #{name} #{bit_size} #{type.get_type_str}"
        case bit_size
        when  -1, -11  # -1: char_t, -11: char
          type_str = "#{signC}Char"
          cast_str = "#{sign}char_t"
        when -2
          type_str = "#{signC}Short"
          cast_str = "#{sign}short_t"
        when -3
          type_str = "#{signC}Int"
          cast_str = "#{sign}int_t"
        when -4
          type_str = "#{signC}Long"
          cast_str = "#{sign}long_t"
        when -5
          type_str = "Intptr"
          cast_str = "intptr_t"
        when 8, 16, 32, 64, 128
          type_str = "#{signC}Int#{bit_size}"
          cast_str = "#{sign}int#{bit_size}_t"
        else
          raise "unknown bit_size '#{bit_size}' for int type "
        end

      when FloatType
        bit_size = type.get_bit_size
        if bit_size == 32 then
          type_str = "Float32"
          cast_str = "float32_t"
        else
          type_str = "Double64"
          cast_str = "double64_t"
        end

      when PtrType
        type_str = "Intptr"
        cast_str = "intptr_t"
      when ArrayType
        type_str = "Intptr"
        cast_str = "intptr_t"
      end

      if type.get_type_str == cast_str then
        cast_str = ""
      else
        cast_str = "(" + cast_str + ")"
      end

      if( b_get )then
        cast_str.gsub!( /\)$/, "*)" )
        file.print "    " * nest
=begin
        file.print "if( ( ercd_ = cTDR_get#{type_str}( #{cast_str}&(#{outer}#{name}#{outer2}) ) ) != E_OK )\n"
        file.print "    " * nest
        file.print "    goto error_reset;\n"
=end
        file.print "#{name} = *((#{type.get_type_str} *)(&msg[#{@index}]));\n"
        if bit_size.nil?
            raise "HRP2 RPC supports only specified bit_size"
        else
            case bit_size
            when 8, 16, 32, 64, 128
            else
                raise "HRP2 RPC supports only specified bit_size"
            end
        end
        @index += bit_size / 8
      else
        file.print "    " * nest
=begin
        file.print "if( ( ercd_ = cTDR_put#{type_str}( #{cast_str}#{outer}#{name}#{outer2} ) ) != E_OK )\n"
        file.print "    " * nest
        file.print "    goto error_reset;\n"
=end
        file.print "*((#{type.get_type_str} *)(&msg[#{@index}])) = #{name};\n"
        if bit_size.nil?
            raise "HRP2 RPC supports only specified bit_size"
        else
            case bit_size
            when 8, 16, 32, 64, 128
            else
                raise "HRP2 RPC supports only specified bit_size"
            end
        end
        @index += bit_size / 8
      end

    when StructType
      members_decl =type.get_members_decl
      members_decl.get_items.each { |m|
        if m.is_referenced? then
          print_param_nc( m.get_name, m.get_type, file, nest, b_marshal, "#{outer}#{name}#{outer2}.", nil, b_get )
        end
      }
      members_decl.get_items.each { |m|
        if ! m.is_referenced? then
          print_param_nc( m.get_name, m.get_type, file, nest, b_marshal, "#{outer}#{name}#{outer2}.", nil, b_get )
        end
      }

    when VoidType
    when EnumType  # mikan EnumType
    when FuncType  # mikan FuncType
    end
  end


  #=== PREAMBLE ���Υ���������
  # ����ޡ�����饻�륿���פξ�硢����ޡ������ؿ��Υץ�ȥ��������������
  def gen_preamble file, b_singleton, ct_name, global_name
    if ct_name != @unmarshaler_celltype_name.to_sym then
      return
    end

    file.print "/* ����ޡ������ؿ��Υץ�ȥ�������� */\n"
    # signature �˴ޤޤ�� ���٤Ƥδؿ��ˤĤ���
    @signature.get_function_head_array.each { |f|
      f_name = f.get_name
      f_type = f.get_declarator.get_type
      id = @signature.get_id_from_func_name( f_name )
      file.print "static ER  tTransparentUnmarshaler_#{@signature.get_name}_#{f_name}();\t/* func_id: #{id} */\n"
    }
    file.print "\n"
    file.print "static uint8_t msg[256];\n"
    file.print "\n"
  end

  #=== POSTAMBLE ���Υ���������
  # ����ޡ�����饻�륿���פξ�硢����ޡ������ؿ�������
  def gen_postamble file, b_singleton, ct_name, global_name
    if ct_name != @unmarshaler_celltype_name.to_sym then
      return
    end

    file.print "\n/*** ����ޡ������ؿ� ***/\n\n"
    @signature.get_function_head_array.each { |f|
      f_name = f.get_name
      f_type = f.get_declarator.get_type
      id = @signature.get_id_from_func_name( f_name )

      # �ؿ����֤��ͤ���Ĥ�?
      if f_type.get_type.kind_of?( VoidType ) then
        b_void = true
      else
        b_void = false
      end

      file.print <<EOT
/*
 * name:    #{f_name}
 * func_id: #{id} 
 */
EOT
      file.print "static ER\n"
      file.print "tTransparentUnmarshaler_#{@signature.get_name}_#{f_name}()\n"
      file.print "{\n"
      file.print "	ER  ercd_;\n"

      # �����������ѿ������
      param_list = f.get_declarator.get_type.get_paramlist.get_items
           # FuncHead->  Decl->    FuncType->ParamList
      param_list.each{ |par|
        name = par.get_name
        type = par.get_type
        if type.kind_of? ArrayType then
          type = type.get_type
          aster = "(*"
          aster2 = ")"
        else
          aster = ""
          aster2 = ""
        end

        type_str = type.get_type_str.gsub( /\bconst\b */, "" ) # "const" �򳰤�

        file.printf( "    %-12s %s%s%s%s;\n", type_str, aster, name, aster2, type.get_type_str_post )
      }

      # ����ͤ��������ѿ������
      if ! b_void then
        if f.is_oneway? then
          retval_ptr = ""   # oneway �ξ�硢������뤬�ΤƤ���
        else
          # =begin ishikawa modified
          # retval_ptr = "*"
          retval_ptr = ""
          # =end ishikawa modified
        end
        file.printf( "    %-12s #{retval_ptr}retval_%s;\n", f_type.get_type.get_type_str, f_type.get_type.get_type_str_post )
      end

      # in �����������Ϥ�����
      file.print "\n        /* ���ϰ������� */\n"
      b_get = true    # unmarshal �Ǥ� get
      b_marshal  = false
      @index = 2
      print_params( param_list, file, 1, b_marshal, b_get, true, f.is_oneway? )
      print_params( param_list, file, 1, b_marshal, b_get, false, f.is_oneway? )
=begin
      if ! b_void && ! f.is_oneway? then
        ret_ptr_type = PtrType.new( f_type.get_type )
        print_param_nc( "retval_", ret_ptr_type, file, 2, :RETURN, nil, nil, b_get )
      end
=end
      # �ѥ��åȤμ�����λ
      # mikan �����ϡ��оݴؿ���ƽФ���˼»ܤ��������ƽФ��ѥ��åȤλ��ѽ��������������Ū�Ȥ���
      file.print "        /* �ѥ��åȽ���������å� */\n"
      if ! f.is_oneway? then
        b_continue = "true"
      else
        b_continue = "false"
      end
=begin
      file.print "    if( (ercd_=cTDR_receiveEOP(#{b_continue})) != E_OK )\n"
      file.print "        goto error_reset;\n\n"
=end
      # �оݴؿ���ƽФ�
      file.print "    /* �оݴؿ��θƽФ� */\n"
      if b_void then
        file.print( "    cServerCall_#{f_name}(" )
      else
        file.print( "    #{retval_ptr}retval_ = cServerCall_#{f_name}(" )
      end

      delim = " "
      param_list.each{ |par|
        file.print delim
        delim = ", "
        file.print "#{par.get_name}"
      }
      file.print( " );\n" )

      # ����͡����ϰ����μ��襳���ɤ�����

      if ! b_void && ! f.is_oneway? then
        file.print "    if( (ercd_ = cMessageBuffer_send(&retval_, sizeof(#{f_type.get_type.get_type_str})) != E_OK ) )\n"
        file.print "        goto error_reset;\n"

      end
      # oneway �ξ����ϡ�����ͤ�̵����������Ԥ��ʤ�����Ʊ���ʸƽФ���
      if ! f.is_oneway? then
        file.print <<EOT
    /* �ؿ������ν�λ������ */
    if( ( ercd_ = cEventflag_set( 0x01 ) ) != E_OK ){
      goto error_reset;
    }
EOT
      end  # ! f.is_oneway?
      file.print <<EOT
    return E_OK;
error_reset:
    return ercd_;
}

EOT

    }

  end

end
