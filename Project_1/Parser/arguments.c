#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "Productions.h"
#include "../Analyizer/AnalyzerCaller.h"
#include "../DataType/LinkedList.h"
#include "../Analyizer/Print_Tokens/PrintHandler.h"

char expected[];

void arguments(int *count){
    if(match(4,0) == 0){ // (
        analyzerCaller(returnedToken);
        parameter_list(count);
        if(match(4, 1) == -1){ // )
            strcpy(expected, "')'");
            argumentsSync();
            goto end;
        }
        analyzerCaller(returnedToken);
    }else if(match(13,2) == 0){ // ;
    }
    else{
        strcpy(expected, "'(' or ';'");
        argumentsSync();
        goto end;
    }
end:;
}

void argumentsSync(){
    fprintf(writePtr, "     SYNERROR:   Found ");
    fprintf(writePtr, (*returnedToken).tokenChars);
    fprintf(writePtr, " expected ");
    fprintf(writePtr, expected);
    fprintf(writePtr, "\n");
   // (*returnedToken).token = 17;
    //ListingErrorPrinter((*returnedToken));

    do{
        if(match(15,0) == 0){
            exit(1);
            break;
        }else if(match(13, 2) == 0){ // ;
            break;
        }
        analyzerCaller(returnedToken);
    }while(match_results == -1);
}
