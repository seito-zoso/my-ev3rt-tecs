include EV3RT_TECS

begin
  LCD.font=:medium
  LCD.puts "main sample"
  Sub1 = TECS::TsTask.new( 'MrubySubTask1eTaskBridge' )
  Sub2 = TECS::TsTask.new( 'MrubySubTask2eTaskBridge' )
  WakeupTask = TECS::TsTask.new( 'MrubyWakeupTaskeTaskBridge' )
  Wakeupper = TECS::TsCyclic.new( 'TaskCyclicWakeuppereCyclicBridge' )
  Cychdr  = TECS::TsCyclic.new( 'CyclicHandlereCyclicBridge' )

  Sub1.activate
  Sub2.activate
  WakeupTask.activate
  Wakeupper.start
  Cychdr.start
  loop{
    LCD.draw("mruby sample", 0, 0)
    RTOS.delay(100)   # every 1 second
  }
    
rescue => e
    LCD.error_puts e
end
