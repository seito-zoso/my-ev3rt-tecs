#! /bin/sh

if [ "$1" = "-u" ] ; then
    LIST_UNMANIFESTED_FILES=true
elif [ "$1" = "-c" ] ; then
    LIST_UNMANIFESTED_FILES=false

else
    echo "usage: ./util/release.sh [-c|-u] [MANIFEST]"
    echo "  -c : create .tgz to release"
    echo "  -u : list up UNMANIFESTED FILES"
    exit 0
fi

shift
if [ "$#" -gt "0" ]; then
    MANIFEST=$1
else
    MANIFEST=MANIFEST
fi

# MANIFEST 関数の読み込み
read_manifest(){
    PACKAGE=$1
    manifest=$2
    LP=$3  # leading path
    if [ -f $manifest ]; then
        FILES=`grep -v '^PACKAGE ' $manifest | grep -v '^VERSION ' | grep -v '^INCLUDE ' | grep -v '^#' | grep -v '^[ \t]*$' | sed -e s,^,$LP,`
    else
        echo MANIFEST file $manifest not found
        exit 1
    fi
}

write_version(){
    VER=$1
    PACKAGE=$2
    VF=$3
    echo -n    > $VF
    echo -n '$package = '       >> $VF
    if [ $?  != 0 ]; then
        # エラーメッセージは echo によって出力されているはず
        exit 1
    fi
    echo -n '"'  >> $VF
    echo -n $PACKAGE >> $VF
    echo    '"'  >> $VF
    echo -n '$version = '       >> $VF
    echo -n '"'  >> $VF
    echo -n $VER >> $VF
    echo    '"'  >> $VF
    if [ $?  != 0 ]; then
        # エラーメッセージは echo によって出力されているはず
        exit 1
    fi
}

check_all_files(){
    echo "checking files in MANIFEST"
    for file in $ALL
    do
        if [ -f $file -o -d $file ]; then
            echo > /dev/null
        else
            echo $file not found
        fi
    done
}

FILES=""
ALL=""

echo "reading MANIFEST files"
VERSION_FILE="tecsgen/tecslib/version.rb"
VERSION=`grep '^VERSION ' $MANIFEST | sed -e 's/VERSION //'`
VERSION_STRING=$VERSION
VERSION_NUMBER=`echo $VERSION | sed -e s/A/9991/ -e s/B/9992/ -e s/C/9993/`   # alpha, beta まで考慮
if [ "$VERSION" = "" ] ;then
    echo "VERSION not found in $MANIFEST"
    exit 1
fi
PACKAGE=`grep '^PACKAGE ' $MANIFEST | sed -e 's/PACKAGE //'`
if [ "$PACKAGE" = "" ] ;then
    echo "PACKAGE not found in $MANIFEST"
    exit 1
fi

if [ ! -d ../$PACKAGE ]; then
    echo there is no PACKAGE : $PACKAGE in '".."'.
    exit 1
fi

echo PACKAGE : $PACKAGE
echo VERSION : $VERSION

LP="$PACKAGE/"
read_manifest $PACKAGE $MANIFEST $LP
ALL="$FILES $ALL"

for manifest in `grep '^INCLUDE ' $MANIFEST | sed -e 's/INCLUDE //'`
do
    LP="$PACKAGE/`dirname $manifest`/"
    read_manifest $PACKAGE $manifest $LP
    ALL="$ALL $FILES"
done

if [ "$LIST_UNMANIFESTED_FILES" = "true" ];then
    # version.rb を更新
    echo "writing version.rb"
    write_version $VERSION $PACKAGE $VERSION_FILE

    # リストをチェック
    cd ..
    echo "finding all files in $PACKAGE (except referece)"
    ALL_FILES_LIST=`find $PACKAGE -name reference -prune -o -name .svn -prune -o -type f -print | sort`
    echo "sorting list in $MANIFEST"
    ALL_IN_MANIFEST=`echo $ALL | sort`
    echo "unmanifested files are below"
    for f in $ALL_FILES_LIST; do
        FOUND=false
        for f2 in $ALL_IN_MANIFEST; do
            if [ "$f" = "$f2" ]; then
                FOUND=true
                break
            fi
        done
        if [ "$FOUND" = "false" ]; then
            echo $f
        fi
    done
    check_all_files
else

# すべてのファイルが存在するかチェック
    cd ..

    check_all_files

    echo "creating tar file"
# tar の実行
    # echo $PACKAGE-$VERSION.tgz $ALL
    tar czf $PACKAGE-$VERSION.tgz $ALL
    if [ $? != 0 ]; then
        echo "! ERROR OCCURRED while tar"
        exit 1
    fi
    echo $PACKAGE-$VERSION.tgz in ".."
fi
