#!/bin/bash

pid=$1
isfd=$2
regex='^[0-9]+$'


if [ "$pid" = "" ]
then
	echo "parametrs not found"

	exit
elif ! [[ $pid =~ $regex ]]
then
	echo "   Enter correct PID!"

	exit
fi
if ps -p $pid > /dev/null
then
	
	echo -n "Name:    "
	ps -p $pid -o comm=
	echo "PID:     $pid"
	echo -n "PPID:   "
	ps -o ppid= -p $pid
else
	echo "  No process with PID = $pid"

	exit
fi


if [ "$isfd" = "fd" ]
then
	echo -n "FD:"
	ls -l /proc/$pid/fd | awk '{print $9}'
fi


echo -e "----------------------------\n"
