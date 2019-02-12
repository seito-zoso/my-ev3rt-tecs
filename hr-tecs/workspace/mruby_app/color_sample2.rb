include EV3RT_TECS

begin
    LCD.font=:medium
    
    color_port = Parameter.color_sensor_port
    
    LCD.draw("color sample2", 0, 0)
    LCD.draw("port #{color_port}", 0, 2)
    
    $color_sensor = ColorSensor.new(color_port)

    while true
        LCD.draw("color = black ", 0, 5) if $color_sensor.black?
        LCD.draw("color = blue  ", 0, 5) if $color_sensor.blue?
        LCD.draw("color = green ", 0, 5) if $color_sensor.green?
        LCD.draw("color = yellow", 0, 5) if $color_sensor.yellow?
        LCD.draw("color = red   ", 0, 5) if $color_sensor.red?
        LCD.draw("color = white ", 0, 5) if $color_sensor.white?
        LCD.draw("color = brown ", 0, 5) if $color_sensor.brown?
    end
rescue => e
    LCD.error_puts e
end

