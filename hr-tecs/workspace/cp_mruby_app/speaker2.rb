include EV3RT_TECS

begin
    LCD.font=:medium

    LCD.draw("speaker sample2", 0,1) 
    
    Speaker.volume= 1
    while true
        Speaker.tone(:c4, 30) if Button[:left].pressed?
        Speaker.tone(:c5, 30) if Button[:right].pressed?
        Speaker.tone(:c6, 30) if Button[:up].pressed?
        Speaker.tone(:f4, 30) if Button[:down].pressed?
        Speaker.tone(:f5, 30) if Button[:enter].pressed?
        RTOS.delay(30)
    end
rescue => e
    LCD.error_puts e
end
