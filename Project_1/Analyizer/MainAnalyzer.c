#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "../DataType/LinkedList.h"
#define ADDOP 1
#define RELOP 2
#define MULOP 3
#define GROUPING 4
#define INT


#include "./MainAnalyzer.h"

void analyzer(char readingBuffer[77], struct TokenReturn *Rtoken){// int *forwadPosition, int *backPosition){
  (*Rtoken).token = 0;
  (*Rtoken).atribute = NULL;
  whiteSpace(readingBuffer, Rtoken, forwadPosition, backPosition);
  addop(readingBuffer, Rtoken);
  if((*Rtoken).token != 0){
    return;
  }
  relop(readingBuffer, Rtoken);
  if((*Rtoken).token != 0){
    return;
  }
  mulop(readingBuffer, Rtoken);
  if((*Rtoken).token != 0){
    return;
  }
  grouping(readingBuffer, Rtoken);
  if((*Rtoken).token != 0){
    return;
  }
}

void whiteSpace(char readingBuffer[77], struct TokenReturn *Rtoken){
    while(readingBuffer[forwadPosition] == 32 || readingBuffer[forwadPosition] == 9){
        forwadPosition = forwadPosition + 1;
    }
    backPosition = forwadPosition;
}

void addop(char readingBuffer[77], struct TokenReturn *Rtoken){
    if(readingBuffer[forwadPosition] == 43){ //  +
        (*Rtoken).atribute = 0;
        (*Rtoken).token = ADDOP;
        forwadPosition += 1;
        strcpy((*Rtoken).tokenChars, "+");
    }//addition
    else if(readingBuffer[forwadPosition] == 45){ //  -
        (*Rtoken).atribute = 1;
        (*Rtoken).token = ADDOP;
        forwadPosition += 1;
        strcpy((*Rtoken).tokenChars, "-");
    }//subtraction
    backPosition = forwadPosition;
}

void relop(char readingBuffer[77], struct TokenReturn *Rtoken){
    if(readingBuffer[forwadPosition] == 61){ // =
        (*Rtoken).atribute = 0;
        (*Rtoken).token = RELOP;
        forwadPosition += 1;
        strcpy((*Rtoken).tokenChars, "=");
    }
    else if(readingBuffer[forwadPosition] == 60){ // <
        forwadPosition += 1;
        if(readingBuffer[forwadPosition] == 61){// <=
            forwadPosition += 1;
            (*Rtoken).atribute = 2;
            (*Rtoken).token = RELOP;
            strcpy((*Rtoken).tokenChars, "<=");
            backPosition = forwadPosition;
            return;
        }
        (*Rtoken).atribute = 1;
        (*Rtoken).token = RELOP;
        strcpy((*Rtoken).tokenChars,"<");
    }
    else if(readingBuffer[forwadPosition] == 62){ // <
        forwadPosition += 1;
        if(readingBuffer[forwadPosition] == 61){// <=
            forwadPosition += 1;
            (*Rtoken).atribute = 4;
            (*Rtoken).token = RELOP;
            strcpy((*Rtoken).tokenChars,">=");
            backPosition = forwadPosition;
            return;
        }
        (*Rtoken).atribute = 3;
        (*Rtoken).token = RELOP;
        strcpy((*Rtoken).tokenChars, "<");
    }
    backPosition = forwadPosition;
}

void mulop (char readingBuffer[77], struct TokenReturn *Rtoken){
    if(readingBuffer[forwadPosition] == 42){ //  *
        (*Rtoken).atribute = 0;
        (*Rtoken).token = MULOP;
        strcpy((*Rtoken).tokenChars,"*");
        forwadPosition += 1;
    }//addition
    else if(readingBuffer[forwadPosition] == 47){ //  /
        (*Rtoken).atribute = 1;
        (*Rtoken).token = MULOP;
        strcpy((*Rtoken).tokenChars,"/");
        forwadPosition += 1;
    }//subtraction
    backPosition = forwadPosition;
}

void grouping (char readingBuffer[77], struct TokenReturn *Rtoken){
    if(readingBuffer[forwadPosition] == 40){ //  (
        (*Rtoken).atribute = 0;
        (*Rtoken).token = GROUPING;
        strcpy((*Rtoken).tokenChars,"(");
        forwadPosition += 1;
    }
    else if(readingBuffer[forwadPosition] == 41){ //  )
        (*Rtoken).atribute = 1;
        (*Rtoken).token = GROUPING;
        strcpy((*Rtoken).tokenChars,")");
        forwadPosition += 1;
    }
    else if(readingBuffer[forwadPosition] == 123){ //  (
        (*Rtoken).atribute = 2;
        (*Rtoken).token = GROUPING;
        strcpy((*Rtoken).tokenChars,"{");
        forwadPosition += 1;
    }
    else if(readingBuffer[forwadPosition] == 125){ //  )
        (*Rtoken).atribute = 3;
        (*Rtoken).token = GROUPING;
        strcpy((*Rtoken).tokenChars,"}");
        forwadPosition += 1;
    }
    backPosition = forwadPosition;
}
