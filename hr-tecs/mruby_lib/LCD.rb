unless $initialized
  module EV3RT_TECS
    class LCD < TECS::TsLCD
      @@font = {:small=>0, :medium=>1}
      @@lcd_color = {:white=>0, :black=>1}
      private
      def initialize
        super "BridgeLCD"
        clear
      end
      @@instance = self.new
      public
      def self.font=(fnt)
        if @@font[fnt] == nil 
          LCD.error_puts "#{fnt} is unknown font"
          return
        end 
        @@instance.setFont(@@font[fnt])
      end
      def self.draw(str, x, y)
        buf=TECS::CharPointer.new( str.length + 1 )
        buf.from_s str
        @@instance.drawString(buf, x, y)
      end
      def self.fill_rect(x, y, w, h, color)
        if @@lcd_color[color] == nil 
          LCD.error_puts "#{color} is unknown color"
          return
        end 
        @@instance.fillRect(x, y, w, h, @@lcd_color[color]);
      end
      def self.draw_line(x0, y0, x1, y1)
        @@instance.drawLine(x0, y0, x1, y1)
      end
      def self.show_message_box(title, msg)
        title_buf=TECS::CharPointer.new( title.to_s.length + 1 )
        title_buf.from_s title.to_s

        msg_buf=TECS::CharPointer.new( msg.to_s.length + 1 )
        msg_buf.from_s msg.to_s
        @@instance.showMessageBox(title_buf, msg_buf)
      end
      def self.error_puts (msg)
        self.show_message_box("ERROR", msg)
      end
      def self.print (msg)
        msg_buf=TECS::CharPointer.new( msg.to_s.length + 1 )
        msg_buf.from_s msg.to_s
        @@instance.print msg_buf
      end
      def self.puts (msg)
        msg_buf=TECS::CharPointer.new( msg.to_s.length + 1 )
        msg_buf.from_s msg.to_s
        @@instance.puts msg_buf
      end

    end
  end
end # unless $initialized
