unless $initialized
  module EV3RT_TECS
    class BatteryImpl < TECS::TsBattery
      def initialize( bridge_name )
        super 
      end
      # def mA
      #   current_mA
      # end
      # def mV
      #   voltage_mV
      # end
      alias :mA :current_mA
      alias :mV :voltage_mV
    end
    Battery = BatteryImpl.new "BridgeBattery"
  end
end # unless $initialized
