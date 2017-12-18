#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "Productions.h"
#include "../Analyizer/AnalyzerCaller.h"
#include "../DataType/LinkedList.h"

char expected[];

void declarations(){
    if(match(8,0) == 0){ //var
        analyzerCaller(returnedToken);
        if(match(8, 10) == -1){ //var_id
            strcpy(expected, "'var_id'");
            declarationsSync();
            goto end;
        }
        analyzerCaller(returnedToken);
        if(match(10, 2) == -1){ // :
            strcpy(expected, "':'");
            declarationsSync();
            goto end;
        }
        analyzerCaller(returnedToken);
        type();
        analyzerCaller(returnedToken);
        if(match(13, 2) == -1){ //var_id
            strcpy(expected, "'var_id'");
            declarationsSync();
            goto end;
        }
        analyzerCaller(returnedToken);
        declarations_tail();
    }else{
        strcpy(expected, "'var'");
        declarationsSync();
        goto end;
    }
end:;
}

void declarationsSync(){
    fprintf(writePtr, "     SYNERROR:   Found ");
    fprintf(writePtr, (*returnedToken).tokenChars);
    fprintf(writePtr, " expected ");
    fprintf(writePtr, expected);
    fprintf(writePtr, "\n");
    do{
        analyzerCaller(returnedToken);
        if(match(15,0) == 0){
            break;
        }else if(match(7, 2) == 0){ // begin
            break;
        }else if(match(7, 1) == 0){ // procedure
            break;
        }
    }while(match_results == -1);
}