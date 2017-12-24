/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   dataTypes.h
 * Author: kadir
 *
 * Created on December 22, 2017, 10:03 PM
 */

#ifndef DATATYPES_H
#define DATATYPES_H

typedef struct {
    char **command;
    int argn;
}Command;

Command * createCommand();
void commandExterner(Command * command);
void deleteCommand(Command * command);
char * getCommandArgumant(Command * command);
void addCommandArgumant(Command * command, char * argumant);


typedef struct {
    char *word;
    int lastchar;
    int size;
}String;

String * createString();
void stringExterner(String * string, int externSize);
void addChar(String * string, char c, int index);
void deleteString(String * string);
int deleteChar(String * string, int index);
int deleteCharInterval(String * string, int start, int end);
void addCharArray(String * string, char * word, int index);
int locateFirstChar(String * string, char c);
int locateLastChar(String * string, char c);
void printString(String * string);

#endif /* DATATYPES_H */

