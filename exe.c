/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "arrayList.h"
#include "dataTypes.h"
#include "exe.h"
#include "reservedCharacters.h"

/*
 This function checks the entered command is correct or incorrect.
 */
int parser(String * string) {
    /*ArrayList * pipelist = pipe_list(string);
      return redirectors(pipelist[i]);
    }*/




    ArrayList * list = split(string, " ");
    //for (int i = 0; i < list->lastElement; i++) {
    //printf("token %d : %s\n", i, arrayList_getData(list, i));
    //}
    char *dsd[] = {
        "/bin/bash",
        "./dsd_helper.sh",
        arrayList_getData(list, 1),
        arrayList_getData(list, 2),
        arrayList_getData(list, 3),
        NULL
    };

    char *killMe[] = {
        "/bin/bash",
        "./kill_user_processes.sh",
        arrayList_getData(list, 1),
        NULL
    };

    char *org[] = {
        "/bin/bash",
        "./organizeFiles.sh",
        arrayList_getData(list, 1),
        NULL
    };


    /*
     ADD YOUR char ARRAYS HERE...
     *and call them with your error handlings in below where I left a comment end of the method for it  |
     *                                                                                                  V
     */

    //KADIR'S SCRIPTS
    char * AssignmentKeeper[] = {
        "/bin/bash",
        "./AssignmentKeeper.sh",
        NULL
    };

    char *sshConnector[] = {
        "/bin/bash",
        "./sshconnector.sh",
        arrayList_getData(list, 1),
        arrayList_getData(list, 2),
        arrayList_getData(list, 3),
        arrayList_getData(list, 4),
        arrayList_getData(list, 5),
        arrayList_getData(list, 6),
        NULL
    };

    char * addSwap[] = {
        "/bin/bash",
        "./addSwap.sh",
        arrayList_getData(list, 1),
        NULL
    };




    /*
     * In here I keep the arguments one by one to use them for error handling
     */
    String * arg1 = arrayList_getData(list, 1);
    //printf("ARG 1: %s",arrayList_getData(list, 1)->word);
    String * arg2 = arrayList_getData(list, 2);
    String * arg3 = arrayList_getData(list, 3);


    /*
     This part is about error handling of dsd_helper.sh script
     */
    if (strcmp(arrayList_getData(list, 0), "dsd") == 0) {
        if (!strcmp(arg1, "man")) {
            execv(dsd[0], dsd);
        } else if (strcmp(arg1, "man") && isNumeric(arg1) == 1 && isNumeric(arg2) == 1) {
            execv(dsd[0], dsd);
        } else if ((isNumeric(arg1) == 0 || isNumeric(arg2) == 0) && strcmp(arg1, "man")) {
            printf("-KIsh: %s : command not found\n", arrayList_getData(list, 1));
            return -1;
        }

        //////////////////////////////////////////////////////////////////////////////////////
        if (!strcmp(arg3, "-i")) {
            printf("-KIsh: %s : Wrong parameter usage!\n", arrayList_getData(list, 3));
            return -1;
        } //bu kisim calismiyor  bu -> if (strcmp(arg3, "-i")) ve bu-> if (!strcmp(arg3, "-i"))  
        //bi sey farketmedi parametrenin yanlıs girilmesinde print basmıyo ama kodu calistirmiyor en azindan 
        return 0;
    } else if (strcmp(arrayList_getData(list, 0), "killMe") == 0) {
        /*if (arg1 && strcmp(arg1, "man")) {
            printf("-KIsh: %s : command not found\n", arrayList_getData(list, 1));
            return -1;
        }*/
        execv(killMe[0], killMe);
        return 0;
    } else if (strcmp(arrayList_getData(list, 0), "org") == 0) {
        if (arg1 && strcmp(arg1, "man")) {
            printf("-KIsh: %s : command not found\n", arrayList_getData(list, 1));
            return -1;
        }
        execv(org[0], org);
        return 0;
    } else if (strcmp(arrayList_getData(list, 0), "assk") == 0) { ///KADIR's SCRIPTS /////
        printf("hello");
        execv(AssignmentKeeper[0], AssignmentKeeper);
        return 0;
    } else if (strcmp(arrayList_getData(list, 0), "sshc") == 0) {
        execv(sshConnector[0], sshConnector);
        return 0;
    } else if (strcmp(arrayList_getData(list, 0), "adds") == 0) {
        execv(addSwap[0], addSwap);
        return 0;
    }
    /////////////////////////////////////////////////////////////



    return -1; //Last one more note: I used it when the comamnd okay to execute then parser returns 0
    //other wise it returns -1 
    // you can change it if you want 
    // :)    
}//parser method ends

/*
 This function takes the whole expression with redirecters and pipelines.
 */
ArrayList * pipe_list(String * string) {
    if (!string) {
        return NULL;
    }

    ArrayList * pipe_list = split(string, PIPE_CHARACTER);
    return pipe_list;
}

/*
 This function takes the parted expression which processed by pipe_list function.
 */

/*ArrayList * redirectors(String * string) {
    if (!string /*||* /) {
        return NULL;
    } else if (string->lastchar < 1) {
        return string;
    }
    
}*/

int isNumeric(String * arg) {
    int isDigit, j = 0;
    int i = atoi(&arg);
    while (j < strlen(arg)) {
        isDigit = isdigit(i);
        if (isDigit == 0) break;
        j++;
    }
    if (j < strlen(arg) - 1) {
        //printf("One of the arg is not a integer\n");
        return 0;
    }
    return 1;
}