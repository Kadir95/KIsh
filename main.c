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

/*
 * 
 */

int main(int argc, char** argv) {
    
    String * str = createString();
    
    addChar(str, 'd');
    addChar(str, 'e');
    addChar(str, 'n');
    addChar(str, 'i');
    addChar(str, 'z');
    addChar(str, 'd');
    addChar(str, 'e');
    addChar(str, 'n');
    addChar(str, 'i');
    addChar(str, 'z');
    addChar(str, 'd');
    addChar(str, 'e');
    addChar(str, 'n');
    addChar(str, 'i');
    addChar(str, 'z');
    printString(str);
    
    deleteCharInterval(str, 1, 3);
    
    printString(str);
    /*
    Command command;
    while (exitCheck(command)){
        printf("%s | %s <+",getlogin() ,get_current_dir_name());
        char inputChar = '\0';
        while(inputChar != '\n'){
            inputChar = getchar();
            if(inputChar != '\n'){
                
            }
        }
    }
    */
    return (EXIT_SUCCESS);
}

int exitCheck(Command command){
    if(!command.argn){
        return 1;
    }
    
    if(strcmp(command.command[0], "exit")){
        return 0;
    }
    
    return 1;
}

