# coding: utf-8
include EV3RT_TECS

begin
    LCD.font=:medium
    LCD.draw("battery sample", 0, 0) 
	  sm = SharedMemory.new()
    
    loop{
      start = RTOS.usec

      # LCD 表示は、msec 単位で時間を消費することに留意のこと
      LCD.draw("battery mA::#{Battery.mA}", 0, 4)
      LCD.draw("battery mV::#{Battery.mV}", 0, 5)

      val = RTOS.usec - start
      sm.putVal( WAKEUP_TASK_TIME, val )		# sm[BT_CMD] = 1

      RTOS.sleep
    }
rescue => e
    LCD.error_puts e
end
