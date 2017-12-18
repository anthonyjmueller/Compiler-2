#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "Productions.h"
#include "../Analyizer/AnalyzerCaller.h"
#include "../DataType/LinkedList.h"

char expected[];

void identifier_list_tail(){
    if(match(13, 1) == 0){ // ,
        analyzerCaller(returnedToken);
        if(match(8, 10) == -1){ //var_id
            strcpy(expected, "'var_id'");
            identifier_list_tailSync();
            goto end;
        }
        analyzerCaller(returnedToken);
        identifier_list_tail();
    }
    else if(match(4,1) == 0){ // ,
    }else{
        strcpy(expected, "',' ')'");
        identifier_list_tailSync();
        goto end;
    }
end: ;
}

void identifier_list_tailSync(){
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
        }else if(match(4,1) == 0){ // )
            break;
        }
    }while(match_results == -1);
}
