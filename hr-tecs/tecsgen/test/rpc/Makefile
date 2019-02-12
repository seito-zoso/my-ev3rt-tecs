# 変数 #_MVAR_#
TARGET = rpc_test.exe
TIMESTAMP = gen/tecsgen.timestamp
TECSGEN_EXE = tecsgen
BASE_DIR = .
CC = gcc
CFLAGS = -I $(BASE_DIR)/. -I $(BASE_DIR)/../cygwin -I $(TECSPATH) -I $(TECSPATH)/mruby -I $(TECSPATH)/rpc -I $(TECSPATH)/TECSInfo -I $(BASE_DIR)/rpc -I $(GEN_DIR) -D "Inline=static inline"
LD = gcc
LDFLAGS = -lpthread
GEN_DIR = $(BASE_DIR)/gen
SRC_DIR = $(BASE_DIR)/src
_TECS_OBJ_DIR = $(GEN_DIR)/
#   _TECS_OBJ_DIR   # should end with '/'

vpath %.c $(SRC_DIR) $(GEN_DIR)  ../cygwin $(TECSPATH) $(TECSPATH)/mruby $(TECSPATH)/rpc $(TECSPATH)/TECSInfo
vpath %.h $(SRC_DIR) $(GEN_DIR)  ../cygwin $(TECSPATH) $(TECSPATH)/mruby $(TECSPATH)/rpc $(TECSPATH)/TECSInfo

# OTHER_OBJS =                       # Add objects out of tecs care.
OTHER_OBJS = $(_TECS_OBJ_DIR)vasyslog.o

# ルール #_MRUL_#
allall: tecs
	make all     # in order to include generated Makefile.tecsgen & Makefile.depend

all : $(TARGET)


# depend を include #_MDEP_#
-include $(GEN_DIR)/Makefile.tecsgen
-include $(GEN_DIR)/Makefile.depend

$(TARGET) : $(TIMESTAMP) $(CELLTYPE_COBJS) $(TECSGEN_COBJS) $(PLUGIN_COBJS) $(OTHER_OBJS)
	$(LD) -o $(TARGET) $(TECSGEN_COBJS) $(CELLTYPE_COBJS) $(PLUGIN_COBJS) $(OTHER_OBJS) $(LDFLAGS)
clean :
	rm -f $(CELLTYPE_COBJS) $(TECSGEN_COBJS) $(PLUGIN_COBJS) $(OTHER_OBJS) $(TARGET)  $(TIMESTAMP)
	rm -rf $(GEN_DIR)

tecs : $(TIMESTAMP)

$(TIMESTAMP) : $(TECS_IMPORTS)
	$(TECSGEN_EXE) -I ../../tecs -I ../../tecs/rpc -I ../cygwin rpc_test.cdl

# generic target for objs
$(_TECS_OBJ_DIR)%.o : %.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(_TECS_OBJ_DIR)tTask.o : tTask.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
$(_TECS_OBJ_DIR)tKernel.o : tKernel.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
$(_TECS_OBJ_DIR)tSemaphore.o : tSemaphore.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
$(_TECS_OBJ_DIR)tEventflag.o : tEventflag.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
$(_TECS_OBJ_DIR)tDataqueuePeer.o : tDataqueuePeer.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
$(_TECS_OBJ_DIR)tSysLog.o : tSysLog.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
$(_TECS_OBJ_DIR)tTDR.o : tTDR.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
$(_TECS_OBJ_DIR)tRPCDedicatedTaskMain.o : tRPCDedicatedTaskMain.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
$(_TECS_OBJ_DIR)tPPAllocator.o : tPPAllocator.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
$(_TECS_OBJ_DIR)tDataqueueAdaptor.o : tDataqueueAdaptor.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
$(_TECS_OBJ_DIR)tAlloc.o : tAlloc.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
$(_TECS_OBJ_DIR)tSample.o : tSample.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
$(_TECS_OBJ_DIR)tSimple.o : tSimple.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
$(_TECS_OBJ_DIR)tTracePlugin_sSample.o : tTracePlugin_sSample.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
$(_TECS_OBJ_DIR)tTracePlugin_sSimple.o : tTracePlugin_sSimple.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
$(_TECS_OBJ_DIR)tMarshaler_sSimple.o : tMarshaler_sSimple.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
$(_TECS_OBJ_DIR)tUnmarshaler_sSimple.o : tUnmarshaler_sSimple.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
$(_TECS_OBJ_DIR)tMarshaler_sSample.o : tMarshaler_sSample.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
$(_TECS_OBJ_DIR)tUnmarshaler_sSample.o : tUnmarshaler_sSample.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
