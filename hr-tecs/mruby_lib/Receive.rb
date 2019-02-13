# coding: utf-8
unless $initialized
  module EV3RT_TECS
    class Receive < TECS::TsReceive

      private
      def initialize
        super "BridgeReceive"
      end

      public
      def recv()
        receive()
      end

    end
  end
end
