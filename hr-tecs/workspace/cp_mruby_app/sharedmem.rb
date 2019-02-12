# coding: utf-8
include EV3RT_TECS

begin
    LCD.font=:medium
    LCD.puts "VM[1]"

    BT_CMD = 1     # 共有メモリの index = 1 を bt_cmd として使用する
    sm = SharedMemory.new()

    sm.putVal( BT_CMD, 1 )		# sm[BT_CMD] = 1
    val = sm.getVal( BT_CMD )	# val = sm[BT_CMD]

    LCD.puts "VM[1]: val = #{val}"

    RTOS.delay(1000)

    sm.putVal( BT_CMD, 10 )		# sm[BT_CMD] = 1
    val = sm.getVal( BT_CMD )	# val = sm[BT_CMD]

    LCD.puts "VM[1]: val = #{val}"

rescue => e
    LCD.error_puts e
end
