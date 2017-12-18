#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "Productions.h"
#include "../Analyizer/AnalyzerCaller.h"
#include "../DataType/LinkedList.h"

char expected[];

void subprogram_head(){
    if(match(7, 1) == 0){ // procedure
        analyzerCaller(returnedToken);
        if(match(8, 10) == -1){ // var_id
            strcpy(expected, "'var_id'");
            subprogram_headSync();
            goto end;
        }
        analyzerCaller(returnedToken);
        arguments();
        if(match(13,2) == -1){ // ;
            strcpy(expected, "';'");
            subprogram_headSync();
            goto end;
        }
        analyzerCaller(returnedToken);

    }
    else{
        strcpy(expected, "'procedure'");
        subprogram_headSync();
        goto end;
    }
end:;
}

void subprogram_headSync(){
    fprintf(writePtr, "     SYNERROR:   Found ");
    fprintf(writePtr, (*returnedToken).tokenChars);
    fprintf(writePtr, " expected ");
    fprintf(writePtr, expected);
    fprintf(writePtr, "\n");
    do{
        analyzerCaller(returnedToken);
        if(match(15,0) == 0){
            exit(1);
            break;
        }else if(match(7,1) == 0){ // procedure
            break;
        }else if(match(7,2) == 0){ // begin
            break;
        }else if(match(8,0) == 0){ // var
            break;
        }
    }while(match_results == -1);
}
