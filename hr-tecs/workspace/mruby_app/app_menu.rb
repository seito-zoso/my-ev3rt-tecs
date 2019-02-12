include EV3RT_TECS # モジュール

mrb_dir = "mrb_app" # .mrb保存ディレクトリの指定

class CLIMenu
  MENU_PAGE_SIZE = 6

  attr_reader :title, :entries, :page # 参照可能にしている

  def initialize(title,dir)
    @title = title    # インスタンス変数。同じインスタンスであればメソッドを超えて共通。
    @dir = dir
    @entries = []
    @page = 0
    @position = 0
    @btr = 4096   # 読みだすバイト数。必要であれば変更する
    LCD.font = :medium
  end

  def push
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
      entries.push(Entry.new(text)) # 項目をentriesにPUSH
      num += 1
    end
    dir.close
  end

  def draw
    clear
    LCD.draw(@title, 0, 0)
    start = @page * MENU_PAGE_SIZE
    finish = [start + MENU_PAGE_SIZE, @entries.size].min
    @entries.values_at(start...finish).each_with_index do |entry, index|
      selected = (@position % MENU_PAGE_SIZE == index)
      prefix = selected ? ">" : " " # selectedが真であれば＞、偽なら何もなし
      LCD.draw("#{prefix}#{entry.name}", 0, index + 1)
    end
  end

  def next
    return if @position + 1 >= entries.size # 今の位置がentriesの要素数以上なら何もしない
    @position += 1
    if @position + 1 > (@page + 1) * MENU_PAGE_SIZE #更新後の位置がページサイズ×現在のページ以上なら
      @page += 1
    end
  end

  def prev
    return if @position <= 0 # 今の位置が0以下なら何もしない
    @position -= 1
    if @position < @page * MENU_PAGE_SIZE
      @page -= 1
    end
  end

  def current
    @position
  end

  def run
    clear
    inst = RunApp.new
    inst.run("#{@dir}/#{entries[@position].name}")
    while true
      if Button[:back].pressed?
        while Button[:back].pressed?
          RTOS.delay(10)
        end
        break
      end
    end
  end

  def clear
    LCD.fill_rect(0, 0, 178, 128, :white)
  end
end

class Entry
  attr_accessor :name #参照と変更両方可能に

  def initialize(name)
    @name = name
  end
end

# 引数：タイトルと読み込み対象ディレクトリ
cli_menu = CLIMenu.new("App Menu", mrb_dir)

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
      cli_menu.run
    end
    cli_menu.draw
    RTOS.delay(200)
  end
rescue => e
  LCD.error_puts e
end
