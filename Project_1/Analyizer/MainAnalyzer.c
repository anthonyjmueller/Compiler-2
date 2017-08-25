#include<stdlib.h>
#include<stdio.h>
#include "../DataType/LinkedList.h"
#define ADDOP 1

#include "./MainAnalyzer.h"

void analyzer(char readingBuffer[77], struct TokenReturn *Rtoken, int forwadPosition, int backPosition){
  (*Rtoken).token = 0;
  (*Rtoken).atribute = NULL;
  whiteSpace(readingBuffer, Rtoken, forwadPosition, backPosition);
  addop(readingBuffer, Rtoken);
}

void whiteSpace(char readingBuffer[77], struct TokenReturn *Rtoken, int forwadPosition, int backPosition){
    while(readingBuffer[forwadPosition] == 32 || readingBuffer[forwadPosition] == 9){
        forwadPosition = forwadPosition + 1;
    }
    backPosition = forwadPosition;
}

void addop(char readingBuffer[77], struct TokenReturn *Rtoken, int forwadPosition, int backPosition){
    if(readingBuffer[forwadPosition] == 43){
        (*Rtoken).atribute = 0;
        (*Rtoken).token = ADDOP;
    }//addition
    if(readingBuffer[forwadPosition] == 45){
        (*Rtoken).atribute = 1;
        (*Rtoken).token = ADDOP;
    }//subtraction
}
