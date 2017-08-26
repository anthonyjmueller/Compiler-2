#include<stdlib.h>
#include<stdio.h>
#include "../../DataType/LinkedList.h"

#include "./PrintHandler.h"

FILE *ListingFile;

void ListingPrinter(struct TokenReturn *currToken, int currLine){
    printf("here");
    char lineNum[5];
    sprintf(lineNum, "%d", currLine);

    fprintf(ListingFile, lineNum);
    fprintf(ListingFile, ".");

    int numDigits = strlen(lineNum);
    for(; numDigits < 10; numDigits++){
        fprintf(ListingFile, " ");
    }

    if ((*currToken).token == 99){//print error
        printf("error");
    }
    else{
       printf("noError");
    }
}

void InitTokenFile(FILE *lstPtr){
    fprintf(lstPtr, "Line    "); // (9)
    fprintf(lstPtr, "Lexeme         "); //(15)
    fprintf(lstPtr, "Token Type  "); //(12)
    fprintf(lstPtr, "Token Attribute"); //(15)
    fprintf(lstPtr, "\n");
}
