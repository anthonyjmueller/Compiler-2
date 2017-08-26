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
    fprintf(lstPtr, "Line             "); // (9)
    fprintf(lstPtr, "Lexeme        "); //(15)
    fprintf(lstPtr, "Token Type       "); //(17)
    fprintf(lstPtr, "Token Attribute"); //(15)
    fprintf(lstPtr, "\n");
}

void printToken(struct TokenReturn *currToken, char lineNum[], FILE *tokenFile){
    int numDigits = strlen(lineNum);
    for(; numDigits < 5; numDigits++){
        fprintf(tokenFile, " ");
    }
    fprintf(tokenFile, lineNum);
    fprintf(tokenFile, "    "); // Ends printing line number

    numDigits = strlen((*currToken).tokenChars);
    for(; numDigits < 15; numDigits++){
        fprintf(tokenFile, " ");
    }
    fprintf(tokenFile, (*currToken).tokenChars);
    fprintf(tokenFile, "     "); // End printing string literal

    if((*currToken).token == 1){ // totaling 12
        fprintf(tokenFile, "       ");
        fprintf(tokenFile, "ADDOP");
    }
    else if((*currToken).token == 2){ // totaling 12
        fprintf(tokenFile, "       ");
        fprintf(tokenFile, "RELOP");
    }
    else if((*currToken).token == 3){ // totaling 12
        fprintf(tokenFile, "       ");
        fprintf(tokenFile, "MULOP");
    }
    else if((*currToken).token == 4){ // totaling 12
        fprintf(tokenFile, "    ");
        fprintf(tokenFile, "GROUPING");
    }
    else if((*currToken).token == 5){ // totaling 12
        fprintf(tokenFile, "         ");
        fprintf(tokenFile, "INT");
    }
    else if((*currToken).token == 6){ // totaling 12
        fprintf(tokenFile, "        ");
        fprintf(tokenFile, "REAL");
    }
    fprintf(tokenFile, "                 ");


    char temp[5];
    sprintf(temp, "%d", ((*currToken).atribute));
    numDigits = strlen(temp);
    for(; numDigits < 5; numDigits++){
        fprintf(tokenFile, " ");
    }
    fprintf(tokenFile, temp); // End token attribute

    fprintf(tokenFile, "\n");
}
