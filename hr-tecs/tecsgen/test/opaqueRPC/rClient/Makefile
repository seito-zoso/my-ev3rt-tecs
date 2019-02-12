# 変数 #_MVAR_#
# fixed variable (unchangeable by config or plugin)
TARGET_BASE = opaqueRPC-rClient
BASE_DIR = ..
GEN_DIR = $(BASE_DIR)/gen/rClient
INCLUDES = -I $(BASE_DIR)/. -I $(BASE_DIR)/../cygwin -I $(BASE_DIR)/../../tecs -I $(BASE_DIR)/../../tecs/rpc -I $(TECSPATH) -I $(TECSPATH)/mruby -I $(TECSPATH)/posix -I $(TECSPATH)/rpc -I $(TECSPATH)/TECSInfo -I $(GEN_DIR)
DEFINES =

# end of fixed variable (unchangeable by config or plugin)
#default C Compiler
CC = gcc

#default C Compiler options
CFLAGS = $(INCLUDES) $(DEFINES) -D  "Inline=static inline"

#default Liknker
LD = gcc

#default Liknker Options
LDFLAGS = -lpthread

#default srource directory
SRC_DIR = $(BASE_DIR)/src

#default target name
TARGET = $(TARGET_BASE).exe

#default TECS generator
TECSGEN_EXE = tecsgen

#Time Stamp
TIMESTAMP = tecsgen.timestamp

#default relocatable object (.o) directory
_TECS_OBJ_DIR = $(GEN_DIR)/



# Pre-tecsgen target
PRE_TECSGEN_TARGET =

# Post-tecsgen target
POST_TECSGEN_TARGET =

# vpath for C sources and headers
vpath %.c $(SRC_DIR) $(GEN_DIR)  ../../cygwin ../../../tecs ../../../tecs/rpc $(TECSPATH) $(TECSPATH)/mruby $(TECSPATH)/posix $(TECSPATH)/rpc $(TECSPATH)/TECSInfo
vpath %.h $(SRC_DIR) $(GEN_DIR)  ../../cygwin ../../../tecs ../../../tecs/rpc $(TECSPATH) $(TECSPATH)/mruby $(TECSPATH)/posix $(TECSPATH)/rpc $(TECSPATH)/TECSInfo

# Other objects (out of tecsgen)
# OTHER_OBJS =                      # Add objects out of tecs care.
OTHER_OBJS = $(_TECS_OBJ_DIR)vasyslog.o
# ルール #_MRUL_#
allall: tecs
	make all     # in order to include generated Makefile.tecsgen & Makefile.depend

all : $(TARGET)


# depend を include #_MDEP_#
-include $(GEN_DIR)/Makefile.tecsgen
-include $(GEN_DIR)/Makefile.depend

$(TARGET) : $(TECSGEN_COBJS) $(PLUGIN_COBJS) $(OTHER_OBJS) $(CELLTYPE_COBJS)
	$(LD) -o $(TARGET) $(TECSGEN_COBJS) $(CELLTYPE_COBJS) $(PLUGIN_COBJS) $(OTHER_OBJS) $(LDFLAGS)
clean :
	rm -f $(CELLTYPE_COBJS) $(TECSGEN_COBJS) $(PLUGIN_COBJS) $(OTHER_OBJS) $(TARGET) 

tecs:
	@echo "run 'make tecs' in root region"

# generic target for objs
$(_TECS_OBJ_DIR)%.o : %.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(_TECS_OBJ_DIR)tSysLog.o : tSysLog.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(_TECS_OBJ_DIR)tTask.o : tTask.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(_TECS_OBJ_DIR)tKernel.o : tKernel.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(_TECS_OBJ_DIR)tSemaphore.o : tSemaphore.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(_TECS_OBJ_DIR)tNBOTDR.o : tNBOTDR.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(_TECS_OBJ_DIR)tSocketClient.o : tSocketClient.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(_TECS_OBJ_DIR)tAlloc.o : tAlloc.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(_TECS_OBJ_DIR)tSimpleClient.o : tSimpleClient.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(_TECS_OBJ_DIR)tClientRPCErrorHandler.o : tClientRPCErrorHandler.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(_TECS_OBJ_DIR)tTracePlugin_sSimple.o : tTracePlugin_sSimple.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(_TECS_OBJ_DIR)tOpaqueMarshaler_sSimple.o : tOpaqueMarshaler_sSimple.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(_TECS_OBJ_DIR)vasyslog.o : vasyslog.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(_TECS_OBJ_DIR)nTECSInfo_tNamespaceInfo.o : nTECSInfo_tNamespaceInfo.c
	$(CC) -c $(CFLAGS) -o $@ $<
