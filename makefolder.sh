#! /bin/sh

TEMP="temp"

if [ -d $TEMP ]
then
	echo "directory is ready."
else
	mkdir $TEMP
	echo "directory is ready."
fi
