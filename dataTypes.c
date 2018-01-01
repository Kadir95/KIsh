/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dataTypes.h"

// Command Data Type Codes
Command * createCommand(){
    Command * created = (Command *) malloc(sizeof(Command));
    created->list = arrayList_create(sizeof(String));
    created->list->arrayList_nodeClear = deleteString;
    return created;
}
void deleteCommand(Command * command){
    arrayList_clear(command->list);
    free(command->list);
    free(command);
}
char * getCommandExec(Command * command){
    if(command->list->lastElement < 1){
        fprintf(stderr, "There is no executible\n");
    }
    
    return ((String *) arrayList_getData(command->list, 0))->word;
}
char ** getCommandArgumant(Command * command){
    if(command->list->lastElement < 2){
        return NULL;
    }
    
    char **result = (char **) malloc(sizeof(char *) * command->list->lastElement - 1);
    for(int i = 0; i < command->list->lastElement - 1; i++){
        result[i] = ((String *) arrayList_getData(command->list, i))->word;
    }
    
    return result;
}
void addCommandArgumant(Command * command, char * argumant){
    if(command->list->lastElement < 1){
        fprintf(stderr, "There is no executable to add argument!");
        return;
    }
    String * temp = createString();
    addCharArray(temp, argumant, 0);
    arrayList_append(command->list, temp);
    return;
}
void addCommandExec(Command * command, char * exec){
    if(command->list->lastElement > 0){
        fprintf(stderr, "Command already have an executable!");
        return;
    }
    
    String * temp = createString();
    addCharArray(temp, exec, 0);
    printString(temp);
    arrayList_insert(command->list, temp, 0);
    printString(arrayList_getData(command->list, 0));
    return;
}




// String Data Type Codes
String * createString(){
    String * created = (String *) malloc(sizeof(String));
    created->lastchar = 0;
    created->size = 10;
    created->word = (char *) malloc(sizeof(char) * 10);
    
    memset(created->word, 0, sizeof(char) * 10);    // Set to null all char values
    
    return created;
}
void stringExterner(String * string, int externSize){
    if(!string){
        fprintf(stderr, "There is no string to extern!\n");
        return;
    }
    
    char * newWord = (char *) malloc(sizeof(char) * externSize);
    memset(newWord, 0, sizeof(char) * externSize);  // Set to null all new char values 
    
    if(string->word){
        memcpy(newWord, string->word, externSize < string->size ? externSize : string->size);   // Old values copy to new area 
    } else {
        string->word = newWord;     // if word is a null pointer, new char array directly will be pointed
    }
    
    string->size = externSize;
}
void addChar(String * string, char c, int index){
    if(!string){
        fprintf(stderr, "There is no string to extern!\n");
        return;
    }
    
    if(string->lastchar >= string->size){
        stringExterner(string, string->size * 2);
    }
    
    string->word[string->lastchar] = c;
    string->lastchar++;
}
void deleteString(String * string){
    free(string->word);
    free(string);
}
int deleteChar(String * string, int index){
    if(index >= string->lastchar || index < 0) {
        return 1;
    }
    
    if(string->lastchar -1 > index){
        memmove(string->word + sizeof(char) * (index), string->word + sizeof(char) * (index + 1), sizeof(char) * (string->lastchar - index + 1));
    } else {
        string->word[index] = 0;
    }
    
    string->lastchar--;
    
    return 0;
}
ArrayList * split(String * string, char * arg){
    char * token = strtok(string->word, arg);
    ArrayList * list = arrayList_create(sizeof(String));
    while(token){
        String * temp = createString();
        addCharArray(temp, token, 0);
        token = strtok(NULL, arg);
        arrayList_append(list, temp);
        free(temp);
    }
    return list;
}
/*
ArrayList * split(String * string, char * arg){
    char * tooken = strtok(string->word, arg);
    ArrayList * list = arrayList_create(sizeof(char *));
    while(tooken){
        arrayList_append(list, tooken);
        //printf("%s\n", temp);
        tooken = strtok(NULL, arg);
    }
    return list;
}
*/

int deleteCharInterval(String * string, int start, int end){
    if(start > end){
        int temp = start;
        start = end;
        end = temp;
    }
    
    if(start < 0 || start >= string->lastchar ||  end < 0 || end >= string->lastchar){
        return 1;
    }
    
    memmove(string->word + sizeof(char) * (start), string->word + sizeof(char) * (end + 1), sizeof(char) * (string->lastchar - start + 1));
    
    string->lastchar -= (end - start + 1);
    
    return 0;
}
void addCharArray(String * string, char * word, int index){
    if(index >= string->size || index < 0) {
        return ;
    }
    
    int wordSize = strlen(word);
    
    if(wordSize < 1){
        return;
    }
    
    while(string->lastchar + wordSize >= string->size){
        stringExterner(string, string->size * 2);
    }
    
    if(index == string->lastchar){
        strcpy(string, word);
        //memcpy(string->word + sizeof(char) * index, word, sizeof(char) * wordSize);
    } else {
        memmove(string->word + sizeof(char) * (index + wordSize), string->word + sizeof(char) * (index), sizeof(char) * (string->lastchar - index));
        memcpy(string->word + sizeof(char) * index, word, sizeof(char) * wordSize);
    }
    
    string->lastchar += wordSize;
    
}
int locateFirstChar(String * string, char c){
    
}
int locateLastChar(String * string, char c);
void printString(String * string){
    printf("lastchar : %d, size : %d | %s\n", string->lastchar, string->size, string->word);
}