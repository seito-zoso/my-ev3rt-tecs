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
TARGET = opaqueRPC.exe
TIMESTAMP = tecsgen.timestamp
TECSGEN_EXE = tecsgen
BASE_DIR = .
CC = gcc
CFLAGS = -I $(BASE_DIR)/. -I $(BASE_DIR)/.. -I $(BASE_DIR)/../cygwin -I $(TECSPATH) -I $(TECSPATH)/mruby -I $(TECSPATH)/rpc -I $(BASE_DIR)/rpc -I $(GEN_DIR) -D __extension__= -D "Inline=static inline"
LD = gcc
LDFLAGS = 
GEN_DIR = $(BASE_DIR)/gen
SRC_DIR = $(BASE_DIR)/src
_TECS_OBJ_DIR = $(GEN_DIR)/
#   _TECS_OBJ_DIR   # should end with '/'

vpath %.c $(SRC_DIR) $(GEN_DIR)  .. ../cygwin $(TECSPATH) $(TECSPATH)/mruby $(TECSPATH)/rpc rpc
vpath %.h $(SRC_DIR) $(GEN_DIR)  .. ../cygwin $(TECSPATH) $(TECSPATH)/mruby $(TECSPATH)/rpc rpc

OTHER_OBJS =                       # Add objects out of tecs care.
# OTHER_OBJS = $(_TECS_OBJ_DIR)vasyslog.o

# ルール #_MRUL_#
allall: tecs
	make all     # in order to include generated Makefile.tecsgen & Makefile.depend

all :  sub_regions


# depend を include #_MDEP_#
-include $(GEN_DIR)/Makefile.tecsgen

sub_regions:$(TIMESTAMP)
	cd rClient; make all
	cd rServer; make all

clean :
	cd rClient; make clean
	cd rServer; make clean
	rm -f $(CELLTYPE_COBJS) $(TECSGEN_COBJS) $(PLUGIN_COBJS) $(OTHER_OBJS) $(TARGET)  $(TIMESTAMP)
	rm -rf $(GEN_DIR)

tecs : $(TIMESTAMP)

$(TIMESTAMP) : $(TECS_IMPORTS)
	$(TECSGEN_EXE)  --generate-all-template -g gen -D __extension__= -I .. -I ../cygwin -I ../../tecs -I ../../tecs/rpc opaqueRPC.cdl
	touch $(TIMESTAMP)

# generic target for objs
$(_TECS_OBJ_DIR)%.o : %.c
	$(CC) -c $(CFLAGS) -o $@ $<

