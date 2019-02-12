# coding: utf-8
include EV3RT_TECS

begin
    LCD.font=:medium
    LCD.puts "sharedmemory sample2"
    LCD.puts "VM[2]"

    RTOS.delay(1000)

    BT_CMD = 1     # 共有メモリの index = 1 を bt_cmd として使用する
    sm = SharedMemory.new()

    val = sm.getVal( BT_CMD )	# val = sm[BT_CMD]

    LCD.puts "VM[2]: val = #{val}"

    RTOS.delay(1000)

    val = sm.getVal( BT_CMD )	# val = sm[BT_CMD]

    LCD.puts "VM[2]: val = #{val}"

rescue => e
    LCD.error_puts e
end
