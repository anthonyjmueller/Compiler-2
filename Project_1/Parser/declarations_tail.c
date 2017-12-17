#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "Productions.h"
#include "../Analyizer/AnalyzerCaller.h"
#include "../DataType/LinkedList.h"

char expected[];

void declarations_tail(){
    if(match(8,0) == 0){ //var
        analyzerCaller(returnedToken);
        if(match(8, 10) == -1){ //var_id
            strcpy(expected, "'var_id'");
            declarations_tailSync();
            goto end;
        }
        analyzerCaller(returnedToken);
        if(match(10, 2) == -1){ // :
            strcpy(expected, "':'");
            declarations_tailSync();
            goto end;
        }
        analyzerCaller(returnedToken);
        type();
        analyzerCaller(returnedToken);
        if(match(13, 2) == -1){ //var_id
            strcpy(expected, "'var_id'");
            declarations_tailSync();
            goto end;
        }
        analyzerCaller(returnedToken);
        declarations_tail();
    }else if(match(7, 0) == 0 || match(7, 6) == 0){
    }
    else{
        strcpy(expected, "'var' or 'begin' or 'procedure'");
        declarations_tailSync();
        goto end;
    }
end:;
}

void declarations_tailSync(){
    fprintf(writePtr, "     SYNERROR:   Found ");
    fprintf(writePtr, (*returnedToken).tokenChars);
    fprintf(writePtr, " expected ");
    fprintf(writePtr, expected);
    fprintf(writePtr, "\n");
    do{
        analyzerCaller(returnedToken);
        if(match(15,0) == 0){
            break;
        }else if(match(7, 0) == 0){ // begin
            break;
        }else if(match(7, 6) == 0){ // procedure
            break;
        }
    }while(match_results == -1);
}
