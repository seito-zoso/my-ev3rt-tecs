# このファイルは tecsgen により自動生成されました
# Makefile.temp は gen の一つ上のディレクトリに移して使用します
#  % mv Makefile.temp Makefile
# 
# clean のデフォルト動作は $(GEN_DIR)/Makefile.* を削除します

# 変数 #_MVAR_#
TARGET = region.exe
TECSGEN_EXE = tecsgen
CC = gcc
CFLAGS = -I . -I ../RUNTIME/tecs-runtime/include -I ../RUNTIME/tecs-runtime/target -I gen
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
 	$(GEN_DIR)/tCtR1_templ.o \
 	$(GEN_DIR)/tCtR2_templ.o \
 	$(GEN_DIR)/tCtOuter_templ.o \
 	$(GEN_DIR)/tMain_templ.o \
# TEMPL_COBJS terminater

TEMPL_SRCS = \
 	$(GEN_DIR)/tCtR1_templ.c \
 	$(GEN_DIR)/tCtR2_templ.c \
 	$(GEN_DIR)/tCtOuter_templ.c \
 	$(GEN_DIR)/tMain_templ.c \
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
#	tecsgen -U  -G rRegion2 -I ../RUNTIME/tecs-runtime/include -I ../RUNTIME/tecs-runtime/target region.cdl
#	$(TECSGEN_EXE) -G rRegion2 -I ../RUNTIME/tecs-runtime/include -I ../RUNTIME/tecs-runtime/target region.cdl
	$(TECSGEN_EXE) -I ../RUNTIME/tecs-runtime/include -I ../RUNTIME/tecs-runtime/target region.cdl
	touch tecsgen.timestamp

# Celltype: tCtR1
$(GEN_DIR)/tCtR1_tecsgen.o : $(GEN_DIR)/tCtR1_tecsgen.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(GEN_DIR)/tCtR1_templ.o : $(GEN_DIR)/tCtR1_templ.c
	$(CC) -c $(CFLAGS) -o $@ $<

tCtR1.o : tCtR1.c
	$(CC) -c $(CFLAGS) -o $@ $<

# Celltype: tCtR2
$(GEN_DIR)/tCtR2_tecsgen.o : $(GEN_DIR)/tCtR2_tecsgen.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(GEN_DIR)/tCtR2_templ.o : $(GEN_DIR)/tCtR2_templ.c
	$(CC) -c $(CFLAGS) -o $@ $<

tCtR2.o : tCtR2.c
	$(CC) -c $(CFLAGS) -o $@ $<

# Celltype: tCtOuter
$(GEN_DIR)/tCtOuter_tecsgen.o : $(GEN_DIR)/tCtOuter_tecsgen.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(GEN_DIR)/tCtOuter_templ.o : $(GEN_DIR)/tCtOuter_templ.c
	$(CC) -c $(CFLAGS) -o $@ $<

tCtOuter.o : tCtOuter.c
	$(CC) -c $(CFLAGS) -o $@ $<

# Celltype: tTracePlugin_sSig3
$(GEN_DIR)/tTracePlugin_sSig3_tecsgen.o : $(GEN_DIR)/tTracePlugin_sSig3_tecsgen.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(GEN_DIR)/tTracePlugin_sSig3_templ.o : $(GEN_DIR)/tTracePlugin_sSig3_templ.c
	$(CC) -c $(CFLAGS) -o $@ $<

tTracePlugin_sSig3.o : tTracePlugin_sSig3.c
	$(CC) -c $(CFLAGS) -o $@ $<

# Celltype: tMain
$(GEN_DIR)/tMain_tecsgen.o : $(GEN_DIR)/tMain_tecsgen.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(GEN_DIR)/tMain_templ.o : $(GEN_DIR)/tMain_templ.c
	$(CC) -c $(CFLAGS) -o $@ $<

tMain.o : tMain.c
	$(CC) -c $(CFLAGS) -o $@ $<

