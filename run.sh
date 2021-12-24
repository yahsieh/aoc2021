#!/bin/bash
set -eo pipefail

readonly PROG="`basename $0`"
source .env

usage_and_exit() {
	cat << EOF
Usage: $PROG <day> <test/run>
EOF
	exit 1
}

if [ $# -ne 2 ]; then
    usage_and_exit
fi
if [ ! -d "$1" ]; then
    echo "directory $1 doesn't exist"
    exit 1
fi
if [ ! -e "$1/$1.cpp" ]; then
    echo "$1.cpp doesn't exist"
    exit 1
fi

g++ -std=c++11 -Werror "$1/$1.cpp" -o "$1/a.out"
if [ $2 == "run" ]; then
    if [ ! -e "$1/input.txt" ]; then
        echo "downloading $1 input file"
        curl -sSL --cookie "session=$SESSION" "https://adventofcode.com/2021/day/${1#d}/input" -o "$1/input.txt"
    fi
    echo "running $1"
    "./$1/a.out" < "$1/input.txt"
elif [ $2 == "test" ]; then
    if [ ! -e "$1/test${1#d}" ]; then
        echo "testing $1"
        "./$1/a.out" < "$1/test${1#d}.txt"
    else
        echo "$1 test file doesn't exist"
    fi
else
    usage_and_exit
fi