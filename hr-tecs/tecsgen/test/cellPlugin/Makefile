# このファイルは tecsgen により自動生成されました
# Makefile.temp は gen の一つ上のディレクトリに移して使用します
#  % mv Makefile.temp Makefile
# 
# clean のデフォルト動作は $(GEN_DIR)/Makefile.* を削除します

# 変数 #_MVAR_#
TARGET = cellPlugin.exe
TIMESTAMP = tecsgen.timestamp
TECSGEN_EXE = tecsgen
BASE_DIR = 
CC = gcc
CFLAGS = -I $(BASE_DIR). -I $(BASE_DIR)../cygwin -I $(BASE_DIR)../../tecs -I $(GEN_DIR)
LD = gcc
LDFLAGS = 
GEN_DIR = $(BASE_DIR)gen
SRC_DIR = $(BASE_DIR)src
OTHER_OBJS =                       # Add objects out of tecs care.

vpath %.c $(SRC_DIR) $(GEN_DIR)
vpath %.h $(SRC_DIR) $(GEN_DIR)

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
	$(TECSGEN_EXE) -L . -I ../cygwin/ -I ../../tecs cellPlugin.cdl
	touch $(TIMESTAMP)

tCelltype.o : tCelltype.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
tCelltype2.o : tCelltype2.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
tCelltype3.o : tCelltype3.c
	$(CC) -c $(CFLAGS) -o $@ $<
 
