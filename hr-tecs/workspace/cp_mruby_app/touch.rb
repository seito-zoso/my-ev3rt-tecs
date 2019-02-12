include EV3RT_TECS

begin
    LCD.font= :medium
    LCD.draw("touch sample", 0,1)

    touch_port = Parameter.touch_sensor_port

    LCD.draw("touch:#{touch_port}", 0, 2)
    touch_sensor = TouchSensor.new(touch_port)

    count = 0
    while true
        LCD.draw("touch count:#{count}", 0, 5)
        while !touch_sensor.pressed?  do end
        while touch_sensor.pressed?  do end
        count = count + 1
    end
rescue => e
    LCD.error_puts e
end

