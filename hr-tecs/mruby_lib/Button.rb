# coding: utf-8
unless $initialized
  module EV3RT_TECS
    class Button < TECS::TsButton
      private
      @@button_hash = {:left=>0, :right=>1, :up=>2, :down=>3, :enter=>4, :back=>5}
      @@buttons_instance = Hash.new
      
      def initialize( button )
        @button = button
      end
      
      public
      def self.[](subscript)
        #LCD.puts "#{subscript} is unknown button type."if @@button_hash[subscript] == nil
        if @@buttons_instance[subscript] == nil
          @@buttons_instance[subscript] = EV3RT_TECS::Button.new(@@button_hash[subscript])
        else
          @@buttons_instance[subscript]
        end
      end
      def pressed?
        isPressed( @button )
      end
      # この alias は、うまくいかないようです
      # alias pressed? :isPressed
    end
  end
end # unless $initialized
