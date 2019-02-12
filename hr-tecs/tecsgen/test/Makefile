TECSGEN_EXE = tecsgen
TECSMERGE_EXE = tecsmerge
# TECSGEN = $(TECSGEN_EXE) -o -I RUNTIME/runtime/include -I RUNTIME/runtime/test
TECSGEN = $(TECSGEN_EXE) -I RUNTIME/runtime/include -I RUNTIME/runtime/test
TECSGEN_N = $(TECSGEN_EXE) -I RUNTIME/runtime/include -I RUNTIME/runtime/test

COPT = -g -c -IRUNTIME/runtime/test -IRUNTIME/runtime/include -Igen -Isrc -Igen_comp
#COPT = -g -c -IRUNTIME/runtime/target -IRUNTIME/runtime/include -Igen -Isrc -Igen_comp

TARGETS = \
	result-normal.txt \
	result-abnormal.txt \
	singleton \
	portarray \
	composite.1 \
	recursive_composite \
	recursive_composite2 \
	recursive_composite2_idx_is_id \
	recursive_composite3 \
	factory \
	import_C.1 \
	init \
	id \
	attribute.1 \
	bool \
	var.1 \
	struct.1 \
	struct.2 \
	namespace \
	region \
	region2.1 \
	allocator.1 \
	allocator2.1 \
	allocatorCB.1 \
	romram.1 \
	foreach.1 \
	composite_alloc.1 \
	composite_alloc3.1 \
	require \
	require2 \
	params.1 \
	inline.1 \
	hello.1 \
	simple.1 \
	optional.1 \
	series \
	pointer.1 \
	c_exp \
	const \
	float \
	sjis.1 \
	merge.1 \
	dataqueue.1 \
	through \
	rpc.1 \
	sharedRPC.1 \
	opaqueRPC.1 \
	opaqueMarshaler \
	sharedOpaqueRPC.1 \
	signaturePlugin \
	celltypePlugin \
	cellPlugin \
	CPPBridge \
	reverse_require \
	domainPlugin \
	reverse_join \
	proto \
	cp_omit \
	NotificationPlugin \
	restrict \
	dynamic

#	optimize.1 \

#	bug_test     # 他のルールとの関係でエラーになる

all: $(TARGETS)

.PHONY: test_err
test_err:
	cd ErrorCase; make

result-normal.txt :
	bash test-normal.sh $(TECSGEN_EXE) > result-normal.txt

result-abnormal.txt :
	bash test-abnormal.sh $(TECSGEN_EXE) > result-abnormal.txt

# SimpleCov カバレッジ
#   coverage result is placed under 'tecsgen' directory.
do_rcov : clean
	make do_rcov.2 TECSGEN_EXE=tecsgen_rcov.rb TECSMERGE_EXE=tecsmerge

do_rcov.2 : $(TARGETS)
	cd ErrorCase ; make do_rcov
# end SimpleCov カバレッジ

# test
do_test :
	make do_test.2  TECSGEN_EXE=tecsgen_deb TECSMERGE_EXE=tecsmerge

do_test.2 : $(TARGETS)

