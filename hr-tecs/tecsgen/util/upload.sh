#! /bin/sh
VERSION=`grep '^VERSION ' MANIFEST | sed -e "s/^VERSION //"`
echo VERSION : $VERSION
if [ "$VERSION" = "" ] ;then
    echo "version not found in MANIFEST"
    exit 1
fi

DATE=`date`
if [ "$1" = "-c" ] ; then
    CREATE_TAG=true
elif [ "$1" = "-t" ] ; then
    CREATE_TAG=false
else
    echo "usage: ./util/upload.sh [-c|-t]"
    echo "  -c : upload & create tag"
    echo "  -t : upload only trunk"
    exit 0
fi

TAG=tecsgen-$VERSION
TAGS_URL=http://dev.toppers.jp/svn/tecs/toppers/tecsgen/tags
TRUNK_URL=http://dev.toppers.jp/svn/tecs/toppers/tecsgen/trunk
echo checking tags
if svn ls $TAGS_URL/$TAG > /dev/null 2>&1 ; then
    echo "'$TAG' already exist on repositry"
    exit 1
else
	# 
    # echo "making tecsgen"
	# pushd tecsgen
	# make clean
	# make generator
	# popd

    echo "committing trunk"
    if svn commit -m "release $VERSION" ; then
		echo "copy $VERSION master trunk: done"
		if [ "$CREATE_TAG" = "true" ]; then
			if svn copy $TRUNK_URL $TAGS_URL/$TAG -m "release $VERSION" ; then
				echo "copy $VERSION done"
			else
				echo "!!! svn : copy error"
				exit 1
			fi
		fi
    else
		echo "!!! svn : trunk copy error"
		exit 1
    fi
fi
echo done
