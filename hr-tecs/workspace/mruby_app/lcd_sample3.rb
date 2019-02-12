include EV3RT_TECS

begin
    LCD.draw("lcd sample3", 0, 0)
    80.times{|i|
        LCD.print "#{i}  "
        RTOS.delay(200)
    }
rescue => e
    LCD.error_puts e
end
