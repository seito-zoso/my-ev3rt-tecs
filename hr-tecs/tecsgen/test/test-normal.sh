#! /bin/bash

do_test()
{
   TECSGEN=$1
   shift
   pushd $1
   shift
   echo "##### $TECSGEN $*  #####"
   $TECSGEN $*
   popd 
}

if [ "$1" = "" ] ; then
  echo "usage: sh test-normal.sh tecsgen.exe"
  exit 1
fi

do_test $1 ./sample/data-normal normal-1.idl
do_test $1 ./sample/data-normal normal-2.idl

do_test $1 ./sample/data-flat jsp_flat.sig.CPP sample1_flat.blt.CPP sample1_flat.ct.CPP



