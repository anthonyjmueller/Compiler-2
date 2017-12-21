#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int forwadPosition = 0;
int backPosition = 0;
int varCountID = 10;
char readingBuff[77];
char lineNum[5];
int currLine = 1;
int match_results = 0;
struct ReserveWord *startReserve;
struct SymbolTable *startSymbol;
struct TokenReturn* returnedToken;
FILE *writePtr;
FILE *readPtr;
FILE *tokenWrite;
FILE *memwritePtr;

//for type/scope/offset
int level = 1;
int offset = 0;
int potenAdd = 0;
struct node *currGreen;
struct node *currEnd;

#include "LinkedList.h"
#include "MainAnalyzer.h"
#include "PrintHandler.h"
#include "Analyizer/AnalyzerCaller.h"
#include "Parser/Productions.h"
#include "Datatype/nodes.h"


int main(int argc, char *argv[]){

    char fileName[100];
    if (argc == 2){
        strcpy(fileName, argv[1]);
    }
    else{
        exit(-1);
    }

    remove("ListingFile.txt");
    remove("TokenFile.txt");
    remove("MemoryFile.txt");

    readPtr = fopen(fileName,"r");
    writePtr = fopen("ListingFile.txt", "a");
    tokenWrite = fopen("TokenFile.txt", "a");
    memwritePtr = fopen("MemoryFile.txt", "a");

    startSymbol = malloc(sizeof(struct SymbolTable));
    SymbolTableInit(startSymbol);

    startReserve = ReserveWordListCreator();
    struct ReserveWord tempIter;
    tempIter = *startReserve;

    //currGreen = malloc(sizeof(struct node));
    currGreen = NULL;
    //currEnd = malloc(sizeof(struct node));
    currEnd = NULL;

    InitTokenFile(tokenWrite);
    InitMemFile();

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
    returnedToken = malloc(sizeof(struct TokenReturn));
    *returnedToken = returnedTokenobj;
    TokenReturnInit(returnedToken);

    fgets(readingBuff, 72, readPtr);
    //fgets(readingBuff, 72, readPtr);
   // do{
    //    analyzerCaller(returnedToken);
    //}while((*returnedToken).token != 15);
    program();


    //write what to do for end of file, generate token and send to analyzer

    fclose(writePtr);
    return 1;
}
