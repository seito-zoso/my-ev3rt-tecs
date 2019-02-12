unless $initialized
  module EV3RT_TECS
    class Motor < TECS::TsMotor
      @@motor_type_hash = {1=>:large,2=>:medium,-18=>:E_ID}
      def initialize(port, type=:large)
        @port = port
        @type = type           
        if($port_hash[port] != nil)
          LCD.error_puts"#{$port_hash[port]}(#{@type}) has already used #{port}"
          raise "#{$port_hash[port]}(#{@type}) has already used #{port}"
        else
          $port_hash[port] = "Motor"
        end
        case port
        when :port_a then
          realname = "BridgeMotorA"
        when :port_b then
          realname = "BridgeMotorB"
        when :port_c then
          realname = "BridgeMotorC"
        when :port_d then
          realname = "BridgeMotorD"
        else
          LCD.error_puts "#{port} is unknown port for Motor."
          raise "#{port} is unknown port for Motor."
        end
        super realname
        case type
        when :large
          initializePort(1)
        when :medium
          initializePort(2)
        end
      end
      def type
        @@motor_type_hash[getType]
      end
      def power=(pwm)
        setPower pwm
      end
      def power
        getPower
      end
      def stop(brake=true)
        super brake
      end
      def rotate(deg, spd, blk=false)
        super deg, spd, blk
      end
      def count
        getCounts
      end
      def reset_count
        resetCounts
      end
    end
  end    
end # unless $initialized
