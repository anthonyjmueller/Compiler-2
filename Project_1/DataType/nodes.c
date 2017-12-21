#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "nodes.h"
#include "LinkedList.h"

int checkAddGreenNode(){
    struct node *newSpace = malloc(sizeof(struct node));

    if(currGreen == NULL){ //First call from program
        currGreen = malloc(sizeof(struct node));
        (*currGreen).level = level;
        (*currGreen).nodeType = 1;
        (*currGreen).offset = offset;
        (*currGreen).lexID = (*returnedToken).atribute;
        strcpy((*currGreen).name ,(*returnedToken).tokenChars);
        (*currGreen).prev = NULL;

        (*newSpace).nodeType = 3;

        currEnd = newSpace;
        (*currGreen).next = newSpace;
        (*currEnd).prev = currGreen;
        return 1;
    }else{   /////////////////////////////////////////procedure calls
        struct node *iter = malloc(sizeof(struct node));
        iter = currEnd;
        while((*iter).lexID != 10){
            if((*iter).nodeType == 1){ //if blue node
                if(strcmp((*iter).name, (*returnedToken).tokenChars) == 0){
                    fprintf(writePtr, "     SYMERROR:   Procedure name already used ");
                    fprintf(writePtr, (*iter).name);
                    fprintf(writePtr, "\n");
                    (*newSpace).nodeType = 3;

                    (*currEnd).next = newSpace;
                    (*newSpace).prev = currEnd;
                    currEnd = newSpace;
                    return -1;
                }
            }
            iter = (*iter).prev;
        }
       if((*iter).nodeType == 1){ //if blue node
            if(strcmp((*iter).name, (*returnedToken).tokenChars) == 0){
                fprintf(writePtr, "     SYMERROR:   Procedure name already used ");
                fprintf(writePtr, (*iter).name);
                fprintf(writePtr, "\n");
                (*newSpace).nodeType = 3;

                (*currEnd).next = newSpace;
                (*newSpace).prev = currEnd;
                currEnd = newSpace;
                return -1;
            }
        }

        struct node *newGreen = malloc(sizeof(struct node));
        (*newGreen).nodeType = 1;
        (*newGreen).offset = offset;
        (*newGreen).level = level;
        (*newGreen).lexID = (*returnedToken).atribute;
        strcpy((*newGreen).name, (*returnedToken).tokenChars);
        (*currEnd).next = newGreen;
        (*newGreen).prev = currEnd;
        currEnd = newGreen;
        currGreen = newGreen;
        //Adds new space node
        (*newSpace).nodeType = 3;

        currEnd = newSpace;
        (*currGreen).next = newSpace;
        (*currEnd).prev = currGreen;
        //

        return 1;
    }

};

int checkAddBlueNode(int type){
    struct node *iter = malloc(sizeof(struct node));
    iter = currEnd;
    while((*iter).nodeType != 1){
        if((*iter).nodeType == 2){ //if blue node
            if(strcmp((*iter).name, (*returnedToken).tokenChars) == 0){
                //fprintf(writePtr, "     SYMERROR:   Variable name already used ");
                //fprintf(writePtr, (*iter).name);
                //fprintf(writePtr, "\n");
                return -1;
            }
        }

        iter = (*iter).prev;
    }

    struct node *newBlue = malloc(sizeof(struct node));
    (*newBlue).nodeType = 2;
    (*newBlue).varType = type;
    (*newBlue).offset = offset;
    (*newBlue).lexID = (*returnedToken).atribute;
    strcpy((*newBlue).name, (*returnedToken).tokenChars);
    (*currEnd).next = newBlue;
    (*newBlue).prev = currEnd;
    currEnd = newBlue;
    printMemFile();
    return 1;
};

////////do not call at program end, only procedure ends
void popScope(){
    struct node currPos;
    currPos = *currEnd;
    if(currPos.lexID != 10){
        while(currPos.nodeType != 3){
            currPos = (*currPos.prev);
        }
        currPos = *currPos.prev;
        *currEnd = currPos;
    }

    offset = (*currGreen).offset;
    if((*currGreen).lexID != 10){
        while(currPos.nodeType != 3){
            currPos = *currPos.prev;
        }
        currPos = *currPos.prev;
        currGreen = &currPos;
    }
};

int getType(){
    struct node *iter = malloc(sizeof(struct node));
    iter = currEnd;
    while((*iter).prev != NULL){
        if((*iter).nodeType == 2){ //if blue node
            if(strcmp((*iter).name, (*returnedToken).tokenChars) == 0){
                return (*iter).varType;
            }
        }
        iter = (*iter).prev;
    }
    return 0;
    /////////////////////Error variable not found
};

struct node* getProc(){
    struct node *iter = malloc(sizeof(struct node));
    iter = currEnd;
    while((*iter).prev != NULL){
        if((*iter).nodeType == 1){ //if blue node
            if(strcmp((*iter).name, (*returnedToken).tokenChars) == 0){
                return iter;
            }
        }
        iter = (*iter).prev;
    }
    return NULL;
};

void InitMemFile(){
    fprintf(memwritePtr, "Line Number     ");
    fprintf(memwritePtr, "Variable name   ");
    fprintf(memwritePtr, "Offset          ");
    fprintf(memwritePtr, "\n");
};

void printMemFile(){
    fprintf(memwritePtr, lineNum);
    fprintf(memwritePtr, ".");
    int numDigits = strlen(lineNum);
    for(; numDigits < 15; numDigits++){
        fprintf(memwritePtr, " ");
    }

    numDigits = strlen((*currEnd).name);
    fprintf(memwritePtr, (*currEnd).name);
    for(; numDigits < 16; numDigits++){
        fprintf(memwritePtr, " ");
    }
    char offs[10];
    sprintf(offs, "%ld%", (*currEnd).offset);
    numDigits = strlen(offs);
    fprintf(memwritePtr, offs);
    for(; numDigits < 16; numDigits++){
        fprintf(memwritePtr, " ");
    }
    fprintf(memwritePtr, "\n");
}
