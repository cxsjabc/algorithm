#!/bin/bash

if [ -z "$1" ]
then
	echo "Need argument..."
	exit -1
fi

source common.sh
DEST=$1
shift

g++ $@ -x c++ -Wall -g -o $DEST.elf $DEST.cpp ${COMMON_C} && ./$DEST.elf
