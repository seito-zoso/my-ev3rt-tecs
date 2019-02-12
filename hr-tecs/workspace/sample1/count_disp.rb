# coding: utf-8
unless $initialized
  include EV3RT_TECS
end # unless $initialized

begin
  unless $initialized
    LCD.font=:medium
	  sm = SharedMemory.new()
    $initialized = true
  else
	  val = sm.getVal( WAKEUP_TASK_TIME )
    LCD.draw("WakeupTask="+val.to_s+"usec   ", 0, 7)
  end    
rescue => e
    LCD.error_puts e
end
