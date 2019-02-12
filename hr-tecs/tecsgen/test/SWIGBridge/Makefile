# 変数 #_MVAR_#
TARGET = SWIGBridge.so
TIMESTAMP = tecsgen.timestamp
TECSGEN_EXE = tecsgen
CC = gcc
CXXC = gcc
CFLAGS = -I . -I ../cygwin -I ../../tecs -I gen
LD = gcc
LDFLAGS = -shared
LIBS =  -l ruby -l stdc++
GEN_DIR = gen
SRC_DIR = src
ADDITIONAL_COBJS = CsTest.o SWIGBridge_wrap.o

vpath %.c $(SRC_DIR) $(GEN_DIR)

vpath %.h $(SRC_DIR) $(GEN_DIR)

vpath %.cxx  $(GEN_DIR)

# ルール #_MRUL_#
no_target :
	@echo "no target specified"
	@echo "at first or when edit .cdl files, do below"
	@echo "% make tecs"
	@echo "at second, do below"
	@echo "% make all"
	@echo "to clean"
	@echo "% make clean"

all : $(TARGET) 


# depend を include #_MDEP_#
-include gen/Makefile.tecsgen
-include gen/Makefile.depend

$(TARGET) : $(TIMESTAMP) $(CELLTYPE_COBJS) $(TECSGEN_COBJS) $(PLUGIN_COBJS) $(ADDITIONAL_COBJS)
	$(LD) $(LDFLAGS) -o $(TARGET) $(TECSGEN_COBJS) $(CELLTYPE_COBJS) $(PLUGIN_COBJS) $(ADDITIONAL_COBJS) $(LIBS)


clean :
	rm -rf $(GEN_DIR)
	rm -f $(TECS_COBJS) $(ADDITIONAL_COBJS)
	rm -f $(TARGET)
	rm -f $(TIMESTAMP)

tecs : $(TIMESTAMP)

$(TIMESTAMP) : $(TECS_IMPORTS)
	$(TECSGEN_EXE) -L . -I ../cygwin -I ../../tecs generate.cdl
	touch $(TIMESTAMP)

CsTest.o : CsTest.cxx
	$(CXXC) -c $(CFLAGS) -o $@ $<

SWIGBridge_wrap.o : $(GEN_DIR)/SWIGBridge_wrap.cxx
	$(CXXC) -D SWIG -c $(CFLAGS) -I /usr/lib/ruby/1.8/i386-cygwin -o $@ $<

$(GEN_DIR)/SWIGBridge_wrap.cxx : $(GEN_DIR)/SWIGBridge.i
	swig -c++ -ruby -I/usr/include $(GEN_DIR)/SWIGBridge.i
