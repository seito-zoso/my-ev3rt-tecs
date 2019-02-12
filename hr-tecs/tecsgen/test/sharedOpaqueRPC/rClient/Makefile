# このファイルは tecsgen により自動生成されました
# Makefile.temp は gen の一つ上のディレクトリに移して使用します
#  % mv Makefile.temp Makefile
# 
# clean のデフォルト動作は $(GEN_DIR)/Makefile.* を削除します
#
# このファイルは GNU make で gcc を用い POSIX 環境で動作するモジュールをビルドするのに適切なように生成されています
# vpath, CFLAGS, OTHER_OBJS などを調整する必要があるかもしれません
# 他の環境やターゲットの場合、このファイルを元に変更する必要があります

# 変数 #_MVAR_#
TARGET = opaqueRPC-rClient.exe
TIMESTAMP = tecsgen.timestamp
TECSGEN_EXE = tecsgen
BASE_DIR = ..
CC = gcc
CFLAGS = -g -I $(BASE_DIR)/. -I $(BASE_DIR)/.. -I $(BASE_DIR)/../cygwin -I $(TECSPATH) -I $(TECSPATH)/mruby -I $(TECSPATH)/rpc -I $(BASE_DIR)/rpc -I $(GEN_DIR) -D __extension__= -D "Inline=static inline" -Werror-implicit-function-declaration
LD = gcc
LDFLAGS = -lpthread
GEN_DIR = $(BASE_DIR)/gen/rClient
SRC_DIR = $(BASE_DIR)/src
_TECS_OBJ_DIR = $(GEN_DIR)/
#   _TECS_OBJ_DIR   # should end with '/'

vpath %.c $(SRC_DIR) $(GEN_DIR)  ../.. ../../cygwin $(TECSPATH) $(TECSPATH)/mruby $(TECSPATH)/rpc ../rpc
vpath %.h $(SRC_DIR) $(GEN_DIR)  ../.. ../../cygwin $(TECSPATH) $(TECSPATH)/mruby $(TECSPATH)/rpc ../rpc

# OTHER_OBJS =                       # Add objects out of tecs care.
OTHER_OBJS = $(_TECS_OBJ_DIR)vasyslog.o

# ルール #_MRUL_#
allall: tecs
	make all     # in order to include generated Makefile.tecsgen & Makefile.depend

all : $(TARGET)


# depend を include #_MDEP_#
-include $(GEN_DIR)/Makefile.tecsgen
-include $(GEN_DIR)/Makefile.depend

$(TARGET) : $(CELLTYPE_COBJS) $(TECSGEN_COBJS) $(PLUGIN_COBJS) $(OTHER_OBJS)
	$(LD) -o $(TARGET) $(TECSGEN_COBJS) $(CELLTYPE_COBJS) $(PLUGIN_COBJS) $(OTHER_OBJS) $(LDFLAGS)
clean :
	rm -f $(CELLTYPE_COBJS) $(TECSGEN_COBJS) $(PLUGIN_COBJS) $(OTHER_OBJS) $(TARGET) 

tecs:
	@echo "run 'make tecs' in root region"

$(_TECS_OBJ_DIR)tSysLog.o : tSysLog.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
$(_TECS_OBJ_DIR)tTask.o : tTask.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
$(_TECS_OBJ_DIR)tKernel.o : tKernel.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
$(_TECS_OBJ_DIR)tSemaphore.o : tSemaphore.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
$(_TECS_OBJ_DIR)tTDR.o : tTDR.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
$(_TECS_OBJ_DIR)tRPCSharedChannelMan.o : tRPCSharedChannelMan.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
$(_TECS_OBJ_DIR)tSocketClient.o : tSocketClient.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
$(_TECS_OBJ_DIR)tAlloc.o : tAlloc.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
$(_TECS_OBJ_DIR)tSimpleClient.o : tSimpleClient.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
$(_TECS_OBJ_DIR)tSampleClient.o : tSampleClient.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
$(_TECS_OBJ_DIR)tOpaqueMarshaler_sSample.o : tOpaqueMarshaler_sSample.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
$(_TECS_OBJ_DIR)tTracePlugin_sSimple.o : tTracePlugin_sSimple.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
$(_TECS_OBJ_DIR)tOpaqueMarshaler_sSimple.o : tOpaqueMarshaler_sSimple.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
$(_TECS_OBJ_DIR)tTracePlugin_sSocketClientOpener.o : tTracePlugin_sSocketClientOpener.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
$(_TECS_OBJ_DIR)tTracePlugin_sAlloc.o : tTracePlugin_sAlloc.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
$(_TECS_OBJ_DIR)tTracePlugin_sSysLog.o : tTracePlugin_sSysLog.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
$(_TECS_OBJ_DIR)vasyslog.o : vasyslog.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
