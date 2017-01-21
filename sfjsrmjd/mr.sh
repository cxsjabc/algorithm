#!/bin/bash

if [ -z "$1" ]
then
	echo "Need argument..."
	exit -1
fi

gcc -Wall -g -o $1 $1.c && ./$1
