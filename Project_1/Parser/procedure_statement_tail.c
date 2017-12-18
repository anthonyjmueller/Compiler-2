#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "Productions.h"
#include "../Analyizer/AnalyzerCaller.h"
#include "../DataType/LinkedList.h"

char expected[];

void procedure_statement_tail(){
    if(match(4,0) == 0){ // (
        analyzerCaller(returnedToken);
        expression_list();
        if(match(4, 1) == -1){ // )
            strcpy(expected, "')'");
            procedure_statement_tailSync();
            goto end;
        }
        analyzerCaller(returnedToken);
    }
    else if(match(7, 6) == 0 || match(13, 2) == 0 || match(7, 3) == 0){ // else ; end
    }
    else{
        strcpy(expected, "'(' or 'else' or ';' or 'end'");
        procedure_statement_tailSync();
        goto end;
    }
end:;
}

void procedure_statement_tailSync(){
    fprintf(writePtr, "     SYNERROR:   Found ");
    fprintf(writePtr, (*returnedToken).tokenChars);
    fprintf(writePtr, " expected ");
    fprintf(writePtr, expected);
    fprintf(writePtr, "\n");
    do{
        analyzerCaller(returnedToken);
        if(match(15,0) == 0){
            break;
        }else if(match(7, 3) == 0){ // end
            break;
        }else if(match(13, 2) == 0){ // ;
            break;
        }else if(match(7, 6) == 0){ // else
            break;
        }
    }while(match_results == -1);
}
