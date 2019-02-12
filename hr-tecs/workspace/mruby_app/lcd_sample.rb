include EV3RT_TECS

begin
    LCD.font=:medium
    LCD.puts "lcd sample"
    while true
        LCD.puts "left  button " if Button[:left ].pressed?
        LCD.puts "right button " if Button[:right].pressed?
        LCD.puts "enter button " if Button[:enter].pressed?
        break if Button[:back ].pressed?
        
        RTOS.delay(100)
    end
    
rescue => e
    LCD.error_puts e
end
