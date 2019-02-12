unless $initialized
  module EV3RT_TECS
    class GyroSensor < TECS::TsGyroSensor
      def initialize( port )
        @port = port
        if($port_hash[port] == nil)
          $port_hash[port] = "GyroSensor"
        else
          LCD.error_puts "GyroSensor::#{$port_hash[port]} has already used #{port}"
          raise "GyroSensor::#{$port_hash[port]} has already used #{port}"
        end
        puts "call GyroSensor for #{port}"
        case port
        when :port_1 then
          realname = "BridgeGyroSensor1"
        when :port_2 then
          realname = "BridgeGyroSensor2"
        when :port_3 then
          realname = "BridgeGyroSensor3"
        when :port_4 then
          realname = "BridgeGyroSensor4"
        else
          LCD.error_puts "#{port} is unknown port for GyroSensor."
          raise "#{port} is unknown port for GyroSensor."
        end
        super realname
        initializePort
      end
      def rate
        getRate
      end
      def angle
        getAngle
      end
      def calibrate(n = 200)
        ret = super(n)
        return :E_OBJ if ret == -41.0
        ret
      end
    end
  end
end # unless $initialized
