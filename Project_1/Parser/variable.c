#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "Productions.h"
#include "../Analyizer/AnalyzerCaller.h"
#include "../DataType/LinkedList.h"

char expected[];

void variable(){
    if(match(8, 10) == 0){ // else
            analyzerCaller(returnedToken);
            variable_tail();
    }
    else{
        strcpy(expected, "'id_var'");
        variableSync();
        goto end;
    }
end:;
}

void variableSync(){
    fprintf(writePtr, "     SYNERROR:   Found ");
    fprintf(writePtr, (*returnedToken).tokenChars);
    fprintf(writePtr, " expected ");
    fprintf(writePtr, expected);
    fprintf(writePtr, "\n");
    do{
        analyzerCaller(returnedToken);
        if(match(15,0) == 0){
            break;
        }else if(match(14, 0) == 0){ // assignop
            break;
        }
    }while(match_results == -1);
}
