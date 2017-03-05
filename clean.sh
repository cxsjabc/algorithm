#!/bin/bash

if [ -z $1 ]; then
DIR=.
else
DIR=$1
fi

echo "DIR:${DIR}"

ELF="*.elf"
DSYM="*.dSYM"

FILES=`find $DIR -name $ELF -or -name $DSYM` 
#echo "FILES:$FILES"
echo $FILES | xargs rm -rf

#rm -rf *.elf
#rm -rf *.dSYM
