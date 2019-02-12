# このファイルは tecsgen により自動生成されました
# Makefile.temp は gen の一つ上のディレクトリに移して使用します
#  % mv Makefile.temp Makefile
# 
# clean のデフォルト動作は $(GEN_DIR)/Makefile.* を削除します

# 変数 #_MVAR_#
TARGET = allocator.exe
TECSGEN_EXE = tecsgen
CC = gcc
CFLAGS = -I . -I ../RUNTIME/tecs-runtime/target -I ../RUNTIME/tecs-runtime/include -I gen -I src -I gen -Werror-implicit-function-declaration
LD = gcc
LDFLAGS = 
GEN_DIR = gen
SRC_DIR = src
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
-include gen/Makefile.tecsgen
-include gen/Makefile.depend

$(TARGET) : tecsgen.timestamp $(CELLTYPE_COBJS) $(TECSGEN_COBJS) $(PLUGIN_COBJS)
	$(LD) $(LDFLGAS) -o $(TARGET) $(TECSGEN_COBJS) $(CELLTYPE_COBJS) $(PLUGIN_COBJS)

# For temporal construction using template code.
TEMPL_COBJS = \
 	$(GEN_DIR)/tAlloc_templ.o \
 	$(GEN_DIR)/tThroughComponent_templ.o \
 	$(GEN_DIR)/tTargetComponent_templ.o \
 	$(GEN_DIR)/tTestClient_templ.o \
# TEMPL_COBJS terminater

TEMPL_SRCS = \
 	$(GEN_DIR)/tAlloc_templ.c \
 	$(GEN_DIR)/tThroughComponent_templ.c \
 	$(GEN_DIR)/tTargetComponent_templ.c \
 	$(GEN_DIR)/tTestClient_templ.c \
# TEMPL_SRCS terminater

# テンプレートコードでメークしてみる場合 #_TCM_#
# $(TARGET) : tecsgen.timestamp $(TECSGEN_COBJS) $(TEMPL_COBJS) $(PLUGIN_COBJS)
#	$(LD) $(LDFLGAS) -o $(TARGET) $(TECSGEN_COBJS) $(TEMPL_COBJS) $(PLUGIN_COBJS)

clean :
	rm -rf $(GEN_DIR)
	rm -f $(TECS_COBJS)
	rm -f $(TARGET)
	rm -f tecsgen.timestamp

tecs : tecsgen.timestamp

tecsgen.timestamp : $(TECS_IMPORTS)
	$(TECSGEN_EXE)  -r -I../RUNTIME/tecs-runtime/target -I../RUNTIME/tecs-runtime/include -Igen -Isrc allocator.cdl
	touch tecsgen.timestamp

# Celltype: tAlloc
$(GEN_DIR)/tAlloc_tecsgen.o : $(GEN_DIR)/tAlloc_tecsgen.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(GEN_DIR)/tAlloc_templ.o : $(GEN_DIR)/tAlloc_templ.c
	$(CC) -c $(CFLAGS) -o $@ $<

tAlloc.o : tAlloc.c
	$(CC) -c $(CFLAGS) -o $@ $<

# Celltype: tThroughComponent
$(GEN_DIR)/tThroughComponent_tecsgen.o : $(GEN_DIR)/tThroughComponent_tecsgen.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(GEN_DIR)/tThroughComponent_templ.o : $(GEN_DIR)/tThroughComponent_templ.c
	$(CC) -c $(CFLAGS) -o $@ $<

tThroughComponent.o : tThroughComponent.c
	$(CC) -c $(CFLAGS) -o $@ $<

# Celltype: tTargetComponent
$(GEN_DIR)/tTargetComponent_tecsgen.o : $(GEN_DIR)/tTargetComponent_tecsgen.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(GEN_DIR)/tTargetComponent_templ.o : $(GEN_DIR)/tTargetComponent_templ.c
	$(CC) -c $(CFLAGS) -o $@ $<

tTargetComponent.o : tTargetComponent.c
	$(CC) -c $(CFLAGS) -o $@ $<

# Celltype: tTestClient
$(GEN_DIR)/tTestClient_tecsgen.o : $(GEN_DIR)/tTestClient_tecsgen.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(GEN_DIR)/tTestClient_templ.o : $(GEN_DIR)/tTestClient_templ.c
	$(CC) -c $(CFLAGS) -o $@ $<

tTestClient.o : tTestClient.c
	$(CC) -c $(CFLAGS) -o $@ $<

