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
    else if((*currToken).token == 7){ // totaling 12
        fprintf(tokenFile, "     ");
        fprintf(tokenFile, "CONTROL");
    }
    else if((*currToken).token == 8){ // totaling 12
        fprintf(tokenFile, "         ");
        fprintf(tokenFile, "VAR");
    }
    else if((*currToken).token == 9){ // totaling 12
        fprintf(tokenFile, "       ");
        fprintf(tokenFile, "ARRAY");
    }
    else if((*currToken).token == 10){ // totaling 12
        fprintf(tokenFile, "        ");
        fprintf(tokenFile, "TYPE");
    }
    else if((*currToken).token == 11){ // totaling 12
        fprintf(tokenFile, "    ");
        fprintf(tokenFile, "FUNCTION");
    }
    else if((*currToken).token == 12){ // totaling 12
        fprintf(tokenFile, "         ");
        fprintf(tokenFile, "NOT");
    }
    else if((*currToken).token == 13){ // totaling 12
        fprintf(tokenFile, "        ");
        fprintf(tokenFile, "PUNC");
    }
    else if((*currToken).token == 14){ // totaling 12
        fprintf(tokenFile, "    ");
        fprintf(tokenFile, "ASSIGNOP");
    }
    else if((*currToken).token == 15){ // totaling 12
        fprintf(tokenFile, "         ");
        fprintf(tokenFile, "EOF");
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
