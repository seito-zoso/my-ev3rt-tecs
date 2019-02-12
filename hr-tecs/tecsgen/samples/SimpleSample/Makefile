TECSGEN=tecsgen

.PHONY : allall
allall :
	make tecs
	make all

.PHONY : all
all :
	cd SimpleSample; make all TECSGEN_EXE=$(TECSGEN_EXE)
	cd SimpleSampleOpaqueRPC; make all TECSGEN_EXE=$(TECSGEN_EXE)
	cd SimpleSampleTransparentRPC; make all TECSGEN_EXE=$(TECSGEN_EXE)

.PHONY : tecs
tecs :
	cd SimpleSample; make tecs TECSGEN=$(TECSGEN_EXE)
	cd SimpleSampleOpaqueRPC; make tecs TECSGEN=$(TECSGEN_EXE)
	cd SimpleSampleTransparentRPC; make tecs TECSGEN=$(TECSGEN_EXE)

.PHONY : clean
clean :
	cd SimpleSample; make clean
	cd SimpleSampleOpaqueRPC; make clean
	cd SimpleSampleTransparentRPC; make clean

