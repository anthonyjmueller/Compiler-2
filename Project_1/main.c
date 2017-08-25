#include <stdio.h>
#include <stdlib.h>

int forwadPosition = 0;
int backPosition = 0;
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
    struct ReserveWord tempIter;
    tempIter = *startReserve;

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
        analyzer(readingBuff, returnedToken, forwadPosition, backPosition);

        printf(returnedTokenobj.token);
        while ((*returnedToken).token != 0){ //Prints tokens obtained by analyzer
            ListingPrinter(returnedToken, currLine);
            analyzer(readingBuff, returnedToken, forwadPosition, backPosition);
        }

        //test Prints


//        printf(readingBuff);



        //fputs(readingBuff, writePtr);
        currLine++;
    }
    //write what to do for end of file, generate token and send to analyzer

    fclose(writePtr);
}
