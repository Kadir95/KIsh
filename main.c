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

int main(int argc, char** argv) {
    
    ArrayList * list = arrayList_create(sizeof(char));
    char c = 'k';
    char *ptr = &c;
    arrayList_append(list, ptr);
    arrayList_append(list, ptr);
    arrayList_append(list, ptr);
    arrayList_append(list, ptr);
    arrayList_append(list, ptr);
    
    c = 'l';
    arrayList_insert(list, ptr, 2);
    
    printf("%s\n", list->data);
    
    
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

