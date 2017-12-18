#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "Productions.h"
#include "../Analyizer/AnalyzerCaller.h"
#include "../DataType/LinkedList.h"

char expected[];

void variable_tail(){
    if(match(4,2) == 0){ // [
            analyzerCaller(returnedToken);
            expression();
        if(match(4, 3) == -1){ // ]
            strcpy(expected, "']'");
            variable_tailSync();
            goto end;
        }
        analyzerCaller(returnedToken);
    }
    else if(match(14, 0) == 0){ // assignop
    }
    else{
        strcpy(expected, "'[' or ':='");
        variable_tailSync();
        goto end;
    }
end:;
}

void variable_tailSync(){
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
