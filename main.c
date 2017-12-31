/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: kadir
 *
 * Created on December 22, 2017, 9:59 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "dataTypes.h"
#include "arrayList.h"

/*
 * 
 */
int exitCheck(String * command);
void dataClear(void * data);
void func(String * str);

int main(int argc, char** argv) {

    String * str = createString();

    Command command;
    while (exitCheck(str)) {

        deleteCharInterval(str, 0, str->lastchar - 1);
        printf("%s <+", getlogin());
        char inputChar = '\0';
        while (inputChar != '\n') {
            inputChar = getchar();
            if (inputChar != '\n') {
                addChar(str, inputChar, str->lastchar);
            }
        }
        //printString(str);
        func(str);
    }

    printf("see you :)\n");
    return (EXIT_SUCCESS);
}

int exitCheck(String * command) {

    if (!strcmp(command->word, "exit")) {
        return 0;
    }
    return 1;
}

void dataClear(void * data) {
    //free(data);
}

void func(String * str) {
    //printf("string : %s\n", str->word);
    ArrayList * list = split(str, " ");
    for (int i = 0; i < list->lastElement; i++) {
        printf("token %d : %s\n", i, arrayList_getData(list, i));
    }

    char *dsd[] = {
        "/bin/bash",
        "./dsd_helper.sh",
        arrayList_getData(list, 1),
        arrayList_getData(list, 2),
        arrayList_getData(list, 3),
        NULL
    };

    char *killMe[] = {
        "/bin/bash",
        "./kill_user_processes.sh",
        arrayList_getData(list, 1),
        NULL
    };
    
    char *org[] = {
        "/bin/bash",
        "./organizeFiles.sh",
        arrayList_getData(list, 1),
        NULL
    };


    if (strcmp(arrayList_getData(list, 0), "dsd") == 0) { 
        execv(dsd[0], dsd);
    } else if (strcmp(arrayList_getData(list, 0), "killMe") == 0) {  
        execv(killMe[0], killMe);
    } else if (strcmp(arrayList_getData(list, 0), "org") == 0){
        execv(org[0], org);
    }

}
