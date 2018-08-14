#!/bin/bash

FNAME=$(date +%y%m%d) 
TO="Menu GameState Room RoomTree Image ImageImporter Puzzles Cutscene"
MAIN="/home/ghost/Documents/DungeonDweller/"

cd $MAIN
if [ $? -eq 0 ]
then
    for d in $TO
    do
	(cd "$d" && make clean-all)
    done

fi
