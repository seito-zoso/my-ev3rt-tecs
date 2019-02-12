#
# This shell script is not intended to execute direclty in the shell.
# Please read this file into your shell using cmmand like below.
#  % source set_env.sh
# Or you can put the contents of this file into your rc file. ex) .bashrc, .profile ... etc
#
# This shell script is written based on b-shell grammar (bash, ksh are included).
# If you are c-shell user, please refer the bottom of this file.
#
BASEDIR=$PWD    # This line is to be changed if you put the contents into your rc file.

echo $PATH | grep "$BASEDIR/tecsgen" > /dev/null
if [ $? = 0 ]; then
	echo "PATH: unchanged !!"
else
	PATH=$BASEDIR/tecsgen:$PATH
fi
if [ "$TECSPATH" = ""  ]; then
	export TECSPATH=$BASEDIR/tecsgen/tecs    # actual path
#	export TECSPATH=$BASEDIR/tecs            # symbolic link
else
	echo "TECSPATH: unchanged !! ($TECSPATH)"
fi

#
# For C-shell users
#
# pelase execute statements below in your shell.
#
# set BASEDIR = $PWD
# set path = ( $path $BASEDIR/tecsgen )
# setenv TECSPATH $BASEDIR/tecsgen/tecs
