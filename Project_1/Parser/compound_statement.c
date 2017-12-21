#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "Productions.h"
#include "../Analyizer/AnalyzerCaller.h"
#include "../DataType/LinkedList.h"
#include "../Analyizer/Print_Tokens/PrintHandler.h"

char expected[];

void compound_statement(){
    if(match(7 , 2) == 0){ // begin
        analyzerCaller(returnedToken);
        optional_statements();
        if(match(7,3) == -1){ // end
            strcpy(expected, "'end'");
            compound_statementSync();
            goto end;
        }
        analyzerCaller(returnedToken);
    }
    else{
        strcpy(expected, "'begin'");
        compound_statementSync();
        goto end;
    }
end:;
}

void compound_statementSync(){
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
        }else if(match(13,0) == 0){ // .
            break;
        }else if(match(13,2) == 0){ // ;
            break;
        }else if(match(7,6) == 0){ // else
            break;
        }else if(match(7, 3) == 0){ // end
            break;
        }
    }while(match_results == -1);
}
