#!/bin/bash

# check if make, bison and cc are installed
if ! [ -x "$(command -v make)" ]; then
  echo 'test.sh: error: make is not installed.' >&2
  exit 1
fi

if ! [ -x "$(command -v bison)" ]; then
  echo 'test.sh: error: bison is not installed.' >&2
  exit 1
fi

if ! [ -x "$(command -v cc)" ]; then
  echo 'test.sh: error: No C compiler found.' >&2
  exit 1
fi


# check flags
make run-sanitize ARGS="-h"
make run-sanitize ARGS="--help"
make run-sanitize ARGS="-v"
make run-sanitize ARGS="--version"
make run-sanitize ARGS="-tf"
make run-sanitize ARGS="--astf"
make run-sanitize ARGS="-r"
make run-sanitize ARGS="--run"



# resolve and normalize path '../example' to absolute with relative to this script directory
testpath="$(cd "$(dirname "$0")" && pwd)/../examples"
testpath="$(realpath "$testpath")"

# run all scripts in ../examples/ using make run-sanitize ARGS="$filename"
for filename in "$testpath/"*.shsc; do
    echo -e "\n-----------------------------------------------------\n"
    echo -e ">> Running $filename\n"
    make run-sanitize ARGS="$filename"
done



# individual tests
echo -e "\n-----------------------------------------------------\n"
echo -e ">> Running $testpath/oop/\n"
make run-sanitize ARGS="$testpath/oop/*.shsc"



echo -e "\n-----------------------------------------------------\n"
echo -e ">> Running $testpath/inheritance/\n"
make run-sanitize ARGS="$testpath/inheritance/*.shsc -args 123 abc 1 2 3"



# new testpath, resolve and normalize, ../tests/
testpath="$(cd "$(dirname "$0")" && pwd)/../tests"
testpath="$(realpath "$testpath")"

# test the eaxmple at submodule lib/libshsc
echo -e "\n-----------------------------------------------------\n"
echo -e ">> Running lib/libshsc/examples/add.shsc\n"

# if pwd base is tests/, go up one level
if [[ "$PWD" == *tests ]]; then
    cd ..
fi

cd lib/libshsc
make cleaner; make dbg

# choose extension based on platform
if [[ "$OSTYPE" == "linux-gnu"* ]]; then
    cc -Iinclude -shared -fPIC -o examples/add.so examples/add.c -Ltarget -lshsc-dbg
elif [[ "$OSTYPE" == "msys" ]]; then
    cc -Iinclude -shared -fPIC -o examples/add.dll examples/add.c -Ltarget -lshsc-dbg
fi

../../target/shsc-dbg examples/add.shsc
rm -f examples/add.so examples/add.dylib examples/add.dll
cd ../../

# flag -tf test
echo -e "\n-----------------------------------------------------\n"
echo -e ">> Bulk running using examples/inheritance/listfile\n"
# run make run-sanitize ARGS="-tf tests/SyntaxTree.json -r examples/inheritance/listfile"
# test fails if theres a difference between old and new SyntaxTree.json
# this can be checked with git
make run-sanitize ARGS="-tf tests/SyntaxTree.json -r examples/inheritance/listfile -args 123 abc 1 2 3"

# check if there are any differences between old and new SyntaxTree.json
# if there are differences, the test fails
if ! git diff --quiet --exit-code tests/SyntaxTree.json; then
    echo 'test.sh: error: SyntaxTree.json has changed.' >&2
    exit 1
fi
