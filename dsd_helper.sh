#!/bin/bash

#https://stackoverflow.com/questions/10278513/bash-shell-decimal-to-binary-conversion
function convertIntvalToBase () # (Val Base)
{
   local val=$1
   local base=$2
   local result=""
   while [ $val -ne 0 ] ; do
        result=$(( $val % $base ))$result #residual is next digit
        val=$(( $val / $base ))
   done
   #echo  $result
   return $result
}

function inverter()
 {	
	local temp=$1
	i=0
	x=
	until [[ "$temp" == "" ]]
	do
		c="${temp:0:1}"
		temp="${temp:1}"
		if [ $c -eq 1 ]
	    	then
			#number[$i]=0
			x="$x"0
		elif [ $c -eq 0 ]
	    	then 
			#number[$i]=1
			x="$x"1
		fi	
		i=$(( $i + 1 ))
	done
	echo " " $x
	return $x
 }
 if [ $1 = "man" ]
 	then
 	echo
 	echo usage:" "integer  base "      " '#'to get the integer in any base
 	echo usage 2:" "integer "base=2" -i  '#'to get inverse of integer in binary base
 	echo
 	else
 		if [ $3 !=  ]
 			then
 			#echo "3. is null"
 			convertIntvalToBase $1 $2
 			echo $1 in base $2 is $?
 		elif [ $3 = "-i" ]
 			then
 			if [  $2 -eq 2  ]
 				then
 			echo -n Inverse of $1 in base $2 is 
 			convertIntvalToBase $1 $2
 			inverter $?
 		fi

 	fi	
fi