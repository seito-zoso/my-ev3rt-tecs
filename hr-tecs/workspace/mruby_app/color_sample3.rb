include EV3RT_TECS

begin
    LCD.font=:medium

    color_port = Parameter.color_sensor_port

    LCD.draw("color sample3", 0, 0)
    LCD.draw("port #{color_port}", 0, 2)

    color_sensor = ColorSensor.new(color_port)
    while true
        r, g, b  =  color_sensor.rgb
        LCD.draw("r = #{r}", 0, 4)
        LCD.draw("g = #{g}", 0, 5)
        LCD.draw("b = #{b}", 0, 6)
        RTOS.delay(500)
    end
rescue => e
    LCD.error_puts e
end
