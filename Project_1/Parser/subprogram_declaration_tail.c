#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "Productions.h"
#include "../Analyizer/AnalyzerCaller.h"
#include "../DataType/LinkedList.h"
#include "../Analyizer/Print_Tokens/PrintHandler.h"

char expected[];

void subprogram_declaration_tail(){
    if(match(8,0) == 0){ //var
        declarations();
        subprogram_declaration_tail2();
    }
    else if(match(7, 1) == 0){ // procedure
        subprogram_declarations();
        compound_statement();
        popScope();
    }
    else if(match(7,2) == 0){ // begin
        compound_statement();
        popScope();
    }
    else{
        strcpy(expected, "'procedure' or 'var' or 'begin'");
        subprogram_declaration_tailSync();
        goto end;
    }
end:;
}

void subprogram_declaration_tailSync(){
    fprintf(writePtr, "     SYNERROR:   Found ");
    fprintf(writePtr, (*returnedToken).tokenChars);
    fprintf(writePtr, " expected ");
    fprintf(writePtr, expected);
    fprintf(writePtr, "\n");
    do{

        if(match(15,0) == 0){
            exit(1);
            break;
        }else if(match(13,2) == 0){ // ;
            break;
        }
        analyzerCaller(returnedToken);
    }while(match_results == -1);
}
