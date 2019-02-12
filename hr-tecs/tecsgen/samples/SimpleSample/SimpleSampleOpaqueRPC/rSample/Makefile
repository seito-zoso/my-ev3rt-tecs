# ¤³¤Î¥Õ¥¡¥¤¥ë¤Ï tecsgen ¤Ë¤è¤ê¼«Æ°À¸À®¤µ¤ì¤Þ¤·¤¿
# Makefile.temp ¤Ï gen ¤Î°ì¤Ä¾å¤Î¥Ç¥£¥ì¥¯¥È¥ê¤Ë°Ü¤·¤Æ»ÈÍÑ¤·¤Þ¤¹
#  % mv Makefile.temp Makefile
# 
# clean ¤Î¥Ç¥Õ¥©¥ë¥ÈÆ°ºî¤Ï $(GEN_DIR)/Makefile.* ¤òºï½ü¤·¤Þ¤¹
#
# ¤³¤Î¥Õ¥¡¥¤¥ë¤Ï GNU make ¤Ç gcc ¤òÍÑ¤¤ POSIX ´Ä¶­¤ÇÆ°ºî¤¹¤ë¥â¥¸¥å¡¼¥ë¤ò¥Ó¥ë¥É¤¹¤ë¤Î¤ËÅ¬ÀÚ¤Ê¤è¤¦¤ËÀ¸À®¤µ¤ì¤Æ¤¤¤Þ¤¹
# vpath, CFLAGS, OTHER_OBJS ¤Ê¤É¤òÄ´À°¤¹¤ëÉ¬Í×¤¬¤¢¤ë¤«¤â¤·¤ì¤Þ¤»¤ó
# Â¾¤Î´Ä¶­¤ä¥¿¡¼¥²¥Ã¥È¤Î¾ì¹ç¡¢¤³¤Î¥Õ¥¡¥¤¥ë¤ò¸µ¤ËÊÑ¹¹¤¹¤ëÉ¬Í×¤¬¤¢¤ê¤Þ¤¹

# ÊÑ¿ô #_MVAR_#
# fixed variable (unchangeable by config or plugin)
TARGET_BASE = SimpleSample-rSample
BASE_DIR = ..
GEN_DIR = $(BASE_DIR)/gen/rSample
INCLUDES = -I $(BASE_DIR)/. -I $(BASE_DIR)/./. -I $(TECSPATH) -I $(BASE_DIR)/../../cygwin -I $(TECSPATH)/rpc -I $(BASE_DIR)/./gen -I $(BASE_DIR)/src -I $(TECSPATH)/mruby -I $(TECSPATH)/mruby-bak2 -I $(TECSPATH)/mruby.org -I $(TECSPATH)/posix -I $(GEN_DIR)
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

#default source directory
SRC_DIR = $(BASE_DIR)/src

#default target name
TARGET = $(TARGET_BASE).exe

#default TECS generator
TECSGEN = tecsgen

#Time Stamp
TIMESTAMP = $(GEN_DIR)/tecsgen.timestamp

#default relocatable object (.o) directory
_TECS_OBJ_DIR = $(GEN_DIR)/



# Pre-tecsgen target
PRE_TECSGEN_TARGET =

# Post-tecsgen target
POST_TECSGEN_TARGET =

# vpath for C sources and headers
vpath %.c $(SRC_DIR) $(GEN_DIR)  .././. $(TECSPATH) ../../../cygwin $(TECSPATH)/rpc .././gen ../src $(TECSPATH)/mruby $(TECSPATH)/mruby-bak2 $(TECSPATH)/mruby.org $(TECSPATH)/posix
vpath %.h $(SRC_DIR) $(GEN_DIR)  .././. $(TECSPATH) ../../../cygwin $(TECSPATH)/rpc .././gen ../src $(TECSPATH)/mruby $(TECSPATH)/mruby-bak2 $(TECSPATH)/mruby.org $(TECSPATH)/posix

# Other objects (out of tecsgen)
OTHER_OBJS =                      # Add objects out of tecs care.
# OTHER_OBJS = $(_TECS_OBJ_DIR)vasyslog.o
# ¥ë¡¼¥ë #_MRUL_#
allall: tecs
	make all     # in order to include generated Makefile.tecsgen & Makefile.depend

all : $(TARGET)


# depend ¤ò include #_MDEP_#
-include $(GEN_DIR)/Makefile.tecsgen
-include $(GEN_DIR)/Makefile.depend

$(TARGET) : $(CELLTYPE_COBJS) $(TECSGEN_COBJS) $(PLUGIN_COBJS) $(OTHER_OBJS)
	$(LD) -o $(TARGET) $(TECSGEN_COBJS) $(CELLTYPE_COBJS) $(PLUGIN_COBJS) $(OTHER_OBJS) $(LDFLAGS)

clean :
	rm -f $(CELLTYPE_COBJS) $(TECSGEN_COBJS) $(PLUGIN_COBJS) $(OTHER_OBJS) $(TARGET) 

tecs:
	@echo "run 'make tecs' in root region"

# generic target for objs
$(_TECS_OBJ_DIR)%.o : %.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(_TECS_OBJ_DIR)tTask.o : tTask.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
$(_TECS_OBJ_DIR)tKernel.o : tKernel.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
$(_TECS_OBJ_DIR)tSysLog.o : tSysLog.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
$(_TECS_OBJ_DIR)tNBOTDR.o : tNBOTDR.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
$(_TECS_OBJ_DIR)tRPCDedicatedTaskMainWithOpener.o : tRPCDedicatedTaskMainWithOpener.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
$(_TECS_OBJ_DIR)tPPAllocator.o : tPPAllocator.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
$(_TECS_OBJ_DIR)tSocketServer.o : tSocketServer.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
$(_TECS_OBJ_DIR)tSample.o : tSample.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
$(_TECS_OBJ_DIR)tOpaqueUnmarshaler_sSample.o : tOpaqueUnmarshaler_sSample.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
