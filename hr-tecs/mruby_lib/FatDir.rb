# coding: utf-8
unless $initialized
  module EV3RT_TECS
    class FatDir < TECS::TsFatDir

      private
      def initialize
        super "BridgeFatDir"
      end

      public
      def open(name)
        p_name = TECS::CharPointer.new(name.length + 1) # name.to_s.length + 1 の大きさを持つ記憶域を指すポインタを生成して返す。
        p_name.from_s name
        fopendir(p_name)
      end

      def read()
        buf = TECS::CharPointer.new(13)
        freaddir(buf, 13)
        # LCD.draw(buf.value, 0, 1) # String型ではないからエラー
        # LCD.draw(buf.to_s, 0, 2)
        return buf.to_s
      end

      def close
        fclosedir
      end

    end
  end
end
