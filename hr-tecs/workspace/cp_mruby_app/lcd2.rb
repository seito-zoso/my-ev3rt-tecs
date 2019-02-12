include EV3RT_TECS

begin
    LCD.font=:medium
    #LCD.font=:small
    
    LCD.fill_rect(0, 0, 178, 128, :black)
    LCD.draw("lcd sample2", 0, 0)
    15.times{|i|
        LCD.draw("#{i}",i, i+1)
    }
rescue => e
    LCD.error_puts e
end
