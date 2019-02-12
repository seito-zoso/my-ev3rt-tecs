TECSGEN_EXE=tecsgen

all : a b c d e z

a :
	$(TECSGEN_EXE) -I include -Iconfig_win -I. import_C.cdl

b :
	$(TECSGEN_EXE) -I include -Iconfig_win -I. toppers_jsp.cdl

c :
	$(TECSGEN_EXE) -I include -Iconfig_win -I. myappl.cdl

d :
	gcc -E -DTECS -Iinclude -Iconfig_win -I. a.c | sed -e 's,^\(#.*$\\),/* \1 */,' > gen/win.h

e :
	$(TECSGEN_EXE) -I include -Iconfig_win -I. dupl-incl.cdl


z:	# cygwin のシンボリックリンク対策 (exerb 版向け)
	if [ -x /bin/gcc-3.exe ] ; then cpp=gcc-3; elif [ -x /bin/gcc-4.exe ] ; then cpp=gcc-4; else cpp=gcc; fi ; \
	 $(TECSGEN_EXE) "--cpp=$$cpp -E -DTECSGEN -Iinclude -Iconfig_win -I." -I include import_C.cdl

error:
	-$(TECSGEN_EXE) -Iinclude -Iconfig_win -I. -DERROR import_C.cdl
	@echo "##########################"
	@echo "# this results cpp error #"
	@echo "##########################"

clean:
	rm -rf gen
