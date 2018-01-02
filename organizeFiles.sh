 #!/bin/bash
if [ "$1" == "man" ]
 	then
 	echo
 	echo "this command organizes the files in directory path you entered" 
 	echo "by their types into the directories"
 	echo "Usage: org /path/of/somewhere/directory"
 	echo
 elif [ -z $1 ]
 	then
 	echo "Enter the path you wanna be organized:"
	read path
	#echo $path
	cd
	cd $path
	ls
 	echo "Did you entered the path correctly,"
 	echo "otherwise results of the decision you give can be painful ? [Y\N]"
 	read answer
 	if [ "$answer" == "y" ]
 		then
 		a=
		for i in {1..4};do
			a=?$a
			#echo $a
			for file in *.$a ; do
    			[ -f "$file" ] || continue
    			dir="$(echo "$file" | rev | cut -c-$i | rev)"
    			mkdir -p "$dir" || { echo "Couldn't mkdir -p $dir; exiting" ; exit 1 ; }
    			mv -- "$file" "$dir"
			done
		done
		ls
 	fi
 		
fi	

./KIsh