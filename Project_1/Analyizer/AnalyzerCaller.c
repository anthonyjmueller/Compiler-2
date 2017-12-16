#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "../DataType/LinkedList.h"
#include "./MainAnalyzer.h"

#include "./AnalyzerCaller.h"

void analyzerCaller(struct TokenReturn *returnedToken, FILE *writePtr, FILE *tokenWrite, FILE *readPtr){
    startAnalyzer:;
    //Setups numbering for ListingFile
    if(forwadPosition == 0){
        sprintf(lineNum, "%d", currLine);
        fprintf(writePtr, lineNum);
        fprintf(writePtr, ".");

        int numDigits = strlen(lineNum);
        for(; numDigits < 5; numDigits++){
            fprintf(writePtr, " ");
        }
        fprintf(writePtr, readingBuff);
    }


    //gets next token

    do{ //Prints tokens obtained by analyzer
        //ListingPrinter(returnedToken, currLine);
        analyzer(readingBuff, returnedToken);
        // For testing only
        char temp[5];
        sprintf(temp, "%d", (*returnedToken).token);
        printf(temp);
        printf("here \n");
        //End
        if((*returnedToken).token != 0){
            printToken(returnedToken, lineNum, tokenWrite);
            goto endAnalyzer;
        }
    }while ((*returnedToken).token != 0);

        //test Prints


//        printf(readingBuff);



    //fputs(readingBuff, writePtr);
    if(readingBuff[forwadPosition] == '\n'){
       currLine++;
        forwadPosition = 0;
        backPosition = 0;
        if(fgets(readingBuff, 72, readPtr) == NULL){
            (*returnedToken).atribute = 0;
            (*returnedToken).token = 15;
            strcpy((*returnedToken).tokenChars, "EOF");
            sprintf(lineNum, "%d", currLine);
            printToken(returnedToken, lineNum, tokenWrite);
            goto endAnalyzer;
        }
       goto startAnalyzer;
    }

endAnalyzer: ;

}
