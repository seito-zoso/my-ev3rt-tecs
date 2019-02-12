include EV3RT_TECS
begin
    LCD.font=:medium
    LCD.draw("button sample", 0, 0)
    while true
        LCD.draw("left  button ", 0, 2) if Button[:left ].pressed?
        LCD.draw("right button ", 0, 2) if Button[:right].pressed?
        LCD.draw("up    button ", 0, 2) if Button[:up   ].pressed?
        LCD.draw("down  button ", 0, 2) if Button[:down ].pressed?
        LCD.draw("enter button ", 0, 2) if Button[:enter].pressed?
        break if Button[:back ].pressed?
    end
    
rescue => e
    LCD.error_puts e
end
