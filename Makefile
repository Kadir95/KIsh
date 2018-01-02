KIsh : main.o arrayList.o dataTypes.o exe.o 
	gcc -o KIsh main.o arrayList.o dataTypes.o exe.o 

main.o : main.c dataTypes.h arrayList.h exe.h
	gcc -c main.c

arrayList.o : arrayList.c arrayList.h
	gcc -c arrayList.c

dataTypes.o : dataTypes.c dataTypes.h
	gcc -c dataTypes.c

exe.o : exe.c exe.h dataTypes.h reservedCharacters.h
	gcc -c exe.c

clean :
	rm KIsh main.o arrayList.o dataTypes.o exe.o 
