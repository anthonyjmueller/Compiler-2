#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "Productions.h"
#include "../Analyizer/AnalyzerCaller.h"
#include "../DataType/LinkedList.h"

char expected[];

void subprogram_declaration(){
    if(match(7, 1) == 0){ // procedure
        subprogram_head();
        subprogram_declaration_tail();
    }
    else{
        strcpy(expected, "'procedure'");
        subprogram_declarationSync();
        goto end;
    }
end:;
}

void subprogram_declarationSync(){
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
        }else if(match(13,2) == 0){ // ;
            break;
        }
    }while(match_results == -1);
}
