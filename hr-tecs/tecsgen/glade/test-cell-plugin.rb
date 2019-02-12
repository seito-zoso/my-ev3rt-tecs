# -*- coding: utf-8 -*-

#まずは決まり文句
require 'gtk2'

builder = Gtk::Builder.new
builder.add_from_file("tecscde-cell-plugin.glade") #読み込むgladeファイルを指定

# p builder
# p builder.objects

#後で処理を書くウィジェットは下のような形で、変数に代入しておくのよ
main_window = builder["dialog_cell_plugin"]
# @btn_quit = builder["quit"]
label_cell_name = builder[ "label_cell_name" ]

builder.objects.each{ |obj|
  p obj
}

COL_NAME = 0
COL_OPTION = 1

plugin_list = builder[ "treeview_plugin_list" ]
liststore = Gtk::ListStore.new(String, String)
plugin_list.set_model(liststore)

# create renderer for text
renderer = Gtk::CellRendererText.new

# set column information
col = Gtk::TreeViewColumn.new("Plugin", renderer, :text => COL_NAME)
plugin_list.append_column(col)

col = Gtk::TreeViewColumn.new("Option", renderer, :text => COL_OPTION)
plugin_list.append_column(col)

liststore.set_sort_column_id( COL_NAME )

#ウィンドウのクローズボタンが押されたら終了
main_window.signal_connect("destroy") do
  Gtk.main_quit
end

#終了ボタンがクリックされたら終了
# btn_quit.signal_connect("clicked") do
# 	Gtk.main_quit
# end

# メインウィンドウの表示
main_window.show_all

Gtk.main

