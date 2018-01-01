/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "arrayList.h"
#include "dataTypes.h"
#include "exe.h"
#include "reservedCharacters.h"

/*
 This function checks the entered command is correct or incorrect.
 */
int parser(String * string){
    ArrayList * pipe_list = pipe_list(string);
    return redirectors(pipe_list);
}
/*
 This function takes the whole expression with redirecters and pipelines.
 */
ArrayList * pipe_list(String * string){
    if(!string){
        return NULL;
    }
    
    ArrayList * pipe_list = split(string, PIPE_CHARACTER);
    return pipe_list;
}
/*
 This function takes the parted expression which processed by pipe_list function.
 */
ArrayList * redirectors(String * string){
    if(!string || ){
        return NULL;
    } else if(string->lastchar < 1){
        return string;
    }
    
    
    
}