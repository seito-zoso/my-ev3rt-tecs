# coding: utf-8
unless $initialized
  module EV3RT_TECS
    class FatFile < TECS::TsFatFile

      private
      def initialize
        super "BridgeFatFile"
      end

      public
      def open(name, mode)
        p_name = TECS::CharPointer.new(name.length + 1) # name.to_s.length + 1 の大きさを持つ記憶域を指すポインタを生成して返す。
        p_mode = TECS::CharPointer.new(mode.length + 1)
        p_name.from_s name
        p_mode.from_s mode
        fopen(p_name, p_mode)
      end

      def puts(str)
        buf = TECS::CharPointer.new(str.length + 1)
        buf.from_s str
        p_bw = TECS::UIntPointer.new(1)
        fwrite(buf, str.length, p_bw)
      end

      def write(name, str)
        p_name = TECS::CharPointer.new(name.length + 1)
        p_name.from_s name
        mode = "w"
        p_mode = TECS::CharPointer.new(name.length + 1)
        p_mode.from_s mode
        fopen(p_name, p_mode)
        buf = TECS::CharPointer.new(str.length + 1)
        buf.from_s str
        p_bw = TECS::UIntPointer.new(1)
        fwrite(buf, str.length, p_bw)
        fclose
        return p_bw.value.to_s
      end

      def read(btr)
        buf = TECS::CharPointer.new(btr)
        fread(buf, btr)
        # LCD.draw(buf.value, 0, 1) # String型ではないからエラー
        # LCD.draw(buf.to_s, 0, 1)
        return buf.to_s
      end

      def close
        fclose
      end

      def delete(name)
        p_name = TECS::CharPointer.new(name.length + 1) # name.to_s.length + 1 の大きさを持つ記憶域を指すポインタを生成して返す。
        p_name.from_s name
        unlink(p_name)
      end

    end
  end
end # unless $initialized
