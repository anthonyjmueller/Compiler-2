#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "Productions.h"
#include "../Analyizer/AnalyzerCaller.h"
#include "../DataType/LinkedList.h"

char expected[];

void parameter_list_tail(){
    if(match(13 , 2) == 0){ // ;
        analyzerCaller(returnedToken);
        if(match(8,10) == -1){ // var_id
            strcpy(expected, "'var_id'");
            parameter_list_tailSync();
            goto end;
        }
        analyzerCaller(returnedToken);
        if(match(10, 2) == -1){ // :
            strcpy(expected, "':'");
            parameter_list_tailSync();
            goto end;
        }
        analyzerCaller(returnedToken);
        type();
        analyzerCaller(returnedToken);
        parameter_list_tail();
    }else if(match(4,1) == 0){
    }
    else{
        strcpy(expected, "';' or ')'");
        parameter_list_tailSync();
        goto end;
    }
end:;
}

void parameter_list_tailSync(){
    fprintf(writePtr, "     SYNERROR:   Found ");
    fprintf(writePtr, (*returnedToken).tokenChars);
    fprintf(writePtr, " expected ");
    fprintf(writePtr, expected);
    fprintf(writePtr, "\n");
    do{
        analyzerCaller(returnedToken);
        if(match(15,0) == 0){
            break;
        }else if(match(4,1) == 0){ // )
            break;
        }
    }while(match_results == -1);
}
