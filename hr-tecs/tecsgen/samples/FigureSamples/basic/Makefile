#CYGPATH=../../cygwin
CYGPATH=$(TECSPATH)/../../test/cygwin
TARGET_BASE = SimpleSample
BASE_DIR = .
GEN_DIR = $(BASE_DIR)/gen
INCLUDES = -I $(BASE_DIR)/. -I $(BASE_DIR)/src -I $(BASE_DIR)/gen -I $(CYGPATH) -I $(TECSPATH) -I $(TECSPATH)/mruby -I $(TECSPATH)/posix -I $(TECSPATH)/rpc -I $(GEN_DIR)
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
vpath %.c $(SRC_DIR) $(GEN_DIR)  src gen $(CYGPATH) $(TECSPATH) $(TECSPATH)/mruby $(TECSPATH)/posix $(TECSPATH)/rpc
vpath %.h $(SRC_DIR) $(GEN_DIR)  src gen $(CYGPATH) $(TECSPATH) $(TECSPATH)/mruby $(TECSPATH)/posix $(TECSPATH)/rpc

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

$(TARGET) : $(TIMESTAMP) $(CELLTYPE_COBJS) $(TECSGEN_COBJS) $(PLUGIN_COBJS) $(OTHER_OBJS)
	$(LD) -o $(TARGET) $(TECSGEN_COBJS) $(CELLTYPE_COBJS) $(PLUGIN_COBJS) $(OTHER_OBJS) $(LDFLAGS)
clean :
	rm -f $(CELLTYPE_COBJS) $(TECSGEN_COBJS) $(PLUGIN_COBJS) $(OTHER_OBJS) $(TARGET)  $(TIMESTAMP)
	rm -rf $(GEN_DIR)

tecs : $(PRE_TECSGEN_TARGET) $(TIMESTAMP) $(POST_TECSGEN_TARGET)

$(TIMESTAMP) : $(TECS_IMPORTS)
	$(TECSGEN_EXE)  -k euc -I src -I gen -I $(CYGPATH) -I $(TECSPATH) SimpleSample.cdl
	touch $(TIMESTAMP)

# generic target for objs
$(_TECS_OBJ_DIR)%.o : %.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(_TECS_OBJ_DIR)tTask.o : tTask.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
$(_TECS_OBJ_DIR)tSample.o : tSample.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
$(_TECS_OBJ_DIR)tSimple.o : tSimple.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
