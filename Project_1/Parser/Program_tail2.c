#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "Productions.h"
#include "../Analyizer/AnalyzerCaller.h"
#include "../DataType/LinkedList.h"
#include "../Analyizer/Print_Tokens/PrintHandler.h"

char expected[];

void program_tail2(){
    if(match(7, 1) == 0){ //procedure
        subprogram_declarations();
        compound_statement();
        match(13,0); // .
        if(match_results == -1){
            strcpy(expected, "'.'");
            program_tail2Sync();
            goto end;
        }
        analyzerCaller(returnedToken);
    }
    else if(match(7,2) == 0){  //begin
        compound_statement();
        match(13,0);
        if(match_results == -1){
            strcpy(expected, "'.'");
            program_tail2Sync();
            goto end;
        }
        analyzerCaller(returnedToken);
    }else{
        strcpy(expected, "'var' or 'procedure' or'begin'");
        program_tail2Sync();
        goto end;
    }
end:;
}

void program_tail2Sync(){
    fprintf(writePtr, "     SYNERROR:   Found ");
    fprintf(writePtr, (*returnedToken).tokenChars);
    fprintf(writePtr, " expected ");
    fprintf(writePtr, expected);
    fprintf(writePtr, "\n");
    do{

        match(15,0);
        if(match_results == 0){
            exit(1);
            break;
        }
        analyzerCaller(returnedToken);
    }while(match_results == -1);
}
