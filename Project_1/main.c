#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int forwadPosition = 0;
int backPosition = 0;
int varCountID = 10;
struct ReserveWord *startReserve;
struct SymbolTable *startSymbol;
FILE *writePtr;

#include "LinkedList.h"
#include "MainAnalyzer.h"
#include "PrintHandler.h"


int main(int argc, char *argv[]){

    char fileName[100];
    if (argc == 2){
        strcpy(fileName, argv[1]);
    }
    else{
        exit(-1);
    }

    FILE *readPtr;
    FILE *tokenWrite;
    char readingBuff[77];
    char lineNum[5];
    int currLine = 1;

    remove("ListingFile.txt");
    remove("TokenFile.txt");

    readPtr = fopen(fileName,"r");
    writePtr = fopen("ListingFile.txt", "a");
    tokenWrite = fopen("TokenFile.txt", "a");

    startSymbol = malloc(sizeof(struct SymbolTable));
    SymbolTableInit(startSymbol);

    startReserve = ReserveWordListCreator();
    struct ReserveWord tempIter;
    tempIter = *startReserve;

    InitTokenFile(tokenWrite);

    //All reserve word data collected correctly
    while(tempIter.next != NULL){
        printf(tempIter.resWord);
        printf(tempIter.token);
        char tempStr[5];
        sprintf(tempStr, "%d", tempIter.atribute);
        printf(tempStr);
        tempIter = *tempIter.next;
        printf("\n");
    }

    //initializes Token return struct
    struct TokenReturn returnedTokenobj;
    struct TokenReturn* returnedToken = &returnedTokenobj;
    TokenReturnInit(returnedToken);


    //fgets(readingBuff, 72, readPtr);

    while(fgets(readingBuff, 72, readPtr) != NULL){

        forwadPosition = 0;
        backPosition = 0;

        //Setups numbering for ListingFile
        sprintf(lineNum, "%d", currLine);
        fprintf(writePtr, lineNum);
        fprintf(writePtr, ".");

        int numDigits = strlen(lineNum);
        for(; numDigits < 5; numDigits++){
            fprintf(writePtr, " ");
        }
        fprintf(writePtr, readingBuff);


        //gets next token

        do{ //Prints tokens obtained by analyzer
            //ListingPrinter(returnedToken, currLine);
            analyzer(readingBuff, returnedToken);
            // For testing only
            char temp[5];
            sprintf(temp, "%d", returnedTokenobj.token);
            printf(temp);
            printf("here \n");
            //End
            if(returnedTokenobj.token != 0){
                printToken(returnedToken, lineNum, tokenWrite);
            }
        }while ((*returnedToken).token != 0);

        //test Prints


//        printf(readingBuff);



        //fputs(readingBuff, writePtr);
        currLine++;
    }
    returnedTokenobj.atribute = 0;
    returnedTokenobj.token = 15;
    strcpy(returnedTokenobj.tokenChars, "EOF");
    sprintf(lineNum, "%d", currLine);
    printToken(returnedToken, lineNum, tokenWrite);

    //write what to do for end of file, generate token and send to analyzer

    fclose(writePtr);
    return 1;
}
