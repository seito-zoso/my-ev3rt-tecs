unless $initialized
  module EV3RT_TECS
    class Balancer < TECS::TsBalancer
      attr_accessor :pwm_l, :pwm_r
      
      private 
      def initialize
        super "BridgeBalancer"
        init
        @pwm_l = TECS::Int8Pointer.new(1)
        @pwm_r = TECS::Int8Pointer.new(1)
      end
      @@instance = self.new
      public
      def self.control(forward, turn, gyro, offset, angle_l, angle_r, vlt, backlashhalf)
        @@instance.control(forward, turn, gyro, offset, angle_l, angle_r, vlt, @@instance.pwm_l, @@instance.pwm_r, backlashhalf)
        return @@instance.pwm_l.value, @@instance.pwm_r.value
      end
    end
  end
end # unless $initialized
