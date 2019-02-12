#! /bin/sh
# check the number of arguments
if [ "!$1" = "!-r" ]; then
	tecsgen=tecsgen_rcov.rb
	shift
elif [ "!$1" = "!-e" ]; then
	# 今のところ、-e は期待したようには動かない
	tecsgen=tecsgen.exe
	shift
else
	tecsgen=tecsgen
fi

if [ $# -lt 3 ]; then
	echo "usage: test_err.sh N_errors N_warnings [tecsgen_options] file.cdl"
	exit 1
fi

err_warn=""
n_err=$1
shift
if [ $n_err -gt 0 ]; then
	err_warn="$n_err error"
	if [ $n_err -gt 1 ]; then
		err_warn="${err_warn}s"
	fi
fi
#
n_warn=$1
shift
if [ $n_warn -gt 0 ]; then
	if [ "$err_warn" != "" ]; then
		err_warn="$err_warn  "
	fi
	err_warn="$err_warn$n_warn warning"
	if [ $n_warn -gt 1 ]; then
		err_warn="${err_warn}s"
	fi
fi
#
TMP=/tmp/test_err_$$.txt
# echo $err_warn
# echo $TMP
#
echo $tecsgen $*
$tecsgen -L . $* | tee $TMP
grep "^$err_warn" $TMP > /dev/null
status=$?
#
rm -f $TMP
if [ $status -ne 0 ]; then
	echo "***"
	echo "*** number of errors and/or warnings mismatched."
	echo "*** expecting:  '$err_warn'"
	echo "***"
	exit 1
else
	echo "***"
	echo "*** [OK] number of errors and warnings matched. ***"
	echo "***"
	exit 0
fi
