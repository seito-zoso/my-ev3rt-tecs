TECSGEN_EXE = tecsgen
TECSMERGE_EXE = tecsmerge
TECSGEN = $(TECSGEN_EXE) -I RUNTIME/runtime/include -I RUNTIME/runtime/test -I ../cgywin
TECSGEN_N = $(TECSGEN_EXE) -I RUNTIME/runtime/include -I RUNTIME/runtime/test

COPT = -g -c -IRUNTIME/runtime/test -IRUNTIME/runtime/include -Igen -Isrc -Igen_comp

ERR_TARGETS = \
	portarray-err \
	composite_err \
	composite_init_err \
	init-err \
	attribute-err \
	attribute-err2 \
	attribute-err-1 \
	attribute-err-2 \
	attribute-err-3 \
	attribute-err-4 \
	attribute-err-5 \
	const-err \
	sign-err \
	factory-err \
	only_proto \
	import_C-err \
	require-err \
	oneway-err \
	duplicate-err \
	region-err \
	expression-err \
	bug_test2-err \
	singleton-err \
	param-err \
	domainPlugin-err \
	cell-err \
# TERMINATOR


ifeq ($(MAKECMDGOALS),do_rcov)
	TEST_ERR.SH = sh test_err.sh -r
	TECSGEN=tecsgen_rcov.rb
else ifeq ($(MAKECMDGOALS),test_exerb)
	TEST_ERR.SH = sh test_err.sh -e
	TECSGEN=tecsgen.exe
else
	TEST_ERR.SH = sh test_err.sh
	TECSGEN=tecsgen
endif

.PHONY: all
all: test_err

.PHONY: do_rcov
do_rcov: test_err

.PHONY: test_err
test_exerb: test_err

.PHONY: clean
clean :
	rm -rf gen

.PHONY: test_err
test_err: $(ERR_TARGETS)

.PHONY: portarray-err
portarray-err :
	$(TEST_ERR.SH) 15 4 $@.cdl

composite_err : composite_err.cdl
	$(TEST_ERR.SH) 26 7 $@.cdl

composite_init_err : composite_init_err.cdl
	$(TEST_ERR.SH) 3 8 $@.cdl

.PHONY: only_proto
only_proto : only_proto.cdl
	$(TEST_ERR.SH) 1 2 $@.cdl

.PHONY: factory-err
factory-err : factory-err.cdl factory-err2.cdl
	$(TEST_ERR.SH) 7 0 factory-err.cdl
	$(TEST_ERR.SH) 2 0 factory-err2.cdl

init-err : init-err.cdl
	$(TEST_ERR.SH) 19 6 init-err.cdl

attribute-err : attribute-err.cdl
	-$(TECSGEN) attribute-err.cdl
	@echo "####################################################"
	@echo "#  This cause ruby exception in current version    #"
	@echo "#  This results in 23 errors                       #"
	@echo "####################################################"

attribute-err2 :
	$(TEST_ERR.SH) 10 4 $@.cdl

attribute-err-1 :
	$(TEST_ERR.SH) 56 0 $@.cdl

attribute-err-2 :
	$(TEST_ERR.SH) 2 1 $@.cdl

attribute-err-3 :
	$(TEST_ERR.SH) 7 0 $@.cdl

attribute-err-4 :
	$(TEST_ERR.SH) 0 1 $@.cdl

attribute-err-5 :
	$(TEST_ERR.SH) 2 3 $@.cdl

const-err : const-err.cdl
	$(TEST_ERR.SH) 9 1 $@.cdl

import_C-err :
	-cd import_C ; make error TECSGEN_EXE=$(TECSGEN_EXE)

.PHONY: sign-err
sign-err :
	$(TEST_ERR.SH) 2 4 $@.cdl

.PHONY: require-err
require-err :
	$(TEST_ERR.SH) 3 5 $@.cdl

.PHONY: oneway-err
oneway-err :
	$(TEST_ERR.SH) 3 0 $@.cdl

.PHONY: duplicate-err
duplicate-err :
	$(TEST_ERR.SH) 13 1 $@.cdl

.PHONY: region-err
region-err :
	$(TEST_ERR.SH) 3 4 $@.cdl

.PHONY: expression-err
expression-err:
	$(TEST_ERR.SH) 13 5 $@.cdl

.PHONY: bug_test2-err
bug_test2-err:
	$(TEST_ERR.SH) 1 2 $@.cdl

.PHONY: singleton-err
singleton-err:
	$(TEST_ERR.SH) 2 3 $@.cdl

.PHONY: param-err
param-err:
	$(TEST_ERR.SH) 8 0 $@.cdl

.PHONY: domainPlugin-err
domainPlugin-err:
	$(TEST_ERR.SH) 3 0 -I ../cygwin $@.cdl

.PHONY: cell-err
cell-err:
	$(TEST_ERR.SH) 8 1 -I ../cygwin $@.cdl

#####

.c.o:
	gcc $(COPT) -o $@ $<
