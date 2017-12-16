#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int forwadPosition = 0;
int backPosition = 0;
int varCountID = 10;
char readingBuff[77];
char lineNum[5];
int currLine = 1;
struct ReserveWord *startReserve;
struct SymbolTable *startSymbol;
FILE *writePtr;

#include "LinkedList.h"
#include "MainAnalyzer.h"
#include "PrintHandler.h"
#include "Analyizer/AnalyzerCaller.h"


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

    fgets(readingBuff, 72, readPtr);
    //fgets(readingBuff, 72, readPtr);
    do{
        analyzerCaller(returnedToken, writePtr, tokenWrite, readPtr);
    }while((*returnedToken).token != 15);


    //write what to do for end of file, generate token and send to analyzer

    fclose(writePtr);
    return 1;
}
