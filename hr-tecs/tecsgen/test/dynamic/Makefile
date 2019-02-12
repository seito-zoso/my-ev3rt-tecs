TECSGEN=tecsgen

.PHONY : all
all :
	make -f Makefile-normal
	make -f Makefile-ram-initializer
	make -f Makefile-ramonly
	make -f Makefile-singleton
	make -f Makefile-singleton-ramonly
	make -f Makefile-singleton-ram-initializer
	make -f Makefile-array
	make -f Makefile-array-r
	make -f Makefile-array-ram-initializer
	make -f Makefile-singleton-array
	make -f Makefile-singleton-array-r
	make -f Makefile-singleton-array-ram-initializer

.PHONY : tecs
tecs :
	make tecs -f Makefile-normal
	make tecs -f Makefile-ramonly
	make tecs -f Makefile-ram-initializer
	make tecs -f Makefile-singleton
	make tecs -f Makefile-singleton-ramonly
	make tecs -f Makefile-singleton-ram-initializer
	make tecs -f Makefile-array
	make tecs -f Makefile-array-r
	make tecs -f Makefile-array-ram-initializer
	make tecs -f Makefile-singleton-array
	make tecs -f Makefile-singleton-array-r
	make tecs -f Makefile-singleton-array-ram-initializer

.PHONY : clean
clean :
	make clean -f Makefile-normal 
	make clean -f Makefile-ramonly 
	make clean -f Makefile-ram-initializer 
	make clean -f Makefile-singleton 
	make clean -f Makefile-singleton-ramonly
	make clean -f Makefile-singleton-ram-initializer
	make clean -f Makefile-array 
	make clean -f Makefile-array-r 
	make clean -f Makefile-array-ram-initializer
	make clean -f Makefile-singleton-array 
	make clean -f Makefile-singleton-array-r 
	make clean -f Makefile-singleton-array-ram-initializer

.PHONY : test_exec
test_exec :
	./dynamic.exe
	@echo ===============
	./dynamic-r.exe
	@echo ===============
	./dynamic-ram-initializer.exe
	@echo ===============
	./dynamic-singleton.exe
	@echo ===============
	./dynamic-singleton-r.exe
	@echo ===============
	./dynamic-singleton-ram-initializer.exe
	@echo ===============
	./dynamic-array.exe
	@echo ===============
	./dynamic-array-r.exe
	@echo ===============
	./dynamic-array-ram-initializer.exe
	@echo ===============
	./dynamic-singleton-array.exe
	@echo ===============
	./dynamic-singleton-array-r.exe
	@echo ===============
	./dynamic-singleton-array-ram-initializer.exe
