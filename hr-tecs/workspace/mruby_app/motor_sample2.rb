include EV3RT_TECS
begin
    LCD.puts "motor sample2"
    motor_port  = Parameter.tail_motor_port
    #Sensors and Actuators
    LCD.puts "motor port:#{motor_port}"

    motor = Motor.new(motor_port) 

    LCD.puts "motor type is #{motor.type}"
    count = motor.count
    LCD.puts "motor count = #{count}"
    target = 20
    if count > 0
      angle = -target - count
    elsif count <= 0
      angle = target - count
    end
    motor.rotate( angle, 10, false)

    count = motor.count
    LCD.puts "motor angle=#{angle} count = #{count}"
    puts "motor angle=#{angle} count = #{count}"
rescue => e
    LCD.error_puts e
end 

