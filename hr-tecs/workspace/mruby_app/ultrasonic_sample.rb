include EV3RT_TECS
begin
    LCD.font=:medium
    
    LCD.draw("ultrasonic sample", 0, 0)
    # Sensors and Actuators

    ultrasonic_port = Parameter.sonar_sensor_port

    LCD.draw("ultrasonic:#{ultrasonic_port}", 0, 2)
    ultrasonic_sensor = UltrasonicSensor.new(ultrasonic_port)
    
    LCD.draw("listen  = #{ultrasonic_sensor.listen}  ", 0, 3)
    while true
      distance = ultrasonic_sensor.distance
      LCD.draw("distance = #{distance}  ", 0, 4)
    end
rescue => e
    LCD.error_puts e
end    
