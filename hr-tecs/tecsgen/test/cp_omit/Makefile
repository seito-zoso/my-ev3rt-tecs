TECSGEN=tecsgen

.PHONY : all
all :
	make -f Makefile1 TECSGEN=$(TECSGEN)
	make -f Makefile2 TECSGEN=$(TECSGEN)

.PHONY : tecs
tecs :
	make -f Makefile1 tecs TECSGEN=$(TECSGEN)
	make -f Makefile2 tecs TECSGEN=$(TECSGEN)

.PHONY : clean
clean :
	make -f Makefile1 clean
	make -f Makefile2 clean
