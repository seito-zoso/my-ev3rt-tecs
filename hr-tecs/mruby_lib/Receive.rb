# coding: utf-8
unless $initialized
  module EV3RT_TECS
    class Receive < TECS::TsReceive

      private
      def initialize
        super "BridgeReceive"
      end

      public
      def recv(name)
        p_name = TECS::CharPointer.new(name.length + 1) # name.to_s.length + 1 の大きさを持つ記憶域を指すポインタを生成して返す。
        p_name.from_s name
        receive(p_name)
      end

    end
  end
end
