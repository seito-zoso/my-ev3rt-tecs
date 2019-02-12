unless $initialized
    module EV3RT_TECS
        class SharedMemory < TECS::TsSharedMemory
            private
            def initialize()
                super "BridgeSharedMemory"
            end
            @@instance = self.new
        end

        def []=(index, val)
    	    putVal(index, val)
        end

        def [](index)
    	    getVal(index)
        end
    end
end # unless $initialized
