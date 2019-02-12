#! /usr/bin/ruby
# -*- coding: utf-8 -*-

p __FILE__

#まずは決まり文句
require 'gtk2'
p 0

builder = Gtk::Builder.new
builder.add_from_file("tecscde-export.glade") #読み込むgladeファイルを指定

p 1
# p builder
# p builder.objects

#後で処理を書くウィジェットは下のような形で、変数に代入しておくのよ
main_window = builder["dialog_export"]

p 2
#ウィンドウのクローズボタンが押されたら終了
main_window.signal_connect("destroy") do
  Gtk.main_quit
end

#終了ボタンがクリックされたら終了
# btn_quit.signal_connect("clicked") do
# 	Gtk.main_quit
# end

p 3
# メインウィンドウの表示
main_window.show_all

p 4
Gtk.main

