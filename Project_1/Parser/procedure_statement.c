#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "Productions.h"
#include "../Analyizer/AnalyzerCaller.h"
#include "../DataType/LinkedList.h"

char expected[];

void procedure_statement(){
    if(match(7,9) == 0){ // call
        analyzerCaller(returnedToken);
        if(match(8, 10) == -1){ // var_id
            strcpy(expected, "'var_id'");
            procedure_statementSync();
            goto end;
        }
        analyzerCaller(returnedToken);
        procedure_statement_tail();
    }
    else{
        strcpy(expected, "'var_id'");
        procedure_statementSync();
        goto end;
    }
end:;
}

void procedure_statementSync(){
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
        }else if(match(7, 3) == 0){ // end
            break;
        }else if(match(13, 2) == 0){ // ;
            break;
        }else if(match(7, 6) == 0){ // else
            break;
        }
    }while(match_results == -1);
}
