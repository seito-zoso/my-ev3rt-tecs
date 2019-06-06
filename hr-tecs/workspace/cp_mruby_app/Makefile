#  mrubyのアプリケーションファイル名
# APP_NAME = bluetooth.rb
# APP_NAME = battery.rb
APP_NAME = button.rb
# APP_NAME = color.rb
# APP_NAME = color2.rb
# APP_NAME = color3.rb
# APP_NAME = ev3way.rb
# APP_NAME = gyro.rb
# APP_NAME = lcd.rb
# APP_NAME = lcd2.rb
# APP_NAME = lcd3.rb
# APP_NAME = led.rb
# APP_NAME = motor.rb
# APP_NAME = motor2.rb
# APP_NAME = rtos.rb
# APP_NAME = sharedmem.rb
# APP_NAME = sharedmem2.rb
# APP_NAME = speaker.rb
# APP_NAME = speaker2.rb
# APP_NAME = touch.rb
# APP_NAME = ultrasonic.rb

#  mrubyアプリケーションのディレクトリ
MRUBY_DIR = ../cp_mruby_app

# SDのドライブ文字を指定
SD_DIR = /cygdrive/d/

# SD上のアプリケーションディレクトリ
SD_MRB = $(SD_DIR)mrb_app

#  RBファイル
APP_RB 	= $(MRUBY_DIR)/$(APP_NAME)

#  MRBファイル
APP_MRB = $(basename $(APP_RB)).mrb

#  コマンドから転送する場合，TRANSFER = true とする
#  デフォルトでは，TRANSFER = となっている
TRANSFER =
# TRANSFER = true

#  ポート
COM_PORT = 40
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
all: copy

# SD mrb_appに.mrbファイルを保存する
.PHONY: copy
copy: $(APP_MRB)
	mkdir -p $(SD_MRB)
	cp $(basename $(APP_NAME)).mrb $(SD_MRB)

#  mruby compile
$(APP_MRB): $(APP_RB)
	@echo $(APP_MRB)
	$(MRBC) -o$(APP_MRB) $(APP_RB)
endif

# clean .mrbファイル
.PHONY: clean
clean:
	rm -f $(APP_MRB)
