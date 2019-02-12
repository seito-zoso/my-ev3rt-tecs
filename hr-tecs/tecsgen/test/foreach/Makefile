# このファイルは tecsgen により自動生成されました
# Makefile.temp は gen の一つ上のディレクトリに移して使用します
#  % mv Makefile.temp Makefile
# 
# clean のデフォルト動作は $(GEN_DIR)/Makefile.* を削除します

# 変数 #_MVAR_#
TARGET = foreach.exe
TECSGEN_EXE = tecsgen
CC = gcc
CFLAGS = -I . -I ../RUNTIME/tecs-runtime/include -I ../RUNTIME/tecs-runtime/target -I ../RUNTIME/tecs-runtime/workaround -I gen -I src -I gen
LD = gcc
LDFLAGS = 
GEN_DIR = gen
SRC_DIR = src
vpath %.c $(SRC_DIR) $(GEN_DIR)

# ルール #_MRUL_#
no_target :
	@echo "no target specified"
	@echo "at first or when edit .cdl files, do below"
	@echo "% make tecsgen"
	@echo "at second, do below"
	@echo "% make all"
	@echo "to clean"
	@echo "% make clean"

all : $(TARGET) 


# depend を include #_MDEP_#
-include gen/Makefile.tecsgen
-include gen/Makefile.depend

$(TARGET) : tecsgen.timestamp $(CELLTYPE_COBJS) $(TECSGEN_COBJS) $(PLUGIN_COBJS)
	$(LD) $(LDFLGAS) -o $(TARGET) $(TECSGEN_COBJS) $(CELLTYPE_COBJS) $(PLUGIN_COBJS)

# For temporal construction using template code.
TEMPL_COBJS = \
 	$(GEN_DIR)/tCt2_templ.o \
 	$(GEN_DIR)/tCt1_templ.o \
# TEMPL_COBJS terminater

TEMPL_SRCS = \
 	$(GEN_DIR)/tCt2_templ.c \
 	$(GEN_DIR)/tCt1_templ.c \
# TEMPL_SRCS terminater

# テンプレートコードでメークしてみる場合 #_TCM_#
# $(TARGET) : tecsgen.timestamp $(TECSGEN_COBJS) $(TEMPL_COBJS) $(PLUGIN_COBJS)
#	$(LD) $(LDFLGAS) -o $(TARGET) $(TECSGEN_COBJS) $(TEMPL_COBJS) $(PLUGIN_COBJS)

clean :
	rm -rf $(GEN_DIR)
	rm -f $(TECS_COBJS)
	rm -f $(TARGET)
	rm -f tecsgen.timestamp

tecsgen : tecsgen.timestamp

tecsgen.timestamp : $(TECS_IMPORTS)
	$(TECSGEN_EXE) -I../RUNTIME/tecs-runtime/include -I../RUNTIME/tecs-runtime/target -I../RUNTIME/tecs-runtime/workaround -Igen -Isrc foreach.cdl
	touch tecsgen.timestamp

# Celltype: tCt2
$(GEN_DIR)/tCt2_tecsgen.o : $(GEN_DIR)/tCt2_tecsgen.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(GEN_DIR)/tCt2_templ.o : $(GEN_DIR)/tCt2_templ.c
	$(CC) -c $(CFLAGS) -o $@ $<

tCt2.o : tCt2.c
	$(CC) -c $(CFLAGS) -o $@ $<

# Celltype: tCt1
$(GEN_DIR)/tCt1_tecsgen.o : $(GEN_DIR)/tCt1_tecsgen.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(GEN_DIR)/tCt1_templ.o : $(GEN_DIR)/tCt1_templ.c
	$(CC) -c $(CFLAGS) -o $@ $<

tCt1.o : tCt1.c
	$(CC) -c $(CFLAGS) -o $@ $<

