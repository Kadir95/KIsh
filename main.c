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
#include "exe.h"

/*
 * 
 */

int exitCheck(String * command);
void dataClear(void * data);
int execute(Command * cmd);

int main(int argc, char** argv) {
    String * str = createString();
    char buf[256];
    while (exitCheck(str)) {
        deleteCharInterval(str, 0, str->lastchar - 1);
        printf("%s@%s -<", getlogin(), getcwd(buf, 256));
        char inputChar = '\0';
        while (inputChar != '\n') {
            inputChar = getchar();
            if (inputChar != '\n') {
                addChar(str, inputChar, str->lastchar);
            }
        }
        printString(str);
        parser(str);
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

int execute(Command * cmd){
    //execvp(, getCommandArgumant(cmd));
    return system(getCommandExec(cmd));
}