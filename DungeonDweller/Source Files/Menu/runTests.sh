#!/bin/bash

FNAME=$(date +%y%m%d) 
TO="Menu//"
cd "$TO"

ulimit -t 10
if [ $# -eq 2 ] 
then
    TO="$1"
    FROM="$2"
elif [ $# -eq 1 ] 
then
    TO="$1"
fi


echo "Pulling Git Repository"
git pull  

if [ $? -eq 0 ]
then
    cd "$TO"
    make clean-all
    make 

    cd -
fi
