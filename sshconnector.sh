#/bin/bash

function ssh_connection {
	##printf "password : $PASSWORD\nusername : $USERNAME\nport : $PORT\n"
	
	if [ -n "${SSHKEYDIR}" ]
	then
		ssh -i @SSHKEYDIR $USERNAME'@'$IP -p $PORT
	else
		ssh $USERNAME'@'$IP -p $PORT
	fi
}

function read_file {
	if ! [ -n "${1}" ]
	then
		echo "There is no file to read"
		exit 1
	fi
	
	IP="`cat $1 | sed -n '1p'`"
	PORT="`cat $1 | sed -n '2p'`"
	USERNAME="`cat $1 | sed -n '3p'`"
	PASSWORD="`cat $1 | sed -n '4p'`"
	SSHKEYDIR="`cat $1 | sed -n '5p'`"
	
}

function config_printer {
	printf " Select config file :\n"
	range=`ls -1 ${DEFAULTDIR} | wc -l`
	for (( i=1; i <= range; i++))
	do
		printf "$i ) `ls -1 ${DEFAULTDIR} | sed -n ${i}p` \n"
	done
	
	while [ $range -ne 0 ]
	do
		
		read -p "Selection : " SELECTION
		
		if [[ $SELECTION =~ ^[0-9]+$ ]]
		then
			if [ $SELECTION -lt $((`ls -1 $DEFAULTDIR | wc -l` + 1)) ] && [ $SELECTION -gt "-1" ]
			then
				return $SELECTION
			else
				echo "Please select number in range"
			fi
		else
			echo "Write a number"
		fi
	done 
	
}

##		-p		> Connection with password		-p example_password
##		-k		> Connection with SSH Key		-k /home/username/sshkey.key
##		-ip		> Server IP				-ip 255.255.255.255
##		-port		> Connection port			-port 22
##		-u		> User Name				-u client_user_name
##		-s		> Save					-s save_as_example_name
##		-sd		> Save under a dreciton			-sd /path/to/example_file_name
##		-c		> Conneciton with saved configs		-c /path/to/config/file.cfg
##		-lc		> List connection config files		-lc

##		Default config file saves under /home/username/.sshconnection direction
##		


if [ $# -eq 0 ]
then
	echo "SSH Connector Usage: bla bla bla ..."
fi

DEFAULTDIR="/home/$USER/.sshconnection/"

mkdir -p $DEFAULTDIR

IP=`hostname -I`
PORT=22
USERNAME=$USER
PASSWORD=
SSHKEYDIR=
SAVEDIR=$DEFAULTDIR
SAVEFILENAME="`date +Y%Y_M%m_H%H_Mi%M_S%S_NS%N`"
READFILEDIR=

SAVEFLAG=

for (( i=1; i <= $#; i++))
do
	if [ ${!i} = '-p' ]
	then
		j=$((i + 1))
		if [ -n "`echo ${!j} | grep ^[^-]`" ] 
		then
			echo "${!j} is found as password"
			PASSWORD=${!j}
			
		else
			echo ## No password found
		fi


	elif [ ${!i} = '-k' ]
	then
		j=$((i + 1))
		if [ -f ${!j} ]
		then
			echo "${!j} is found as SSHKEY file"
			SSHKEYDIR=${!j}
		else
			echo ## No file found
		fi


	elif [ ${!i} = '-ip' ]
	then
		j=$((i + 1))
		if [ -n "`echo ${!j} | grep -oE "\b((25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.){3}(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\b"`" ]
		then
			echo "${!j} is found as ip"
			IP=${!j}
		else
			echo ## No ip found
		fi


	elif [ ${!i} = '-port' ]
	then
		j=$((i + 1))
		if [ -n "`echo ${!j} | grep "^[0-9]*$"`" ]
		then
			echo "${!j} is found as port"
			PORT=${!j}
		else
			echo ## No file found
		fi


	elif [ ${!i} = '-u' ]
	then
		j=$((i + 1))
		if [ -n "`echo ${!j} | grep ^[^-]`" ]
		then
			echo "${!j} is found as user name"
			USERNAME=${!j}
		else
			echo ## No file found
		fi


	elif [ ${!i} = '-s' ]
	then
		j=$((i + 1))
		SAVEFLAG=T
		if [ -n "`echo ${!j} | grep ^[^-][^/]*$`" ]
		then
			echo "${!j} is found as save file name"
			SAVEFILENAME=${!j}
		else
			echo ## No file found
		fi


	elif [ ${!i} = '-sd' ]
	then
		j=$((i + 1))
		SAVEFLAG=T
		if [ -n "`echo ${!j} | grep ^[^-]`" ]
		then
			echo "${!j} is found as save directory"
			SAVEDIR=${!j}
		else
			echo ## No file found
		fi


	elif [ ${!i} = '-c' ]
	then
		j=$((i + 1))
		if [ -n "`echo ${!j} | grep ^[^-]`" ]
		then
			echo "${!j} is found as save directory"
			READFILEDIR=${!j}
		else
			echo ## No file found
		fi


	elif [ ${!i} = '-lc' ]
	then
		config_printer
		READFILEDIR="$DEFAULTDIR"`ls -1 ${DEFAULTDIR} | sed -n ${?}p`""
		read_file $READFILEDIR
	fi
	
done

if [ -n "${SAVEFLAG}" ]
then 
	FILENAME="$SAVEDIR$SAVEFILENAME"
	printf "$IP\n$PORT\n$USERNAME\n$PASSWORD\n$SSHKEYDIR" > $FILENAME
fi

ssh_connection

