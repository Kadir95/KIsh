/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdlib.h>
#include <string.h>

#include "arrayList.h"

/*
 Create arraylist. Default size is 4
 */
ArrayList * arrayList_create(size_t dataSize){
    ArrayList * created = (ArrayList *) malloc(sizeof(ArrayList));
    created->dataSize = dataSize;
    created->lastElement = 0;
    created->size = ARRAY_START_SIZE;
    created->data = malloc(created->dataSize * ARRAY_START_SIZE);
    arrayList_setToZero(created);
    return created;
}

/*
 Resize the given arraylist 
 */
void arrayList_resize(ArrayList * array, int newSize){
    void * newArray = malloc(array->dataSize * newSize);
    memcpy(newArray, array->data, array->size < newSize ? (array->size * array->dataSize) : (newSize * array->dataSize));
    free(array->data);
    array->data = newArray;
    array->size = newSize;
}

/*
 Append a data at the end of the array
 */
void arrayList_append(ArrayList * array, void * data){
    if(array->lastElement == array->size){
        arrayList_resize(array, array->size * 2);
    }
    
    memcpy(array->data + array->dataSize * (array->lastElement), data, array->dataSize);
    array->lastElement++;
}

/*
 Insert one or more data to the arraylist corresponding to start and end indexes. If the start index just in front of the end index insert the data  
 */
void arrayList_insert(ArrayList * array, void * data, int index){
    if(array->lastElement <= index || index < 0){
        return;
    }
    
    if(!data){
        return;
    }
    
    if(array->lastElement == array->size){
        arrayList_resize(array, array->size * 2);
    }
    
    memmove(array->data + array->dataSize * (index + 1), array->data + array->dataSize * (index), array->dataSize * (array->lastElement - index));
    memcpy(array->data + array->dataSize * index, data, array->dataSize);
    array->lastElement++;
}
int arrayList_getIndex(ArrayList * array, void * data);
void * arrayList_removeLast(ArrayList * array);
void * arrayList_removeFirst(ArrayList * array);
void * arrayList_remove(ArrayList * array, int index);
void * arrayList_clear(ArrayList * array);
void * arrayList_setToZero(ArrayList * array){  // set all array values to zero with memset 
    memset(array->data, 0, array->dataSize * array->size);
}