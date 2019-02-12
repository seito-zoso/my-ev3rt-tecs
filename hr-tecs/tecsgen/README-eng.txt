TECS

  TECS - Toppers Embedded Component System -

  TECS is designed by TECS WG of NPO TOPPERS Project.

README

  This file explains preparation and invocation of TECS generator
  'tecsgen'.

Condition

  You may use TECS under the TOPPERS License which is described in
  each source file. But The TECS specification is distributed under
  the different license.

  Some files are distributed under other licenses. Please see each
  file header part.

Bug report

  If you find a bug or any problem, please let us know by sending
  e-mail. The address is com-wg@toppers.jp (if you are member of
  TOPPERS project) or users@toppers.jp.

  Note: before sending e-mail you have to participate ML.

    URL  http://www.toppers.jp/en/community.html

Preparation

  TECS generator is implemented using Ruby. So you have to install
  Ruby interpreter. But if you use exerb version of tecsgen on Windows
  based system, installing ruby is unnecessary.

Platforms where tecsgen runs

  We checked tecsgen on the platforms below.

    cygwin on Windows based systems
    MacOS X
    Linux (Ubuntu, Fedora)
    Command Prompt on Windows based systems (exerb version) 

Install tecsgen

  You can get TECS generator from svn repository (TOPPERS member only)
  or package from TECS homepage in TOPPERS project's HP.

Setting Environment Variable

  Add PATH to the directory where tecsgen is placed.
  Set TECSPATH where tecsgen/tecs is placed. This is necessary when
  you use MrubyBridgePlugin, *RPCPlugin and Makefile template.

  set_env.sh sets these environment variables. Please read it into
  your b-shell by the command like below.

  % source set_env.sh

  When doing this, you have to change current directory where
  set_env.sh is placed.

  You might need to set TECSGEN_LANG environment variable.

  % export TECSGEN_LANG=C.UTF-8

To invoke tecsgen, type like below.

  % tecsgen hello.cdl

  You will need add some options -I, -D, etc.
  You can see brief help by the command below.

  % tecsgen --help
