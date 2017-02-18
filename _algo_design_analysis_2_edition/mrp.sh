#!/bin/bash

if [ -z "$1" ]
then
	echo "Need argument..."
	exit -1
fi

g++ -Wall -g -o $1.elf $1.cpp && ./$1.elf
