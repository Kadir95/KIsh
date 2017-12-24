/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   arrayList.h
 * Author: kadir
 *
 * Created on December 23, 2017, 3:45 PM
 */

#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <stddef.h>

#define ARRAY_START_SIZE    4

typedef struct {
    void *data;
    size_t dataSize;
    long lastElement;
    long size;
    void (* arrayList_nodeClear) (void * data);
} ArrayList;

typedef ArrayList* ArrayListPtr;

ArrayList * arrayList_create(size_t dataSize);
void arrayList_resize(ArrayList * array, long newSize);
void arrayList_append(ArrayList * array, void * data);
void arrayList_insert(ArrayList * array, void * data, long index);
// void arrayList_insert_arrayList(ArrayList * array, ArrayList * data, int startIndex, int endIndex);
int arrayList_getIndex(ArrayList * array, void * data);
void * arrayList_getData(ArrayList * array, long index);
void * arrayList_removeLast(ArrayList * array);
void * arrayList_removeFirst(ArrayList * array);
void arrayList_remove(ArrayList * array, long index);
void arrayList_clear(ArrayList * array);
void * arrayList_setToZero(ArrayList * array);


#endif /* ARRAYLIST_H */

