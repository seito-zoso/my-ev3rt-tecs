# coding: cp932
include EV3RT_TECS

# �|�[�g�ԍ��̐ݒ�
TOUCH_SENSOR = Parameter.touch_sensor_port
COLOR_SENSOR = Parameter.color_sensor_port
GYRO_SENSOR  = Parameter.gyro_sensor_port
SONAR_SENSOR = Parameter.sonar_sensor_port

TAIL_MOTOR   = Parameter.tail_motor_port
RIGHT_MOTOR  = Parameter.right_motor_port
LEFT_MOTOR   = Parameter.left_motor_port

#���L�̒萔�l�͌�/���ɍ��킹�ĕύX����K�v������܂�
GYRO_OFFSET = 0           # �W���C���Z���T�I�t�Z�b�g�l(�p���x0[deg/sec]��)
SONAR_ALERT_DISTANCE = 30 # �����g�Z���T�ɂ���Q�����m����[cm]
TAIL_ANGLE_STAND_UP = 90  # ���S��~���̊p�x[�x]
TAIL_ANGLE_DRIVE = 3      # �o�����X���s���̊p�x[�x]
P_GAIN = 2.5              # ���S��~�p���[�^������W��
PWM_ABS_MAX = 60          # ���S��~�p���[�^����PWM��΍ő�l

BACKLASHHALF =  4         # �o�b�N���b�V���̔���[deg]

@sonar_counter = 0
@sonar_alert_var = false
#*****************************************************************************
# �����g�Z���T�ɂ���Q�����m
# ���� : ����
# �Ԃ�l : 1(��Q������)/0(��Q������)
#*****************************************************************************
def sonar_alert
    @sonar_counter += 1
    if @sonar_counter == 10
        distance = @sonar.distance
        @sonar_alert_var = distance <= SONAR_ALERT_DISTANCE && distance >= 0
        @sonar_counter = 0
    end
    @sonar_alert_var
end
#*****************************************************************************
# �J���[�Z���T�[�̃L�����u���[�V����
# ���� : n (�����) �ȗ�����10
# n�񑪒肵�����ϒl
#*****************************************************************************
def color_calibration(n=10)
    while true
        break if @touch.pressed?
        RTOS.delay(10)
    end
    col = 0
    n.times { col += @color.reflect}
    col = (col / n).round
    Speaker.tone(:a4, 200)
    RTOS.delay(500)
    col
end
#*****************************************************************************
# ���s�̊��S��~�p���[�^�̊p�x����
# ���� : angle (���[�^�ڕW�p�x[�x])
# �Ԃ�l : ����
#*****************************************************************************
def tail_control(angle)
    pwm = ((angle - @motor_t.count) * P_GAIN).to_i
    if pwm > PWM_ABS_MAX
        pwm = PWM_ABS_MAX
    elsif pwm < -PWM_ABS_MAX
        pwm = -PWM_ABS_MAX
    end

    if pwm == 0
        @motor_t.stop(true)
    else
        @motor_t.power = pwm
    end
end
#main�v���O����
begin
    # LCD��ʕ\��
    LCD.puts "ev3way_sample.rb"
    LCD.puts "--- mruby version ---"
    Speaker.volume = 1
    forward = turn = 0
    # �e�I�u�W�F�N�g�𐶐��E����������
    @sonar = UltrasonicSensor.new(SONAR_SENSOR)
    @color = ColorSensor.new(COLOR_SENSOR)
    @color.reflect
    @touch = TouchSensor.new(TOUCH_SENSOR)
    @gyro  = GyroSensor.new(GYRO_SENSOR)
    motor_l = Motor.new(LEFT_MOTOR)
    motor_r = Motor.new(RIGHT_MOTOR)
    @motor_t = Motor.new(TAIL_MOTOR)
    @motor_t.reset_count
    # LED:�I�����W �L�����u���[�V�������
    LED.color = :orange
    # ���E���F�̃L�����u���[�V����
    black_value = color_calibration
    LCD.puts "black::#{black_value}"
    white_value = color_calibration
    LCD.puts "white::#{white_value}"

    threshold = ((black_value + white_value) / 2).round
    # �X�^�[�g�ҋ@
    LCD.puts "Ready to start"
    while true
        # ���S��~�p�p�x�ɐ���
        tail_control(TAIL_ANGLE_STAND_UP)
        # �^�b�`�Z���T���������܂ő҂�
        break if @touch.pressed?
        RTOS.delay(10)
    end
    # ���s���[�^�G���R�[�_�[���Z�b�g
    motor_l.reset_count
    motor_r.reset_count
    # �W���C���Z���T���Z�b�g
    @gyro.reset

    # LED:�� ���s���
    LED.color = :green

    wait = 3
    # main loop
    forward = turn = 0
    while true
        # �o�����X���s�p�p�x�ɐ���
        tail_control(TAIL_ANGLE_DRIVE)
        # ��Q�����m
        if sonar_alert
            forward = turn = 0
        else
            # ���C���g���[�X
            forward = 30
            turn = @color.reflect >= threshold ? 20 : -20
        end
        # �|���U�q����API���Ăяo���A�|�����s���邽�߂�
        # ���E���[�^�o�͒l�𓾂� */
        pwm_l, pwm_r = Balancer.control(
                 forward,
                 turn,
                 @gyro.rate,
                 GYRO_OFFSET,
                 motor_l.count,
                 motor_r.count,
                 Battery.mV,
                 BACKLASHHALF)

        if pwm_l == 0
            motor_l.stop(true)
        else
            motor_l.power = pwm_l
        end
    
        if pwm_r == 0
            motor_r.stop(true) 
        else
            motor_r.power = pwm_r
        end

        RTOS.delay(wait)
    end
    motor_l.stop(false)
    motor_r.stop(false)
rescue => e
  LCD.error_puts e
end
