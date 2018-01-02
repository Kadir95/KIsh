#/bin/bash

##	+<Value>		Value's type assumes as GB
##	-			Delete all additional swap area

if [ $# -lt 1 ]
then
	echo "Usage :"
	echo "To add swap area		+<Value>	example: +4"
	echo "To delete all areas	-"
	exit 0
fi

if [ -n "`echo $1 | grep "^[+][0-9]\+$"`" ]
then
	SIZE="`echo $1 | sed "s/+//g" `"
	sudo dd if=/dev/zero of=/swapfile.img bs=1024 count="${SIZE}"M
	sudo mkswap /swapfile.img
	sudo echo "/swapfile.img swap swap sw 0 0" >> /etc/fstab
	sudo swapon /swapfile.img
	echo "$SIZE GB swap area has been added"
elif [ -n "`echo $1 | grep "^[-]$"`" ]
then
	sudo swapoff /swapfile.img
	sudo sed "s/\/swapfile.img swap swap sw 0 0//g" /etc/fstab
	sudo rm /swapfile.img
	echo "DELETE SWAP"
fi