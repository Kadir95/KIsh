/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   exe.h
 * Author: mzp7
 *
 * Created on December 31, 2017, 9:35 PM
 */

#ifndef EXE_H
#define EXE_H

#include "arrayList.h"

/*
 This function checks the entered command is correct or incorrect.
 */
int parser(String * string);
/*
 This function takes the whole expression with redirecters and pipelines.
 */
ArrayList * pipe_list(String * string);
/*
 This function takes the parted expression which processed by pipe_list function.
 */
ArrayList * redirectors(String * string);

#endif /* EXE_H */

