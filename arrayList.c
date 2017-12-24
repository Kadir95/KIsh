/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "arrayList.h"
#include "dataTypes.h"

/*
 Create arraylist. Default size is 4
 */
ArrayList * arrayList_create(size_t dataSize){
    ArrayList * created = (ArrayList *) malloc(sizeof(ArrayList));
    created->dataSize = dataSize;
    created->lastElement = 0;
    created->size = ARRAY_START_SIZE;
    created->data = malloc(created->dataSize * ARRAY_START_SIZE);
    created->arrayList_nodeClear = NULL;
    arrayList_setToZero(created);
    return created;
}

/*
 Resize the given arraylist 
 */
void arrayList_resize(ArrayList * array, long newSize){
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
void arrayList_insert(ArrayList * array, void * data, long index){
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

/*
 Returns the index of the given data
 */
int arrayList_getIndex(ArrayList * array, void * data){
    if(!data){
        return -1;
    }
    if(!array){
        return -1;
    }
    
    for(int i = 0; i < array->lastElement; i++){
        if(!memcmp(array->data + array->dataSize * i, data, array->dataSize)){
            return i;
        }
    }
    return -1;
}

/*
 
 */
void * arrayList_getData(ArrayList * array, long index){
    if(array->lastElement <= index || index < 0){
        return NULL;
    }
    if(!array){
        return NULL;
    }
    
    void * result = malloc(array->dataSize);
    
    memcpy(result, array->data + array->dataSize * index, array->dataSize);
    
    return result;
}

/*
 
 */
void * arrayList_removeLast(ArrayList * array);
void * arrayList_removeFirst(ArrayList * array);
void arrayList_remove(ArrayList * array, long index){
    if(!array->arrayList_nodeClear){
        fprintf(stderr, "Warning at arrayList_remove : Node clear function wasn't initialized \n\t if data have any pointer pointed datas won't be cleared!!\n");
    } else {
        array->arrayList_nodeClear(array->data + (array->dataSize * index));
    }
    
    if(array->lastElement - 1 > index){
        memmove(array->data + (array->dataSize * index), array->data + (array->dataSize * (index + 1)), array->dataSize * (array->lastElement -(index + 1)) );
    }
    memset(array->data + array->dataSize * (array->lastElement - 1), 0, array->dataSize);
    
    array->lastElement--;
    
    if(array->lastElement < array->size / 2){
        arrayList_resize(array, array->size / 4 * 3);
    }
    
}
void arrayList_clear(ArrayList * array){
    if(!array->arrayList_nodeClear){
        fprintf(stderr, "Error at arrayList_clear : Node clear function wasn't initialized \n");
    }
    
    for(int i = 0; i < array->lastElement; i++){
        array->arrayList_nodeClear(array->data + (array->dataSize * i));
    }
    
    size_t dataSize = array->dataSize;
    void (*nodeClearFunc) (void * data) = array->arrayList_nodeClear;
    
    free(array->data);
    free(array);
    
    array = arrayList_create(dataSize);
    array->arrayList_nodeClear = nodeClearFunc;
    
    return;
}
void * arrayList_setToZero(ArrayList * array){  // set all array values to zero with memset 
    memset(array->data, 0, array->dataSize * array->size);
}