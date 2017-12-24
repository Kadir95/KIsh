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

void dataClear(void * data);

int main(int argc, char** argv) {
    
    ArrayList * list = arrayList_create(sizeof(char) * 5);
    char * c = "kadir";
    arrayList_append(list, c);
    arrayList_append(list, c);
    arrayList_append(list, c);
    arrayList_append(list, c);
    arrayList_append(list, c);
    
    c = "iremk";
    arrayList_insert(list, c, 2);
    
    printf("size : %d, lastElement : %d | %s\n",list->size, list->lastElement, list->data);
    
    c = "kadir";
    
    printf("%d\n", arrayList_getIndex(list, c));
    
    
    list->arrayList_nodeClear = dataClear;
    arrayList_clear(list);
    
    arrayList_append(list, c);
    arrayList_append(list, c);
    arrayList_append(list, c);
    arrayList_append(list, c);
    arrayList_append(list, c);
    c = "iremk";
    arrayList_insert(list, c, 2);
    
    printf("size : %d, lastElement : %d | %s\n",list->size, list->lastElement, list->data);
    
    arrayList_remove(list, 2);
    arrayList_remove(list, 2);
    arrayList_remove(list, 2);
    arrayList_remove(list, 2);
    
    printf("size : %d, lastElement : %d | %s\n",list->size, list->lastElement, list->data);
    
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

void dataClear(void * data){
    //free(data);
}