#!/bin/bash

FNAME=$(date +%y%m%d) 
TO="Menu GameState Room RoomTree Image ImageImporter Puzzles Cutscene"
MAIN = "/home/rigt2720/Kodika"
cd "$MAIN"
echo "Pulling Git Repository"
git pull  

if [ $? -eq 0 ]
then
    for d in $TO
    do
	(cd "$d" && make clean-all)
	(cd "$d" && make )
    done

    cd -
fi

cd "$MAIN"
git add --all
git commit -m "Automated Make call to all directories in Kodika."
git push
