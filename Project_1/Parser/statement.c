#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "Productions.h"
#include "../Analyizer/AnalyzerCaller.h"
#include "../DataType/LinkedList.h"

char expected[];

void statement(){
    if(match(8,10) == 0){ //var_id
        variable();
        if(match(14, 0) == -1){ // assignop
            strcpy(expected, "':='");
            statementSync();
            goto end;
        }
        analyzerCaller(returnedToken);
        expression();
    }
    else if( match(7 , 9) == 0){ //call
        procedure_statement();
    }
    else if(match(7 , 2) == 0){ //begin
        compound_statement();
        analyzerCaller(returnedToken);
    }
    else if( match(7 , 4) == 0 ){ //if
        analyzerCaller(returnedToken);
        expression();
        if(match(7,5) == -1){ // then
            strcpy(expected, "'then'");
            statementSync();
            goto end;
        }
        analyzerCaller(returnedToken);
        statement();
        statement_tail();
    }
    else if(match(7 , 7) == 0){ // while
        analyzerCaller(returnedToken);
        expression();
        if(match(7,8) == -1){ // do
            strcpy(expected, "'do'");
            statementSync();
            goto end;
        }
        analyzerCaller(returnedToken);
        statement();
    }
    else{
        strcpy(expected, "'id' or 'call' or 'begin' or 'if' or 'while'");
        statement_listSync();
        goto end;
    }
end:;
}

void statementSync(){
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
