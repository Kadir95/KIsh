#/bin/bash

##	Script takes a directory as argument. It will separate source codes to code folder, 
##	documentation files to doc folder and others to etc folder.

mkdir -p doc
mkdir -p code

echo "`ls -1 . | grep ".*\.pdf$\|.*\.doc$\|.*\.odt$\|.*\.docx$"`"
mv -t ./doc/ `ls -1 . | grep ".*\.pdf$\|.*\.doc$\|.*\.odt$\|.*\.docx$"`

echo "`ls -1 . | grep ".*\.c$\|.*\.h$\|.*\.cpp$\|.*\.java$\|.*\.py$\|.*\.r$\|.*\.sh$\|.*\.bin$"`"
mv -t ./doc/ `ls -1 . | grep ".*\.c$\|.*\.h$\|.*\.cpp$\|.*\.java$\|.*\.py$\|.*\.r$\|.*\.sh$\|.*\.bin$"`
