#include<stdlib.h>
#include<stdio.h>
#include "LinkedList.h"

#include "./PrintHandler.h"

FILE *ListingFile;

void ListingPrinter(struct TokenReturn *currToken, int currLine){
    char lineNum[5];
    sprintf(writePtr, "%d", currLine);

    fprintf(ListingFile, lineNum);
    fprintf(ListingFile, ".");

    int numDigits = strlen(lineNum);
    for(; numDigits < 10; numDigits++){
        fprintf(ListingFile, " ");
    }
}

void ListingErrorPrinter(struct TokenReturn *currToken){

    if((*currToken).token == 16){ // totaling 12
        fprintf(writePtr, "     LEXERROR:");
        if((*currToken).atribute == 0){
            fprintf(writePtr, "     Unreconized symbol:    ");
            fprintf(writePtr, (*currToken).tokenChars);
        }
        else if((*currToken).atribute == 1){
            fprintf(writePtr, "     ID Length exceeding 10 Characters:    ");
            fprintf(writePtr, (*currToken).tokenChars);
        }
        else if((*currToken).atribute == 2){
            fprintf(writePtr, "     Integer Length exceeding 10 Characters:    ");
            fprintf(writePtr, (*currToken).tokenChars);
        }
        else if((*currToken).atribute == 3){
            fprintf(writePtr, "     Integer has leading zeros:    ");
            fprintf(writePtr, (*currToken).tokenChars);
        }
        else if((*currToken).atribute == 4){
            fprintf(writePtr, "     Real leading 0 in exponent:    ");
            fprintf(writePtr, (*currToken).tokenChars);
        }
        else if((*currToken).atribute == 5){
            fprintf(writePtr, "     integer part of Real too long:    ");
            fprintf(writePtr, (*currToken).tokenChars);
        }
        else if((*currToken).atribute == 6){
            fprintf(writePtr, "     Fraction part of Real too long:    ");
            fprintf(writePtr, (*currToken).tokenChars);
        }
        else if((*currToken).atribute == 7){
            fprintf(writePtr, "     Exponent part of Real too long:    ");
            fprintf(writePtr, (*currToken).tokenChars);
        }
        else if((*currToken).atribute == 8){
            fprintf(writePtr, "     Leading zeros in real exponent:    ");
            fprintf(writePtr, (*currToken).tokenChars);
        }
        else if((*currToken).atribute == 9){
            fprintf(writePtr, "     Trailing zeros in real fraction:    ");
            fprintf(writePtr, (*currToken).tokenChars);
        }
    }

    fprintf(writePtr, "\n");
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
    else if((*currToken).token == 16){ // totaling 12
        ListingErrorPrinter(currToken);
        fprintf(tokenFile, "   ");
        fprintf(tokenFile, "LEXERROR:");
        if((*currToken).atribute == 0){
            fprintf(tokenFile, "     Unreconized symbol");
        }
        else if((*currToken).atribute == 1){
            fprintf(tokenFile, "     ID Length exceeding 10 Characters");
        }
        else if((*currToken).atribute == 2){
            fprintf(tokenFile, "     Integer Length exceeding 10 Characters");
        }
        else if((*currToken).atribute == 3){
            fprintf(tokenFile, "     Integer has leading zeros");
        }
        else if((*currToken).atribute == 4){
            fprintf(tokenFile, "     Real leading 0 in exponent");
        }
        else if((*currToken).atribute == 5){
            fprintf(tokenFile, "     integer part of Real too long");
        }
        else if((*currToken).atribute == 6){
            fprintf(tokenFile, "     Fraction part of Real too long");
        }
        else if((*currToken).atribute == 7){
            fprintf(tokenFile, "     Exponent part of Real too long");
        }
        else if((*currToken).atribute == 8){
            fprintf(tokenFile, "     Leading zeros in real exponent");
        }
        else if((*currToken).atribute == 9){
            fprintf(tokenFile, "     Trailing zeros in real fraction");
        }
    }

    if((*currToken).token != 16){

        fprintf(tokenFile, "                 ");

        char temp[5];
        sprintf(temp, "%d", ((*currToken).atribute));
        numDigits = strlen(temp);
        for(; numDigits < 5; numDigits++){
            fprintf(tokenFile, " ");
        }
        fprintf(tokenFile, temp); // End token attribute
    }

    fprintf(tokenFile, "\n");
}
