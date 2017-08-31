#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "LinkedList.h"
#define ADDOP 1
#define RELOP 2
#define MULOP 3
#define GROUPING 4
#define INT 5
#define REAL 6
#define CONTROL 7
#define VAR 8
#define ARRAY 9
#define TYPE 10
#define FUNCTION 11
#define NOT 12
#define PUNC 13
#define ASSIGNOP 14
#define EOF 15
#define LEXERROR 16


#include "./MainAnalyzer.h"

void analyzer(char readingBuffer[77], struct TokenReturn *Rtoken){// int *forwadPosition, int *backPosition){
  (*Rtoken).token = 0;
  (*Rtoken).atribute = NULL;
  whiteSpace(readingBuffer, Rtoken, forwadPosition, backPosition);

  words(readingBuffer, Rtoken);
  if((*Rtoken).token != 0){
    return;
  }
  numbers(readingBuffer, Rtoken);
  if((*Rtoken).token != 0){
    return;
  }
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
  catchAll(readingBuffer, Rtoken);
  if((*Rtoken).token != 0){
    return;
  }
  if((*Rtoken).token == 0 && readingBuffer[forwadPosition] != '\n' && readingBuffer[forwadPosition] != '\r'){
    (*Rtoken).tokenChars[0]= readingBuffer[forwadPosition];
    (*Rtoken).tokenChars[1] = '\0';
    (*Rtoken).atribute = 0;
    (*Rtoken).token = LEXERROR;
    forwadPosition += 1;
    backPosition += 1;
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
    else if(readingBuffer[forwadPosition] == 91){ //  (
        (*Rtoken).atribute = 2;
        (*Rtoken).token = GROUPING;
        strcpy((*Rtoken).tokenChars,"[");
        forwadPosition += 1;
    }
    else if(readingBuffer[forwadPosition] == 93){ //  )
        (*Rtoken).atribute = 3;
        (*Rtoken).token = GROUPING;
        strcpy((*Rtoken).tokenChars,"]");
        forwadPosition += 1;
    }
    backPosition = forwadPosition;
}

/*** handles numbers and things [add error hadeling] ***/
void numbers (char readingBuffer[77], struct TokenReturn *Rtoken) {
    while(readingBuffer[forwadPosition] >= 48 && readingBuffer[forwadPosition] <= 57){
        forwadPosition += 1;
    }
    int len1 = forwadPosition - backPosition;
    int len2 = 0;
    int len3 = 0;

    if(readingBuffer[forwadPosition] == 46){ //IF Real and not int
        forwadPosition += 1;
        if(readingBuffer[forwadPosition] == 46){
            forwadPosition -= 1;
            goto exitReal;
        }
        while(readingBuffer[forwadPosition] >= 48 && readingBuffer[forwadPosition] <= 57){
            forwadPosition += 1;
        }
        len2 = forwadPosition - len1 - backPosition;
        if(readingBuffer[forwadPosition] == 69){
            forwadPosition += 1;
            while(readingBuffer[forwadPosition] >= 48 && readingBuffer[forwadPosition] <= 57){
                forwadPosition += 1;
            }
            len3 = forwadPosition - len1 - len2 - backPosition;
        }
    }
    exitReal:;
    //Error checking
    if(len1 > 10  && len2 == 0){
        int location = 0;
        while((location + backPosition) < forwadPosition){
            (*Rtoken).tokenChars[location] = readingBuffer[location + backPosition];
            location += 1;
        }
        (*Rtoken).tokenChars[location] = '\0';
        (*Rtoken).atribute = 2;
        (*Rtoken).token = LEXERROR;
        backPosition = forwadPosition;
        return;
    }
    else if(len1 == 0 && len2 == 1){
        forwadPosition = backPosition;
        return;
    }
    else if(len1 > 5 && len2 > 0){
        //Error first part of real too long
        int location = 0;
        while((location + backPosition) < forwadPosition){
            (*Rtoken).tokenChars[location] = readingBuffer[location + backPosition];
            location += 1;
        }
        (*Rtoken).tokenChars[location] = '\0';
        (*Rtoken).atribute = 5;
        (*Rtoken).token = LEXERROR;
        backPosition = forwadPosition;
        return;
        }
    else if(len2 > 6){
        //Error second part of real too long
        int location = 0;
        while((location + backPosition) < forwadPosition){
            (*Rtoken).tokenChars[location] = readingBuffer[location + backPosition];
            location += 1;
        }
        (*Rtoken).tokenChars[location] = '\0';
        (*Rtoken).atribute = 6;
        (*Rtoken).token = LEXERROR;
        backPosition = forwadPosition;
        return;
    }
    else if(len3 > 3){
        //Error third part of real too long
        int location = 0;
        while((location + backPosition) < forwadPosition){
            (*Rtoken).tokenChars[location] = readingBuffer[location + backPosition];
            location += 1;
        }
        (*Rtoken).tokenChars[location] = '\0';
        (*Rtoken).atribute = 7;
        (*Rtoken).token = LEXERROR;
        backPosition = forwadPosition;
        return;
    }
    else if(len2 > 0){ //Hadle a real that is the correct length
        int location = 0;
        while((location + backPosition) < forwadPosition){
            (*Rtoken).tokenChars[location] = readingBuffer[location + backPosition];
            location += 1;
        }
        (*Rtoken).tokenChars[location] = '\0';
        if((*Rtoken).tokenChars[0] == 0 && (*Rtoken).tokenChars[1] != '\0'){
            //Leading Zeros error
            (*Rtoken).atribute = 8;
            (*Rtoken).token = LEXERROR;
            backPosition = forwadPosition;
            return;
        }
        if((*Rtoken).tokenChars[len1+len2 - 1] == '0'){
            //Trailing zeros error
            (*Rtoken).atribute = 9;
            (*Rtoken).token = LEXERROR;
            backPosition = forwadPosition;
            return;
        }
        if(len3 > 2){
            if((*Rtoken).tokenChars[len1+len2 + len3 - 2] == '0'){
                //Leading Zero error
                (*Rtoken).atribute = 4;
                (*Rtoken).token = LEXERROR;
                backPosition = forwadPosition;
                return;
            }
        }
        (*Rtoken).atribute = 0;
        (*Rtoken).token = REAL;
    }
    else if(len1 > 0){
        int location = 0;
        while((location + backPosition) < forwadPosition){
            (*Rtoken).tokenChars[location] = readingBuffer[location + backPosition];
            location += 1;
        }
        (*Rtoken).tokenChars[location] = '\0';
        if((*Rtoken).tokenChars[0] == '0' && len1 != 1){
            //Leading Zeros error
            (*Rtoken).atribute = 3;
            (*Rtoken).token = LEXERROR;
            backPosition = forwadPosition;
            return;
        }

        (*Rtoken).atribute = 0;
        (*Rtoken).token = INT;
    }

    //end
    backPosition = forwadPosition;
}

/** Handle words and things [Gets word object, add comparisions and Error checking]**/

void words(char readingBuffer[77], struct TokenReturn *Rtoken) {
    char tempWord[75];
    if ((readingBuffer[forwadPosition] >= 65 && readingBuffer[forwadPosition] <= 90) || (readingBuffer[forwadPosition] >= 97 && readingBuffer[forwadPosition] <= 122)){ // Checks for first digit of word
        int location = 0;
        while((readingBuffer[forwadPosition] >= 65 && readingBuffer[forwadPosition] <= 90) || (readingBuffer[forwadPosition] >= 97 && readingBuffer[forwadPosition] <= 122) || (readingBuffer[forwadPosition] >= 49 && readingBuffer[forwadPosition] <= 57)){//checks of letter or digit
            tempWord[location] = readingBuffer[forwadPosition];
            forwadPosition += 1;
            location += 1;
        }
        tempWord[location] = '\0';
        int tempLeng = forwadPosition - backPosition - 1;
        if(tempLeng > 10){
            strcpy((*Rtoken).tokenChars, tempWord);
            (*Rtoken).atribute = 1;
            (*Rtoken).token = LEXERROR;
            backPosition = forwadPosition;
            return;
        }
        printf(tempWord);
        backPosition = forwadPosition;
        struct ReserveWord* currRes;
        struct SymbolTable* currSymbol;
        currRes = startReserve;

        do{
            if (strcmp((*currRes).resWord,tempWord) == 0){
                (*Rtoken).atribute = (*currRes).atribute;
                if(strcmp((*currRes).token, "CONTROL") == 0){
                    (*Rtoken).token = CONTROL;
                }
                else if(strcmp((*currRes).token, "VAR") == 0){
                    (*Rtoken).token = VAR;
                }
                else if(strcmp((*currRes).token, "ARRAY") == 0){
                    (*Rtoken).token = ARRAY;
                }
                else if(strcmp((*currRes).token, "TYPE") == 0){
                    (*Rtoken).token = TYPE;
                }
                else if(strcmp((*currRes).token, "FUNCTION") == 0){
                    (*Rtoken).token = FUNCTION;
                }
                else if(strcmp((*currRes).token, "MULOP") == 0){
                    (*Rtoken).token = MULOP;
                }
                else if(strcmp((*currRes).token, "FUNCTION") == 0){
                    (*Rtoken).token = FUNCTION;
                }
                else if(strcmp((*currRes).token, "NOT") == 0){
                    (*Rtoken).token = NOT;
                }
                else if(strcmp((*currRes).token, "ADDOP") == 0){
                    (*Rtoken).token = ADDOP;
                }
                strcpy((*Rtoken).tokenChars, tempWord);
                backPosition = forwadPosition;
                return;
            }
            currRes = (*currRes).next;
        } while((*currRes).next != NULL);
        //Checks tail
        if (strcmp((*currRes).resWord,tempWord) == 0){
            (*Rtoken).atribute = (*currRes).atribute;
            (*Rtoken).token = (*currRes).token;
            strcpy((*Rtoken).tokenChars, tempWord);
            backPosition = forwadPosition;
            return;
        }

        //Check in Symbol Table
        currSymbol = startSymbol; //Broken, change attribute and token for Rtoken
        if (varCountID == 10){ //No entries
            strcpy((*currSymbol).name, tempWord);
            strcpy((*Rtoken).tokenChars, tempWord);
            (*currSymbol).attribute = varCountID;
            (*Rtoken).atribute = varCountID;
            (*Rtoken).token = VAR;
            backPosition = forwadPosition;
            varCountID += 1;
            return;
        }
        else{
            while((*currSymbol).next != NULL){
                if(strcmp((*currSymbol).name, tempWord) == 0 ){
                    strcpy((*Rtoken).tokenChars, tempWord);
                    (*Rtoken).atribute = (*currSymbol).attribute;
                    (*Rtoken).token = VAR;
                    backPosition = forwadPosition;
                    return;
                }
                currSymbol = (*currSymbol).next;
            }
            if(strcmp((*currSymbol).name, tempWord) == 0){
                strcpy((*Rtoken).tokenChars, tempWord);
                (*Rtoken).atribute = (*currSymbol).attribute;
                (*Rtoken).token = VAR;
                backPosition = forwadPosition;
                return;
            }


            struct SymbolTable *tempCurrSym;
            tempCurrSym = malloc(sizeof(struct SymbolTable));
            SymbolTableInit(tempCurrSym);

            strcpy((*tempCurrSym).name, tempWord);
            strcpy((*Rtoken).tokenChars, tempWord);
            (*tempCurrSym).attribute = varCountID;
            (*Rtoken).atribute = varCountID;
            (*Rtoken).token = VAR;
            (*currSymbol).next = tempCurrSym;
            backPosition = forwadPosition;
            varCountID += 1;
            return;
        }
    }
}

void catchAll(char readingBuffer[77], struct TokenReturn *Rtoken){
    if(readingBuffer[forwadPosition] == 46){ // .
        forwadPosition += 1;
        if(readingBuffer[forwadPosition] == 46){ //  (
            (*Rtoken).atribute = 2;
            (*Rtoken).token = ARRAY;
            strcpy((*Rtoken).tokenChars,"..");
            forwadPosition += 1;
            backPosition = forwadPosition;
            return;
        }
        (*Rtoken).atribute = 0;
        (*Rtoken).token = PUNC;
        strcpy((*Rtoken).tokenChars,".");
        return;
    }
    else if(readingBuffer[forwadPosition] == 58){ //  )
        forwadPosition += 1;
        if(readingBuffer[forwadPosition] == 61){
            (*Rtoken).atribute = 0;
            (*Rtoken).token = ASSIGNOP;
            strcpy((*Rtoken).tokenChars,":=");
            forwadPosition += 1;
            backPosition = forwadPosition;
            return;
        }
        (*Rtoken).atribute = 2;
        (*Rtoken).token = TYPE;
        strcpy((*Rtoken).tokenChars,":");
        return;
    }
    else if(readingBuffer[forwadPosition] == 44){
        (*Rtoken).atribute = 1;
        (*Rtoken).token = PUNC;
        strcpy((*Rtoken).tokenChars,",");
        forwadPosition += 1;
        return;
    }
    else if(readingBuffer[forwadPosition] == 59){
        (*Rtoken).atribute = 2;
        (*Rtoken).token = PUNC;
        strcpy((*Rtoken).tokenChars,";");
        forwadPosition += 1;
        return;
    }
}