.PHONY: clean
clean:
	rm -f result*.txt
	rm -rf gen/*
	rm -f src*/*.o
	rm -rf sample/data-{normal,error,abnormal,flat}/gen
	rm -rf coverage coverage.data
	cd composite  ; make clean
	cd recursive_composite  ; make clean
	cd recursive_composite2 ; make clean
	cd recursive_composite2_idx_is_id ; make clean
	cd recursive_composite3 ; make clean
	cd through ; make clean
	cd import_C ; make clean
	cd rpc ; make clean
	cd composite_namespace ; make clean
	cd namespace ; make clean
	cd attribute ; make clean
	cd bool ; make clean
	cd var ; make clean
	cd struct ; make clean
	cd region ; make clean
	cd region2 ; make clean
	cd allocator ; make clean
	cd allocator2 ; make clean
	cd allocatorCB ; make clean
	cd romram ; make clean
	cd foreach ; make clean
	cd composite_alloc ; make clean
	cd composite_alloc3 ; make clean
	cd inline ; make clean
	cd hello ; make clean
	cd simple ; make clean
	cd opaqueRPC ; make clean
	cd opaqueMarshaler ; make clean
	cd optional ; make clean
	cd series ; make clean
	cd require ; make clean
	cd require2 ; make clean
	cd params ; make clean
	cd pointer ; make clean
	cd sjis ; make clean
	cd merge ; make clean
	cd optimize ; make clean
	cd sharedRPC ; make clean
	cd sharedOpaqueRPC ; make clean
	cd dataqueue ; make clean
	cd signaturePlugin ; make clean
	cd celltypePlugin ; make clean
	cd cellPlugin ; make clean
	cd CPPBridge ; make clean
	cd reverse_require ; make clean
	cd ErrorCase ; make clean
	cd domainPlugin ; make clean
	cd reverse_join ; make clean
	cd proto ; make clean
	cd cp_omit ; make clean
	cd NotificationPlugin ; make clean
	cd restrict ; make clean
	cd dynamic ; make clean


SINGLE_OBJ = \
   gen/tSingle_tecsgen.o \
   gen/tSingleEntry_tecsgen.o \
   gen/tSingleCall_tecsgen.o \
   src/tSingle.o \
   src/tSingleEntry.o \
   src/tSingleCall.o

.PHONY: singleton
singleton: gen/tSingle_tecsgen.h singleton.exe

gen/tSingle_tecsgen.h : singleton.cdl
	$(TECSGEN) singleton.cdl

singleton.exe : $(SINGLE_OBJ)
	gcc -o singleton.exe $(SINGLE_OBJ)


PORTARRAY_OBJ = \
    gen/tCallArray_tecsgen.o \
    gen/tEntryArray_tecsgen.o \
    src/tCallArray_templ.o \
    src/tEntryArray_templ.o

portarray: $(PORTARRAY_OBJ) portarray.exe

gen/tCallArray_tecsgen.c gen/tEntryArray_tecsgen.c : portarray.cdl
	$(TECSGEN) portarray.cdl

portarray.exe : $(PORTARRAY_OBJ)
	gcc -o portarray.exe $(PORTARRAY_OBJ)

composite.1:
	cd composite; make tecs TECSGEN_EXE=$(TECSGEN_EXE)
	cd composite; make all

.PHONY: bool
bool :
	cd bool ; make tecs TECSGEN_EXE=$(TECSGEN_EXE)
	cd bool ; make all

.PHONY: recursive_composite
recursive_composite :
	cd recursive_composite ; make tecs TECSGEN_EXE=$(TECSGEN_EXE)
	cd recursive_composite ; make all

.PHONY: recursive_composite2
recursive_composite2 :
	cd recursive_composite2 ; make tecs TECSGEN_EXE=$(TECSGEN_EXE)
	cd recursive_composite2 ; make all

.PHONY: recursive_composite2_idx_is_id
recursive_composite2_idx_is_id :
	cd recursive_composite2_idx_is_id ; make tecs TECSGEN_EXE=$(TECSGEN_EXE)
	cd recursive_composite2_idx_is_id ; make all

.PHONY: recursive_composite3
recursive_composite3 :
	cd recursive_composite3 ; make TECSGEN_EXE=$(TECSGEN_EXE)

.PHONY: factory
factory : factory.cdl
	$(TECSGEN) factory.cdl

.PHONY : through
through :
	cd through ; make tecs TECSGEN_EXE=$(TECSGEN_EXE)
	cd through ; make all

import_C.1 :
	cd import_C ; make TECSGEN_EXE=$(TECSGEN_EXE)

