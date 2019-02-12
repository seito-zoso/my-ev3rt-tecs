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
# fixed variable (unchangeable by config or plugin)
TARGET_BASE = SimpleSample
BASE_DIR = .
CYGPATH = ../../cygwin
GEN_DIR = $(BASE_DIR)/gen
INCLUDES = -I $(BASE_DIR)/. -I $(BASE_DIR)/./. -I $(TECSPATH) -I $(CYGPATH) -I $(TECSPATH)/rpc -I $(BASE_DIR)/./gen -I $(TECSPATH)/mruby -I $(TECSPATH)/posix -I $(GEN_DIR)
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
vpath %.c $(SRC_DIR) $(GEN_DIR)  $(TECSPATH) $(CYGPATH) $(TECSPATH)/rpc ./gen $(TECSPATH)/mruby $(TECSPATH)/posix
vpath %.h $(SRC_DIR) $(GEN_DIR)  $(TECSPATH) $(CYGPATH) $(TECSPATH)/rpc ./gen $(TECSPATH)/mruby $(TECSPATH)/posix

# Other objects (out of tecsgen)
OTHER_OBJS =                      # Add objects out of tecs care.
# OTHER_OBJS = $(_TECS_OBJ_DIR)vasyslog.o
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

tecs : $(PRE_TECSGEN_TARGET) $(TIMESTAMP) $(POST_TECSGEN_TARGET)

$(TIMESTAMP) : $(TECS_IMPORTS)
	$(TECSGEN_EXE)  -I ./. -I $(TECSPATH) -I $(CYGPATH) -I $(TECSPATH)/rpc -I ./gen SimpleSample.cdl
	touch $(TIMESTAMP)

# generic target for objs
$(_TECS_OBJ_DIR)%.o : %.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(_TECS_OBJ_DIR)tTask.o : tTask.c
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
 
$(_TECS_OBJ_DIR)tDataqueueAdaptor.o : tDataqueueAdaptor.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
$(_TECS_OBJ_DIR)tSample.o : tSample.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
$(_TECS_OBJ_DIR)tSimple.o : tSimple.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
$(_TECS_OBJ_DIR)tMarshaler_sSample.o : tMarshaler_sSample.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
$(_TECS_OBJ_DIR)tUnmarshaler_sSample.o : tUnmarshaler_sSample.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
