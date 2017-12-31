
#grep "<div class" $1 | awk '{print $3}'
#sed 's/'$1'/'$2'/g' $3 


#sed '/regex/{x;p;x;G;}' input.txt

#NUMBERING EACH LINE
#sed = input.txt| sed 'N; s/^/     /; s/ *\(.\{6,\}\)\n/\1  /'


#TRIM beginning of the lines 
#sed 's/^[ \t]*//' $1
#Trim end of line
#sed 's/[ \t]*$//'
#trim both
#sed 's/^[ \t]*//;s/[ \t]*$//'  


# substitute "foo" with "bar" ONLY for lines which contain "baz"
#sed '/div class/s/col-xs-8/BAAAAAAAR/g' input.txt
# substitute "foo" with "bar" EXCEPT for lines which contain "baz"
#sed '/baz/!s/foo/bar/g'


#gsed ':a;s/\B[0-9]\{3\}\>/,&/;ta'                     # GNU sed
#sed -e :a -e 's/\(.*[0-9]\)\([0-9]\{3\}\)/\1,\2/;ta' input.txt # other seds



#!/bin/bash
for file in *_*_*_*.txt ; do
    IFS=_ arr=($file)
    dir=${arr[0]}/${arr[1]}
    [[ -d $dir ]] || mkdir -p "$dir"
    cp "$file" "$dir"/
done