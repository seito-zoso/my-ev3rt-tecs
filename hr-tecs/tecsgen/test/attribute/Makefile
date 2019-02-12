clean :
	make -f Makefile.ROM clean
	make -f Makefile.RAM clean
	make -f Makefile.RAMONLY clean

tecs :
	make -f Makefile.ROM tecs
	make -f Makefile.RAM tecs
	make -f Makefile.RAMONLY tecs

all:
	make -f Makefile.ROM all
	make -f Makefile.RAM all
	make -f Makefile.RAMONLY all

rom :
	make -f Makefile.ROM tecs
	make -f Makefile.ROM all
ram :
	make -f Makefile.RAM tecs
	make -f Makefile.RAM all
ramonly :
	make -f Makefile.RAMONLY tecs
	make -f Makefile.RAMONLY all
