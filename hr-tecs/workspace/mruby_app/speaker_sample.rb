include EV3RT_TECS

begin
    LCD.font=:medium
 
    LCD.puts "speaker sample"
    
    Speaker.volume= 1
    
    #[:f4, 100, :f4, 100, :f4, 100, :f4, 100,:e4, 100,:g4, 100,:f4, 100].each_slice(2){|tone,duration| #–{“–‚Í‚±‚¤‘‚«‚½‚¢
    [[:f5, 150], [:f5, 150], [:f5, 150], [:f5, 200],[:e5, 300],[:g5, 300],[:f5, 400]].each do |tone_duration|
        LCD.puts tone_duration
        Speaker.tone(tone_duration[0], tone_duration[1])
        RTOS.delay(tone_duration[1])
    end 
rescue => e
    LCD.error_puts e
end
