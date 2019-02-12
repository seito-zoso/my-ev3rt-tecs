unless $initialized
  module EV3RT_TECS
    class UltrasonicSensor < TECS::TsUltrasonicSensor
      
      def initialize( port )
        if($port_hash[port] != nil)
          LCD.error_puts "UltrasonicSensor::#{$port_hash[port]} has already used #{port}"
          raise "UltrasonicSensor::#{$port_hash[port]} has already used #{port}"
        else
          $port_hash[port] = "UltrasonicSensor"
        end
        @port = port
        case port
        when :port_1 then
          realname = "BridgeUltrasonicSensor1"
        when :port_2 then
          realname = "BridgeUltrasonicSensor2"
        when :port_3 then
          realname = "BridgeUltrasonicSensor3"
        when :port_4 then
          realname = "BridgeUltrasonicSensor4"
        else
          LCD.error_puts "#{port} is unknown port for UltrasonicSensor."
          raise "#{port} is unknown port for UltrasonicSensor."
        end
        super realname
        initializePort
      end
      
      # def distance
      #   getDistance
      # end
      alias :distance :getDistance
    end
  end
end # unless $initialized
