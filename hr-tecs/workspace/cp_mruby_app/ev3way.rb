# coding: cp932
include EV3RT_TECS

# ポート番号の設定
TOUCH_SENSOR = Parameter.touch_sensor_port
COLOR_SENSOR = Parameter.color_sensor_port
GYRO_SENSOR  = Parameter.gyro_sensor_port
SONAR_SENSOR = Parameter.sonar_sensor_port

TAIL_MOTOR   = Parameter.tail_motor_port
RIGHT_MOTOR  = Parameter.right_motor_port
LEFT_MOTOR   = Parameter.left_motor_port

#下記の定数値は個体/環境に合わせて変更する必要があります
GYRO_OFFSET = 0           # ジャイロセンサオフセット値(角速度0[deg/sec]時)
SONAR_ALERT_DISTANCE = 30 # 超音波センサによる障害物検知距離[cm]
TAIL_ANGLE_STAND_UP = 90  # 完全停止時の角度[度]
TAIL_ANGLE_DRIVE = 3      # バランス走行時の角度[度]
P_GAIN = 2.5              # 完全停止用モータ制御比例係数
PWM_ABS_MAX = 60          # 完全停止用モータ制御PWM絶対最大値

BACKLASHHALF =  4         # バックラッシュの半分[deg]

@sonar_counter = 0
@sonar_alert_var = false
#*****************************************************************************
# 超音波センサによる障害物検知
# 引数 : 無し
# 返り値 : 1(障害物あり)/0(障害物無し)
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
# カラーセンサーのキャリブレーション
# 引数 : n (測定回数) 省略時は10
# n回測定した平均値
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
# 走行体完全停止用モータの角度制御
# 引数 : angle (モータ目標角度[度])
# 返り値 : 無し
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
#mainプログラム
begin
    # LCD画面表示
    LCD.puts "ev3way_sample.rb"
    LCD.puts "--- mruby version ---"
    Speaker.volume = 1
    forward = turn = 0
    # 各オブジェクトを生成・初期化する
    @sonar = UltrasonicSensor.new(SONAR_SENSOR)
    @color = ColorSensor.new(COLOR_SENSOR)
    @color.reflect
    @touch = TouchSensor.new(TOUCH_SENSOR)
    @gyro  = GyroSensor.new(GYRO_SENSOR)
    motor_l = Motor.new(LEFT_MOTOR)
    motor_r = Motor.new(RIGHT_MOTOR)
    @motor_t = Motor.new(TAIL_MOTOR)
    @motor_t.reset_count
    # LED:オレンジ キャリブレーション状態
    LED.color = :orange
    # 黒・白色のキャリブレーション
    black_value = color_calibration
    LCD.puts "black::#{black_value}"
    white_value = color_calibration
    LCD.puts "white::#{white_value}"

    threshold = ((black_value + white_value) / 2).round
    # スタート待機
    LCD.puts "Ready to start"
    while true
        # 完全停止用角度に制御
        tail_control(TAIL_ANGLE_STAND_UP)
        # タッチセンサが押されるまで待つ
        break if @touch.pressed?
        RTOS.delay(10)
    end
    # 走行モータエンコーダーリセット
    motor_l.reset_count
    motor_r.reset_count
    # ジャイロセンサリセット
    @gyro.reset

    # LED:緑 走行状態
    LED.color = :green

    wait = 3
    # main loop
    forward = turn = 0
    while true
        # バランス走行用角度に制御
        tail_control(TAIL_ANGLE_DRIVE)
        # 障害物検知
        if sonar_alert
            forward = turn = 0
        else
            # ライントレース
            forward = 30
            turn = @color.reflect >= threshold ? 20 : -20
        end
        # 倒立振子制御APIを呼び出し、倒立走行するための
        # 左右モータ出力値を得る */
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
