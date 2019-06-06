MRuby::Build.new do |conf|
  # load specific toolchain settings

  # Gets set by the VS command prompts.
  if ENV['VisualStudioVersion'] || ENV['VSINSTALLDIR']
    toolchain :visualcpp
  else
    toolchain :gcc
  end

  # Turn on `enable_debug` for better debugging
  enable_debug

  # Use mrbgems
  # conf.gem 'examples/mrbgems/ruby_extension_example'
  # conf.gem 'examples/mrbgems/c_extension_example' do |g|
  #   g.cc.flags << '-g' # append cflags in this gem
  # end
  # conf.gem 'examples/mrbgems/c_and_ruby_extension_example'
  # conf.gem :core => 'mruby-eval'
  # conf.gem :mgem => 'mruby-io'
  # conf.gem :github => 'iij/mruby-io'
  # conf.gem :git => 'git@github.com:iij/mruby-io.git', :branch => 'master', :options => '-v'

  # include the default GEMs
  conf.gembox 'default'
  # C compiler settings
  # conf.cc do |cc|
  #   cc.command = ENV['CC'] || 'gcc'
  #   cc.flags = [ENV['CFLAGS'] || %w()]
  #   cc.include_paths = ["#{root}/include"]
  #   cc.defines = %w()
  #   cc.option_include_path = '-I%s'
  #   cc.option_define = '-D%s'
  #   cc.compile_options = "%{flags} -MMD -o %{outfile} -c %{infile}"
  # end

  # mrbc settings
  # conf.mrbc do |mrbc|
  #   mrbc.compile_options = "-g -B%{funcname} -o-" # The -g option is required for line numbers
  # end

  # Linker settings
  # conf.linker do |linker|
  #   linker.command = ENV['LD'] || 'gcc'
  #   linker.flags = [ENV['LDFLAGS'] || []]
  #   linker.flags_before_libraries = []
  #   linker.libraries = %w()
  #   linker.flags_after_libraries = []
  #   linker.library_paths = []
  #   linker.option_library = '-l%s'
  #   linker.option_library_path = '-L%s'
  #   linker.link_options = "%{flags} -o %{outfile} %{objs} %{libs}"
  # end

  # Archiver settings
  # conf.archiver do |archiver|
  #   archiver.command = ENV['AR'] || 'ar'
  #   archiver.archive_options = 'rs %{outfile} %{objs}'
  # end

  # Parser generator settings
  # conf.yacc do |yacc|
  #   yacc.command = ENV['YACC'] || 'bison'
  #   yacc.compile_options = '-o %{outfile} %{infile}'
  # end

  # gperf settings
  # conf.gperf do |gperf|
  #   gperf.command = 'gperf'
  #   gperf.compile_options = '-L ANSI-C -C -p -j1 -i 1 -g -o -t -N mrb_reserved_word -k"1,3,$" %{infile} > %{outfile}'
  # end

  # file extensions
  # conf.exts do |exts|
  #   exts.object = '.o'
  #   exts.executable = '' # '.exe' if Windows
  #   exts.library = '.a'
  # end

  # file separetor
  # conf.file_separator = '/'

  # bintest
  # conf.enable_bintest
end

# MRuby::Build.new('host-debug') do |conf|
#   # load specific toolchain settings

#   # Gets set by the VS command prompts.
#   if ENV['VisualStudioVersion'] || ENV['VSINSTALLDIR']
#     toolchain :visualcpp
#   else
#     toolchain :gcc
#   end

#   enable_debug

#   # include the default GEMs
#   conf.gembox 'default'

#   # C compiler settings
#   conf.cc.defines = %w(MRB_ENABLE_DEBUG_HOOK)

#   # Generate mruby debugger command (require mruby-eval)
#   conf.gem :core => "mruby-bin-debugger"

#   # bintest
#   # conf.enable_bintest
# end

# MRuby::Build.new('test') do |conf|
#   # Gets set by the VS command prompts.
#   if ENV['VisualStudioVersion'] || ENV['VSINSTALLDIR']
#     toolchain :visualcpp
#   else
#     toolchain :gcc
#   end

#   enable_debug
#   conf.enable_bintest
#   conf.enable_test

#   conf.gembox 'default'
# end

#MRuby::Build.new('bench') do |conf|
#  # Gets set by the VS command prompts.
#  if ENV['VisualStudioVersion'] || ENV['VSINSTALLDIR']
#    toolchain :visualcpp
#  else
#    toolchain :gcc
#    conf.cc.flags << '-O3'
#  end
#
#  conf.gembox 'default'
#end

