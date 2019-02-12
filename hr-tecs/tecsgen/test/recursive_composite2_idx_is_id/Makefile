# このファイルは tecsgen により自動生成されました
# Makefile.temp は gen の一つ上のディレクトリに移して使用します
#  % mv Makefile.temp Makefile
# 
# clean のデフォルト動作は $(GEN_DIR)/Makefile.* を削除します

# 変数 #_MVAR_#
TARGET = recursive_composite.exe
TIMESTAMP = tecsgen.timestamp
TECSGEN_EXE = tecsgen
BASE_DIR = .
CC = gcc
CFLAGS = -I $(BASE_DIR)/. -I $(BASE_DIR)/../RUNTIME/runtime/test -I $(BASE_DIR)/../RUNTIME/runtime/include -I $(GEN_DIR) -D "Inline=static inline"
LD = gcc
LDFLAGS = 
GEN_DIR = $(BASE_DIR)/gen_rec_comp
SRC_DIR = $(BASE_DIR)/src_rec_comp
_TECS_OBJ_DIR = $(GEN_DIR)/
#   _TECS_OBJ_DIR   # should be end with '/'

vpath %.c $(SRC_DIR) $(GEN_DIR)  . ../RUNTIME/runtime/test ../RUNTIME/runtime/include
vpath %.h $(SRC_DIR) $(GEN_DIR)  . ../RUNTIME/runtime/test ../RUNTIME/runtime/include

OTHER_OBJS =                       # Add objects out of tecs care.

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
-include $(GEN_DIR)/Makefile.tecsgen
-include $(GEN_DIR)/Makefile.depend

$(TARGET) : $(TIMESTAMP) $(CELLTYPE_COBJS) $(TECSGEN_COBJS) $(PLUGIN_COBJS) $(OTHER_OBJS)
	$(LD) $(LDFLAGS) -o $(TARGET) $(TECSGEN_COBJS) $(CELLTYPE_COBJS) $(PLUGIN_COBJS) $(OTHER_OBJS)

clean :
	rm -f $(CELLTYPE_COBJS) $(TECSGEN_COBJS) $(PLUGIN_COBJS) $(OTHER_OBJS) $(TARGET)  $(TIMESTAMP)
	rm -rf $(GEN_DIR)

tecs : $(TIMESTAMP)

$(TIMESTAMP) : $(TECS_IMPORTS)
	$(TECSGEN_EXE)  -u -I../RUNTIME/runtime/test -I../RUNTIME/runtime/include --gen=gen_rec_comp recursive_composite.cdl
	touch $(TIMESTAMP)

# generic target for objs
$(_TECS_OBJ_DIR)%.o : %.c
	$(CC) -c $(CFLAGS) -o $@ $<

tCell1.o : tCell1.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
tCell2.o : tCell2.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
tCell3.o : tCell3.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
tCell4.o : tCell4.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
tCell_serv.o : tCell_serv.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
tCell_clnt.o : tCell_clnt.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
