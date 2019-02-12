unless $initialized
  module EV3RT_TECS
    class LED < TECS::TsLED
      @@color_hash = {:off=>0, :red=>1, :green=>2, :orange=>3}
      private 
      def initialize()
        super "BridgeLED"
      end
      @@instance = self.new
      public
      def self.color= (clr)
        @@instance.setColor( @@color_hash[clr] )
      end
      def self.off
        @@instance.off
      end
    end
  end
end # unless $initialized
