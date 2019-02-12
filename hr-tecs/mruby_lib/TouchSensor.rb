unless $initialized
  module EV3RT_TECS
    class TouchSensor < TECS::TsTouchSensor
      def initialize( port )
        if($port_hash[port] != nil)
          LCD.error_puts "TouchSensor::#{$port_hash[port]} has used #{port}"
          raise "TouchSensor::#{$port_hash[port]} has used #{port}"
        else
          $port_hash[port] = "TouchSensor"
        end
        @port = port
        case port
        when :port_1 then
          realname = "BridgeTouchSensor1"
        when :port_2 then
          realname = "BridgeTouchSensor2"
        when :port_3 then
          realname = "BridgeTouchSensor3"
        when :port_4 then
          realname = "BridgeTouchSensor4"
        else
          LCD.error_puts "#{port} is unknown port for TouchSensor."
          raise "#{port} is unknown port for TouchSensor."
        end
        super realname
        initializePort
      end
      def pressed?
        isPressed
      end
    end
  end
end # unless $initialized
