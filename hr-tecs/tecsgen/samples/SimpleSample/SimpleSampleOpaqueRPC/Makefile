TARGET = SimpleSample.exe
TIMESTAMP = tecsgen.timestamp
TECSGEN_EXE = tecsgen
CYGPATH = ../../cygwin
BASE_DIR = .
CC = gcc
INCLUDE = -I $(BASE_DIR)/. -I $(TECSPATH) -I $(CYGPATH) -I $(TECSPATH)/rpc -I $(GEN_DIR)
CFLAGS = $(INCLUDE) -I $(BASE_DIR)/src -I $(GEN_DIR) -D "Inline=static inline"
LD = gcc
LDFLAGS = 
GEN_DIR = $(BASE_DIR)/gen
SRC_DIR = $(BASE_DIR)/src
_TECS_OBJ_DIR = $(GEN_DIR)/
#   _TECS_OBJ_DIR   # should be end with '/'

vpath %.c $(SRC_DIR) $(GEN_DIR) $(TECSPATH) $(TECSPATH)/rpc $(CYGPATH)
vpath %.h $(SRC_DIR) $(GEN_DIR) $(TECSPATH) $(TECSPATH)/rpc $(CYGPATH)

# OTHER_OBJS =                       # Add objects out of tecs care.
OTHER_OBJS = $(_TECS_OBJ_DIR)vasyslog.o

# ルール #_MRUL_#
allall: tecs
	make all     # in order to include generated Makefile.tecsgen & Makefile.depend

all :  sub_regions


# depend を include #_MDEP_#
-include $(GEN_DIR)/Makefile.tecsgen

sub_regions:$(TIMESTAMP)
	cd rSample; make all
	cd rSimple; make all

clean :
	cd rSample; make clean
	cd rSimple; make clean
	rm -f $(CELLTYPE_COBJS) $(TECSGEN_COBJS) $(PLUGIN_COBJS) $(OTHER_OBJS) $(TARGET)  $(TIMESTAMP)
	rm -rf $(GEN_DIR)

tecs : $(TIMESTAMP)

$(TIMESTAMP) : $(TECS_IMPORTS)
	$(TECSGEN_EXE) $(INCLUDE) -k euc -I src SimpleSample.cdl
	touch $(TIMESTAMP)

# generic target for objs
$(_TECS_OBJ_DIR)%.o : %.c
	$(CC) -c $(CFLAGS) -o $@ $<

