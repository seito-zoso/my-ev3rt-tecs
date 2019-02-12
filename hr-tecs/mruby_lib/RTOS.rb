unless $initialized
  module EV3RT_TECS
    class RTOS < TECS::TsKernel
        private
        def initialize()
            super "BridgeKernel"
        end
        @@instance = self.new
        
        public
        def self.delay(time)
            @@instance.delay(time)
        end
        
        def self.msec
            time = TECS::ULongPointer.new(1)
            @@instance.getTime(time)
            time.value
        end
        def self.usec
            time = TECS::ULongPointer.new(1)
            @@instance.getMicroTime(time)
            time.value
        end
        def self.sleep
            @@instance.sleep
        end
    end     
  end
end