MRuby::CrossBuild.new('ARM') do |conf|
  toolchain :gcc
  conf.cc.defines = %w(DISABLE_STDIO)
  conf.bins = []

  [conf.cc, conf.objc, conf.asm].each do |cc|
    cc.command = ENV['CC'] || 'arm-none-eabi-gcc'
    cc.flags = [ENV['CFLAGS'] || %w(-g -std=gnu99 -O3 -Wall -Werror-implicit-function-declaration)]
    cc.include_paths = ["#{MRUBY_ROOT}/include"],

    cc.defines = %w(DISABLE_GEMS)
    cc.option_include_path = '-I%s'
    cc.option_define = '-D%s'
    cc.compile_options = '%{flags} -MMD -o %{outfile} -c %{infile}'
  end

  [conf.cxx].each do |cxx|
    cxx.command = ENV['CXX'] || 'arm-none-eabi-g++'
    cxx.flags = [ENV['CXXFLAGS'] || ENV['CFLAGS'] || %w(-g -O3 -Wall -Werror-implicit-function-declaration)]
    cxx.include_paths = ["#{MRUBY_ROOT}/include"]
    cxx.defines = %w(DISABLE_GEMS)
    cxx.option_include_path = '-I%s'
    cxx.option_define = '-D%s'
    cxx.compile_options = '%{flags} -MMD -o %{outfile} -c %{infile}'
  end

  conf.linker do |linker|
    linker.command = ENV['LD'] || 'arm-none-eabi-gcc'
    linker.flags = [ENV['LDFLAGS'] || %w()]
    linker.libraries = %w(m)
    linker.library_paths = []
    linker.option_library = '-l%s'
    linker.option_library_path = '-L%s'
    linker.link_options = '%{flags} -o %{outfile} %{objs} %{flags_before_libraries} %{libs} %{flags_after_libraries}'
  end

  # Archiver settings
  conf.archiver do |archiver|
    archiver.command = ENV['AR'] || 'arm-none-eabi-ar'
p  end
  #
  #   conf.cc.flags << "-m32"
  #   conf.linker.flags << "-m32"
    #
  # Use standard print/puts/p
  conf.gem :core => "mruby-print"
  # Use extended toplevel object (main) methods
  conf.gem :core => "mruby-toplevel-ext"
  # Use standard Math module
  #  conf.gem :core => "mruby-math"
  # Use mruby-compiler to build other mrbgems
  conf.gem :core => "mruby-compiler"
  conf.gem :core => "mruby-array-ext"
=begin
  conf.build_mrbtest_lib_only
  # Use standard Kernel#sprintf method
  conf.gem :core => "mruby-sprintf"
  # Use standard Time class
  # conf.gem :core => "mruby-time"
  # Use standard Struct class
  conf.gem :core => "mruby-struct"
  # Use extensional Enumerable module
  conf.gem :core => "mruby-enum-ext"
  # Use extensional String class
  #conf.gem :core => "mruby-string-ext"
  # Use extensional Numeric class
  conf.gem :core => "mruby-numeric-ext"
  # Use extensional Array class
  conf.gem :core => "mruby-array-ext"
  # Use extensional Hash class
  conf.gem :core => "mruby-hash-ext"
  # Use extensional Range class
  conf.gem :core => "mruby-range-ext"
  # Use extensional Proc class
  conf.gem :core => "mruby-proc-ext"
  # Use extensional Symbol class
  conf.gem :core => "mruby-symbol-ext"
  # Use Random class
  # conf.gem :core => "mruby-random"
  # Use extensional Object class
  conf.gem :core => "mruby-object-ext"
  # Use ObjectSpace class
  conf.gem :core => "mruby-objectspace"
  # Use Fiber class
  conf.gem :core => "mruby-fiber"
  # Use Enumerator class (require mruby-fiber)
  conf.gem :core => "mruby-enumerator"
  # Use Enumerable::Lazy class (require mruby-enumerator)
  conf.gem :core => "mruby-enum-lazy"
  # Generate mirb command
  # conf.gem :core => "mruby-bin-mirb"
  # Generate mruby command
  # conf.gem :core => "mruby-bin-mruby"
  # Generate mruby-strip command
  # conf.gem :core => "mruby-bin-strip"
=end
  #conf.gem :core => "mruby-tecs"
  #conf.gem :core => "mruby-bin-mruby"
  #conf.gem :core => "mruby-ev3-motor"
end

# Define cross build settings
# MRuby::CrossBuild.new('32bit') do |conf|
#   toolchain :gcc
#
#   conf.cc.flags << "-m32"
#   conf.linker.flags << "-m32"
#
#   conf.build_mrbtest_lib_only
#
#   conf.gem 'examples/mrbgems/c_and_ruby_extension_example'
#
#   conf.test_runner.command = 'env'
# end
