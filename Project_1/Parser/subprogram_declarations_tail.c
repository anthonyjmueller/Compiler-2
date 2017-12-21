#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "Productions.h"
#include "../Analyizer/AnalyzerCaller.h"
#include "../DataType/LinkedList.h"
#include "../Analyizer/Print_Tokens/PrintHandler.h"

char expected[];

void subprogram_declarations_tail(){
    if(match(7, 1) == 0){ // procedure
        subprogram_declaration();
        if(match(13,2) == -1){ // ;
            strcpy(expected, "';'");
            subprogram_declarations_tailSync();
            goto end;
        }
        analyzerCaller(returnedToken);
        subprogram_declarations_tail();
    }
    else if(match(7,2) == 0){ // begin
    }
    else{
        strcpy(expected, "'procedure' or 'begin'");
        subprogram_declarations_tailSync();
        goto end;
    }
end:;
}

void subprogram_declarations_tailSync(){
    fprintf(writePtr, "     SYNERROR:   Found ");
    fprintf(writePtr, (*returnedToken).tokenChars);
    fprintf(writePtr, " expected ");
    fprintf(writePtr, expected);
    fprintf(writePtr, "\n");
    do{

        if(match(15,0) == 0){
            exit(1);
            break;
        }else if(match(7,2) == 0){ // begin
            break;
        }
        analyzerCaller(returnedToken);
    }while(match_results == -1);
}
