include EV3RT_TECS

begin

    LCD.font=:medium
    LCD.draw("led sample", 0, 0)
    while true
        LED.color=:green  if Button[:left ].pressed?
        LED.color=:orange if Button[:right].pressed?
        LED.color=:red    if Button[:up   ].pressed?
        LED.off           if Button[:down ].pressed?
        LED.color=:orange if Button[:enter].pressed?
        break if Button[:back ].pressed?
    end
rescue => e
    LCD.error_puts e
end
