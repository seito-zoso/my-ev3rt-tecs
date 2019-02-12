# coding: utf-8
module EV3RT_TECS
  class Parameter
    class Param
      attr_accessor :touch_sensor_port, :color_sensor_port, :gyro_sensor_port, :sonar_sensor_port, :tail_motor_port, :right_motor_port, :left_motor_port

      def initialize(touch_sensor_port, color_sensor_port, gyro_sensor_port, sonar_sensor_port, tail_motor_port, right_motor_port, left_motor_port)
        @touch_sensor_port = touch_sensor_port
        @color_sensor_port = color_sensor_port
        @gyro_sensor_port = gyro_sensor_port
        @sonar_sensor_port = sonar_sensor_port
        @tail_motor_port = tail_motor_port
        @right_motor_port = right_motor_port
        @left_motor_port = left_motor_port
      end
    end

    def self.set(touch_sensor_port, color_sensor_port, gyro_sensor_port, sonar_sensor_port, tail_motor_port, right_motor_port, left_motor_port)
      @@parameter = Param.new(touch_sensor_port, color_sensor_port, gyro_sensor_port, sonar_sensor_port, tail_motor_port, right_motor_port, left_motor_port)
    end
    
    def self.touch_sensor_port
      @@parameter.touch_sensor_port
    end

    def self.color_sensor_port
      @@parameter.color_sensor_port
    end

    def self.gyro_sensor_port
      @@parameter.gyro_sensor_port
    end

    def self.sonar_sensor_port
      @@parameter.sonar_sensor_port
    end

    def self.tail_motor_port
      @@parameter.tail_motor_port
    end

    def self.right_motor_port
      @@parameter.right_motor_port
    end

    def self.left_motor_port
      @@parameter.left_motor_port
    end
  end
end
