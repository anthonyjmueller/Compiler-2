#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "Productions.h"
#include "../Analyizer/AnalyzerCaller.h"
#include "../DataType/LinkedList.h"
#include "../Analyizer/Print_Tokens/PrintHandler.h"

char expected[];

void subprogram_head(){
    if(match(7, 1) == 0){ // procedure
        analyzerCaller(returnedToken);
        if(match(8, 10) == -1){ // var_id
            strcpy(expected, "'var_id'");
            subprogram_headSync();
            goto end;
        }
        int succ = checkAddGreenNode();
        if(succ == -1){
            fprintf(writePtr, "     SYMERROR:   Parameter name ");
            fprintf(writePtr, (*returnedToken).tokenChars);
            fprintf(writePtr, " already declared");
            fprintf(writePtr, "\n");
        }
        analyzerCaller(returnedToken);
        int paramCount = 0; /////////////params count
        arguments(&paramCount);
        if(succ == 1){
            (*currGreen).numParams = paramCount;
        }
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
