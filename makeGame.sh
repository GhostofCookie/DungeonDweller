#!/bin/bash

FNAME=$(date +%y%m%d) 
TO="Menu  Room RoomTree   Puzzles "
MAIN="/home/rigt2720/Kodika"

cd $MAIN
if [ $? -eq 0 ]
then
    for d in $TO
    do
	(cd "$d" && make clean-all)
	(cd "$d" && make )
	(cd "$d" && ./testHeaders);
    done

fi

cd $MAIN
echo "Pulling Git Repository"
git add --all
git commit -m "Automated Make call to all directories in Kodika. Pre-Pull"
git pull  

cd $MAIN
git add --all
git commit -m "Automated Make call to all directories in Kodika. Pre-Push"
git push
