TECSGEN_EXE=tecsgen
TECSMERGE_EXE=tecsmerge

all : 0 1 2 3 4 5 6 6.2

0:
	if [ ! -d src ]; then mkdir src; fi

1: gen-1
gen-1 :
	$(TECSGEN_EXE) -k utf8 -I ../cygwin -I ../../tecs -g gen-1 merge-1.cdl
	$(TECSMERGE_EXE) gen-1 src
	diff src/tCelltype.c gen-1/tCelltype_templ.c

2: gen-2
gen-2 :
	$(TECSGEN_EXE) -k utf8 -I ../cygwin -I ../../tecs -g gen-2 merge-2.cdl
	$(TECSMERGE_EXE) gen-2 src
	diff src/tCelltype.c gen-2/tCelltype_templ.c

3: gen-3
gen-3:
	$(TECSGEN_EXE) -k utf8 -I ../cygwin -I ../../tecs -g gen-3 merge-3.cdl
	$(TECSMERGE_EXE) gen-3 src
	diff src/tCelltype.c gen-3/tCelltype_templ.c
4: gen-4
gen-4:
	$(TECSGEN_EXE) -k utf8 -I ../cygwin -I ../../tecs -g gen-4 merge-4.cdl
	$(TECSMERGE_EXE) -p eEnt2:eEntX -f func:funcX -f func2:funcX2 gen-4 src
#	-diff src/tCelltype.c gen-4/tCelltype_templ.c
#       関数名が異なるため diff が出て ignore error となるので外す
5: gen-5
gen-5:
	$(TECSGEN_EXE) -k utf8 -I ../cygwin -I ../../tecs -g gen-5 merge-5.cdl
	$(TECSMERGE_EXE) -p eEntX:eEnt2 gen-5 src
#	-diff src/tCelltype.c gen-5/tCelltype_templ.c
#       関数名が異なるため diff が出て ignore error となるので外す
6: gen-6
gen-6:
	echo " *** 6 *** "
	$(TECSGEN_EXE) -k utf8 -I ../cygwin -I ../../tecs -g gen-6 merge-6.cdl
	$(TECSMERGE_EXE) -p eEnt2 -f funcX:func -f funcX2:func2 gen-6 src
	diff src/tCelltype.c gen-6/tCelltype_templ.c

6.2:
	echo " *** 6.2 *** "
	cp src.org/tCelltype.c src
	$(TECSMERGE_EXE) gen-6 src
	diff -w src.org/tCelltype.c src/tCelltype.c
	# -w: eol code is different between exerb and non-exerb

clean :
	rm -rf gen
	rm -rf gen-1
	rm -rf gen-2
	rm -rf gen-3
	rm -rf gen-4
	rm -rf gen-5
	rm -rf gen-6
	rm -rf src