# init について tA が他で作られるため、エラーとなる
#INIT_OBJ = \
#	gen/tA_tecsgen.o \
#	gen/tA_templ.o
#
#init :  $(INIT_OBJ)
#
#gen/tA_tecsgen.c : init.cdl
#	$(TECSGEN) init.cdl

init : gen/tA_tecsgen.o
gen/tA_tecsgen.c : init.cdl
	$(TECSGEN) init.cdl

id : id.cdl
	$(TECSGEN) -v id.cdl

attribute.1 : 
	cd attribute; make tecs TECSGEN_EXE=$(TECSGEN_EXE)
	cd attribute; make all

var.1 : 
	cd var; make tecs TECSGEN_EXE=$(TECSGEN_EXE)
	cd var; make all

.PHONY: region
region :
	cd region ; make TECSGEN_EXE=$(TECSGEN_EXE)

region2.1 :
	cd region2 ; make tecsgen TECSGEN_EXE=$(TECSGEN_EXE)
	cd region2 ; make all

allocator.1 :
	cd allocator ; make tecsgen TECSGEN_EXE=$(TECSGEN_EXE)
	cd allocator ; make all

allocator2.1 :
	cd allocator2 ; make tecs TECSGEN_EXE=$(TECSGEN_EXE)
	cd allocator2 ; make all

allocatorCB.1 :
	cd allocatorCB ; make tecs TECSGEN_EXE=$(TECSGEN_EXE)
	cd allocatorCB ; make all

romram.1 :
	cd romram ; make tecs TECSGEN_EXE=$(TECSGEN_EXE)
	cd romram ; make all

foreach.1 :
	cd foreach ; make tecsgen TECSGEN_EXE=$(TECSGEN_EXE)
	cd foreach ; make all

composite_alloc.1 :
	cd composite_alloc ; make tecs TECSGEN_EXE=$(TECSGEN_EXE)
	cd composite_alloc ; make all

composite_alloc3.1 :
	cd composite_alloc3 ; make tecs TECSGEN_EXE=$(TECSGEN_EXE)
	cd composite_alloc3 ; make all

.PHONY: require
require :
	cd require ; make tecs TECSGEN_EXE=$(TECSGEN_EXE)
	cd require ; make all

.PHONY: require2
require2 :
	cd require2 ; make tecs TECSGEN_EXE=$(TECSGEN_EXE)
	cd require2 ; make all

params.1 :
	cd params ; make tecs TECSGEN_EXE=$(TECSGEN_EXE)
	cd params ; make all

inline.1 :
	cd inline ; make tecs TECSGEN_EXE=$(TECSGEN_EXE)
	cd inline ; make all

hello.1 :
	cd hello ; make tecs TECSGEN_EXE=$(TECSGEN_EXE)
	cd hello ; make all

simple.1 :
	cd simple ; make tecs TECSGEN_EXE=$(TECSGEN_EXE)
	cd simple ; make all

opaqueRPC.1 :
	cd opaqueRPC ; make tecs TECSGEN_EXE=$(TECSGEN_EXE)
	cd opaqueRPC ; make all

.PHONY:opaqueMarshaler
opaqueMarshaler:
	cd opaqueMarshaler ; make tecs TECSGEN_EXE=$(TECSGEN_EXE)
	cd opaqueMarshaler ; make all

optimize.1 :
	cd optimize ; make tecs TECSGEN_EXE=$(TECSGEN_EXE)
	cd optimize ; make all

optional.1 :
	cd optional ; make tecs TECSGEN_EXE=$(TECSGEN_EXE)
	cd optional ; make all


.PHONY: series
series :
	cd series ; make tecs TECSGEN_EXE=$(TECSGEN_EXE)
	cd series ; make all

pointer.1 :
	cd pointer ; make tecs TECSGEN_EXE=$(TECSGEN_EXE)
	cd pointer ; make all

c_exp :
	$(TECSGEN_EXE) c_exp.cdl
	$(TECSGEN_EXE) composite_cexp.cdl

