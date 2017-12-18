#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "Productions.h"
#include "../Analyizer/AnalyzerCaller.h"
#include "../DataType/LinkedList.h"

char expected[];

void expression_list_tail(){
    if(match(13, 1) == 0){ // ,
        analyzerCaller(returnedToken);
        expression();
        expression_list_tail();
    }
    else if(match(4,1) == 0){ // )
    }
    else{
        strcpy(expected, "'(' or 'else' or ';' or 'end'");
        expression_list_tailSync();
        goto end;
    }
end:;
}

void expression_list_tailSync(){
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
