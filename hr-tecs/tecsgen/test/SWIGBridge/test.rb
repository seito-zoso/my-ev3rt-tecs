#! /usr/bin/ruby

require "SWIGBridge.so"

cell_name = "RubyTest"

puts "test.rb: joining cell #{cell_name}"
cell = SWIGBridge::CsTest.join( cell_name )

puts "test.rb: calling #{cell_name}.cTECS.test(5)"
cell.test 5

puts "test.rb: calling #{cell_name}.cTECS.test4(\"hello\",3)"
cell.test4 "hello", 3
