include EV3RT_TECS

begin
    LCD.font=:medium
    
    LCD.draw("battery sample", 0, 0) 
    
    while true
        LCD.draw("battery mA::#{Battery.mA}", 0, 2)
        LCD.draw("battery mV::#{Battery.mV}", 0, 3)
    end
    while true
        break if Button[:back ].pressed?
    end
rescue => e
    LCD.error_puts e
end
