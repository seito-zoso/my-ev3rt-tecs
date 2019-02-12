include EV3RT_TECS

begin

    instant = Receive.new
    instant.recv()

rescue => e
    LCD.error_puts e
end
