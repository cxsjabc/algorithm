#!/bin/bash

if [ -z $1 ]
then
	echo "No argument..."
	exit -1
fi

DEST=$1
shift

gcc -o $DEST.c.simple.elf $DEST.c $@

if [ $? -eq 0 ]
then
./$DEST.c.simple.elf
fi
