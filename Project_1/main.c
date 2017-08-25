#include <stdio.h>
#include <stdlib.h>

char* forwadPosition;
char* backPosition;
struct ReserveWord *startReserve;
struct SymbolTable *startSymbol;

#include "DataType/LinkedList.h"
#include "Analyizer/MainAnalyzer.h"
#include "Analyizer/Print_Tokens/PrintHandler.h"


int main()
{

    FILE *readPtr;
    FILE *writePtr;
    char readingBuff[77];
    char lineNum[5];
    int currLine = 1;

    remove("ListingFile.txt");

    readPtr = fopen("test2.pas","r");
    writePtr = fopen("ListingFile.txt", "a");

    startReserve = ReserveWordListCreator();

//    struct ReserveWord *temp = startReserve;
//    while ( (*temp).next != NULL ){
//        printf((*temp).resWord);
//        temp = (*temp).next;
//    }

    fgets(readingBuff, 72, readPtr);

    while(fgets(readingBuff, 72, readPtr) != NULL){

        //Setups numbering for ListingFile
        sprintf(lineNum, "%d", currLine);
        fprintf(writePtr, lineNum);
        fprintf(writePtr, ".");

        int numDigits = strlen(lineNum);
        for(; numDigits < 5; numDigits++){
            fprintf(writePtr, " ");
        }
        fprintf(writePtr, readingBuff);

    //initializes Token return struct
        struct TokenReturn returnedTokenobj;
        struct TokenReturn* returnedToken = &returnedTokenobj;
        TokenReturnInit(returnedToken);

        //gets next token
        analyzer(readingBuff, returnedToken);
        printf(returnedTokenobj.token);
        while ((*returnedToken).token != 0){ //Prints tokens obtained by analyzer
            ListingPrinter(returnedToken, currLine);
            analyzer(readingBuff, returnedToken);
        }

        //test Prints


//        printf(readingBuff);



        //fputs(readingBuff, writePtr);
        currLine++;
    }
    //write what to do for end of file, generate token and send to analyzer

    fclose(writePtr);
}
