include EV3RT_TECS

begin
    n = 10
    #測定オーバヘッドの測定
    startu  = RTOS.usec
    n.times{
        RTOS.usec
    }
    endu  = RTOS.usec
    overhead = (endu - startu) / (n + 1)
    
    a=[*1..10]
    sum = 0
    #測定開始
    startu = RTOS.usec
    a.each{|num|
        sum = sum + num
    }
    #測定終了
    endu = RTOS.usec
    
    LCD.puts "sum=#{sum}"
    LCD.puts "#{endu - startu - overhead}usec"
    
rescue => e
    LCD.error_puts e
end    