struct.2 :
	cd struct ; make tecs TECSGEN_EXE=$(TECSGEN_EXE)
	cd struct ; make all

struct.1 : gen/tCellStruct_tecsgen.c

gen/tCellStruct_tecsgen.c : struct.cdl
	$(TECSGEN) struct.cdl

.PHONY: const
const : gen/tIO_tecsgen.c

gen/tIO_tecsgen.c : const.cdl
	$(TECSGEN_N) const.cdl

.PHONY: float
float : gen/tFloat_tecsgen.c

gen/tFloat_tecsgen.c : float.cdl
	$(TECSGEN) float.cdl

BUG_TEST_OBJ = \
	gen/tBugTest_tecsgen.o \
	gen/tBugTest_templ.o \
	gen/tSingle_tecsgen.o \
	gen/tSingle_templ.o

bug_test :  $(BUG_TEST_OBJ)
gen/tBugTest_tecsgen.c : bug_test.cdl
	$(TECSGEN) bug_test.cdl

rpc.1 :
	cd rpc ; make tecs TECSGEN_EXE=$(TECSGEN_EXE)
	cd rpc ; make all

sharedRPC.1 :
	cd sharedRPC ; make tecs TECSGEN_EXE=$(TECSGEN_EXE)
	cd sharedRPC ; make all

sharedOpaqueRPC.1 :
	cd sharedOpaqueRPC ; make tecs TECSGEN_EXE=$(TECSGEN_EXE)
	cd sharedOpaqueRPC ; make all

dataqueue.1 :
	cd dataqueue ; make tecs TECSGEN_EXE=$(TECSGEN_EXE)
	cd dataqueue ; make all

.PHONY: signaturePlugin
signaturePlugin :
	cd signaturePlugin ; make tecs TECSGEN_EXE=$(TECSGEN_EXE)

.PHONY: celltypePlugin
celltypePlugin :
	cd celltypePlugin ; make tecs TECSGEN_EXE=$(TECSGEN_EXE)

.PHONY: cellPlugin
cellPlugin :
	cd cellPlugin ; make tecs TECSGEN_EXE=$(TECSGEN_EXE)

.PHONY: CPPBridge
CPPBridge :
	cd CPPBridge ; make tecs TECSGEN_EXE=$(TECSGEN_EXE)

.PHONY: reverse_require
reverse_require :
	cd reverse_require ; make tecs TECSGEN_EXE=$(TECSGEN_EXE)
	cd reverse_require ; make all

sjis.1 :
	cd sjis ; make  tecs "TECSGEN_EXE=$(TECSGEN_EXE) -k sjis"

merge.1 :
	cd merge ; make TECSGEN_EXE=$(TECSGEN_EXE) TECSMERGE_EXE=$(TECSMERGE_EXE)

.PHONY: namespace
namespace :
	cd namespace ; make tecs TECSGEN_EXE=$(TECSGEN_EXE)
	cd namespace ; make all

.PHONY: domainPlugin
domainPlugin :
	cd domainPlugin ; make TECSGEN_EXE=$(TECSGEN_EXE)

.PHONY: reverse_join
reverse_join :
	cd reverse_join ; make tecs TECSGEN_EXE=$(TECSGEN_EXE)
	cd reverse_join ; make all

.PHONY: proto
proto :
	cd proto ; make TECSGEN_EXE=$(TECSGEN_EXE)

.PHONY: cp_omit
cp_omit :
	cd cp_omit ; make TECSGEN=$(TECSGEN_EXE)

.PHONY: NotificationPlugin
NotificationPlugin :
	cd NotificationPlugin ; make tecs TECSGEN=$(TECSGEN_EXE)

.PHONY: restrict
restrict :
	cd restrict ; make TECSGEN=$(TECSGEN_EXE)

.PHONY: dynamic
dynamic :
	cd dynamic ; make TECSGEN=$(TECSGEN_EXE)

.c.o:
	gcc $(COPT) -o $@ $<
