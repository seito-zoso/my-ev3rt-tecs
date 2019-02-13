include EV3RT_TECS # モジュール

mrb_dir = "mrb_app" # .mrb保存ディレクトリの指定

class CLIMenu
  MENU_PAGE_SIZE = 6

  attr_reader :entries, :page, :mode

  def initialize(dir)
    @mode = 0 # run:0、delete:1,bluetooth:2
    @dir = dir
    @entries = []
    @page = 0
    @position = 0
    @change_flag = true # 何かユーザーから操作があったか
    @btr = 4096   # 読みだすバイト数。必要であれば変更する
    LCD.font = :medium
  end

  def draw
    if @change_flag then
      clear
      LCD.draw("Menu & Bluetooth",0, 0)
      if @mode == 0
        LCD.draw("<      run       >",0, 7)
        start = @page * MENU_PAGE_SIZE
        finish = [start + MENU_PAGE_SIZE, @entries.size].min
        @entries.values_at(start...finish).each_with_index do |entry, index|
          selected = (@position % MENU_PAGE_SIZE == index)
          prefix = selected ? ">" : " " # selectedが真であれば＞、偽なら何もなし
          LCD.draw("#{prefix}#{entry.gsub(".mrb","")}", 0, index + 1)
        end
      elsif @mode == 1
        LCD.draw("<     delete     >",0, 7)
        start = @page * MENU_PAGE_SIZE
        finish = [start + MENU_PAGE_SIZE, @entries.size].min
        @entries.values_at(start...finish).each_with_index do |entry, index|
          selected = (@position % MENU_PAGE_SIZE == index)
          prefix = selected ? ">" : " " # selectedが真であれば＞、偽なら何もなし
          LCD.draw("#{prefix}#{entry.gsub(".mrb","")}", 0, index + 1)
        end
      elsif @mode == 2
        LCD.draw("<    bluetooth   >",0, 7)
        LCD.draw("Receive file",0, 2)
        LCD.draw("  via bluetooth?",0, 3)
      end
    end
    @change_flag = false
  end

  def next
    @change_flag = true
    return if @position + 1 >= entries.size # 今の位置がentriesの要素数以上なら何もしない
    @position += 1
    if @position + 1 > (@page + 1) * MENU_PAGE_SIZE #更新後の位置がページサイズ×現在のページ以上なら
      @page += 1
    end
  end

  def prev
    @change_flag = true
    return if @position <= 0 # 今の位置が0以下なら何もしない
    @position -= 1
    if @position < @page * MENU_PAGE_SIZE
      @page -= 1
    end
  end

  def current
    @position
  end

  def push
    @change_flag = true
    @entries.clear
    dir = FatDir.new
    dir.open(@dir)
    buf = TECS::CharPointer.new(13)
    num = 0
    while true
      text = dir.read
      buf.from_s text
      if buf[0] == 0 then # 項目なしの時は抜ける
        break
      end
      @entries.push(text.dup) # 項目をentriesにPUSH
      num += 1
    end
    dir.close
  end

  def run
    clear
    inst = RunApp.new
    inst.run("#{@dir}/#{entries[@position]}")
    while true
      if Button[:back].pressed?
        while Button[:back].pressed?
          RTOS.delay(10)
        end
        break
      end
    end
  end

  def delete
    @change_flag = true
    clear
    flag = false
    LCD.draw("Delete #{entries[@position].gsub(".mrb","")} ?", 0, 0)
    while true
      flag ? LCD.draw(" No >Yes", 0, 2) : LCD.draw(">No  Yes", 0, 2)
      if Button[:right].pressed?
        while Button[:right].pressed?
          RTOS.delay(10)
        end
        flag = true
      end
      if Button[:left].pressed?
        while Button[:left].pressed?
          RTOS.delay(10)
        end
        flag = false
      end
      if Button[:enter].pressed?
        while Button[:enter].pressed?
          RTOS.delay(10)
        end
        break
      end
    end
    if flag
      file = FatFile.new
      file.delete("#{@dir}/#{entries[@position]}")
      clear
      LCD.draw("Delete #{entries[@position].gsub(".mrb","")} !", 0, 0)
      @page = 0
      @position = 0
      while true
        if Button[:enter].pressed?
          while Button[:enter].pressed?
            RTOS.delay(10)
          end
          break
        end
      end
    end
  end

  def bluetooth
    @change_flag = true
    clear
    LCD.draw("Bluetooth", 0, 0)
    while true
      if Button[:enter].pressed?
        while Button[:enter].pressed?
          RTOS.delay(10)
        end
        break
      end
    end
    # instant = Receive.new
    # instant.recv()
  end

  def mode_change_right
    @mode += 1
    @mode -= 3 if @mode > 2
    @change_flag = true
  end
  def mode_change_left
    @mode -= 1
    @mode += 3 if @mode < 0
    @change_flag = true
  end
  def clear
    LCD.fill_rect(0, 0, 178, 128, :white)
  end
end

# 引数：タイトルと読み込み対象ディレクトリ
cli_menu = CLIMenu.new(mrb_dir)
flag = false
begin
  cli_menu.push # 対象dirを読み込みentryに追加
  cli_menu.draw
  while true
    if Button[:back].pressed?
      while Button[:back].pressed?
        RTOS.delay(10)
      end
      break
    end
    if Button[:up].pressed?
      while Button[:up].pressed?
        RTOS.delay(10)
      end
      cli_menu.prev
    end
    if Button[:down].pressed?
      while Button[:down].pressed?
        RTOS.delay(10)
      end
      cli_menu.next
    end
    if Button[:enter].pressed?
      while Button[:enter].pressed?
        RTOS.delay(10)
      end
      if cli_menu.mode == 0
        cli_menu.run
        flag = true
      end
      if cli_menu.mode == 1
        cli_menu.delete
        cli_menu.push
      end
      if cli_menu.mode == 2
        cli_menu.bluetooth
        flag = true
      end
    end

    if Button[:right].pressed?
      while Button[:right].pressed?
        RTOS.delay(10)
      end
      cli_menu.mode_change_right
    end
    if Button[:left].pressed?
      while Button[:left].pressed?
        RTOS.delay(10)
      end
      cli_menu.mode_change_left
    end
    break if flag
    cli_menu.draw
    RTOS.delay(200)
  end
  cli_menu.clear
rescue => e
  LCD.error_puts e
end
