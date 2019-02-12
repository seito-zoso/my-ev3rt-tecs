@echo OFF
echo "setting PATH, RUBYLIB & TECSPATH"
set PATH=%CD%\tecsgen;%PATH%
set RUBYLIB=%CD%\tecsgen
set TECSPATH=%CD%\tecsgen\tecs
REM symbolic link does not work in windows environment
REM set TECSPATH=%CD%\tecs
