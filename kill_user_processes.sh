#!/bin/bash

if [ "$1" == "man" ]
 	then
 	echo
 	echo "this command kills each process of USER!" 
 	echo "it's recomended to use when you are working on a server" 
 	echo "with your own user name" 
 	echo "otherwise it may be dangerous on your local host" 
 	echo
 elif [ -z $1 ]
 	then
 	echo "Are you sure to kill each USER process? [Y\N]"
 	read answer
 	if [ "$answer" == "y" ]
 		then
 		ps aux  | grep $(whoami) | awk '{print $0}' > pid.txt
		for pid in $(cat pid.txt); do pkill $pid; done
 	fi
 		
fi	

./a.out

#startx