# 
#  Title: Makefile
#  Date	: 2016/05/10
#  Name	: Takuro
#

#  mrubyのアプリケーションファイル名
#APP_NAME = battery_sample.rb
APP_NAME = button_sample.rb
#APP_NAME = color_sample.rb
#APP_NAME = color_sample2.rb
#APP_NAME = color_sample3.rb
#APP_NAME = ev3way_sample.rb
#APP_NAME = gyro_sample.rb
#APP_NAME = lcd_sample.rb
#APP_NAME = lcd_sample2.rb
#APP_NAME = lcd_sample3.rb
#APP_NAME = led_sample.rb
#APP_NAME = motor_sample.rb
#APP_NAME = motor_sample2.rb
#APP_NAME = rtos_sample.rb
#APP_NAME = sharedmemory_sample.rb
#APP_NAME = sharedmemory_sample2.rb
#APP_NAME = speaker_sample.rb
#APP_NAME = speaker_sample2.rb
#APP_NAME = touch_sample.rb
#APP_NAME = ultrasonic_sample.rb

#  mrubyアプリケーションのディレクトリ
MRUBY_DIR = ../mruby_app

#  RBファイル
APP_RB 	= $(MRUBY_DIR)/$(APP_NAME)

#  MRBファイル
APP_MRB = $(basename $(APP_RB)).mrb

#  コマンドから転送する場合，TRANSFER = true とする 
#  デフォルトでは，TRANSFER = となっている
TRANSFER = 

#  ポート
COM_PORT = 4
#  ボーレート
BAUDRATE = 115200

#  TTLファイル名
ZMODEM_TTL_TMPL = ../common/zmodemsend_template.ttl
ZMODEM_TTL = zmodemsend.ttl

#
#  ソースファイルのディレクトリの定義
#
SRCDIR = ../..

#  mruby 関係の設定
MRUBY_SRC_DIR = $(SRCDIR)/../mruby

#  mruby compiler 
MRBC = $(MRUBY_SRC_DIR)/bin/mrbc

#  作業ディレクトリ
WORK_DIR = $(CYGPATH) .

#  Tera Term マクロを使用するための設定
#  TODO: PATHに通しているためttpmacro.exeを使える
TTPMACRO = ttpmacro.exe

#  sed
SED = /usr/bin/sed

# cygpath の設定(Windowsの絶対パス)
CYGPATH = /usr/bin/cygpath -aw


ifdef TRANSFER
all: ttpmacro

#  mruby compile
$(APP_MRB): $(APP_RB)
	$(MRBC) -o$(APP_MRB) $(APP_RB)

APP_MRB_PATH = $(shell $(CYGPATH) $(APP_MRB) | $(SED) -e 's/\\/\\\\/g')

#  TTLファイルを書き換える
$(ZMODEM_TTL): $(APP_MRB) 
	$(SED) 	-e 's/_COM_PORT_/$(COM_PORT)/' \
	   		-e 's/_BAUDRATE_/$(BAUDRATE)/' \
			-e 's/_APP_MRB_/$(APP_MRB_PATH)/' $(ZMODEM_TTL_TMPL) > $(ZMODEM_TTL)

#  Tera Term マクロを通して，バイトコード転送
.PHONY: ttpmacro
ttpmacro: $(ZMODEM_TTL)
	$(TTPMACRO) `$(CYGPATH) $(ZMODEM_TTL)`

else 
all: $(APP_MRB)

#  mruby compile
$(APP_MRB): $(APP_RB)
	@echo $(APP_MRB)
	$(MRBC) -o$(APP_MRB) $(APP_RB)
endif
