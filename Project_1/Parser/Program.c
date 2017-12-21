#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "Productions.h"
#include "../Analyizer/AnalyzerCaller.h"
#include "../DataType/LinkedList.h"
#include "../DataType/nodes.h"
#include "../Analyizer/Print_Tokens/PrintHandler.h"

char expected[];

void program(){
    analyzerCaller(returnedToken);
    match(7, 0);//program
    if(match_results == -1){ //do sync
        strcpy(expected, "'program'");
        programSync();
        goto end;
    }
    analyzerCaller(returnedToken);
    match(8, 10); //Var, 10 or more
    if(match_results == -1){
        strcpy(expected, "'var_id'");
        programSync();
        goto end;
    }
    if(checkAddGreenNode() == 1){
        level += 1;////increases level int
    }
    analyzerCaller(returnedToken);
    match(4,0); //(
    if(match_results == -1){
        strcpy(expected, "'('");
        programSync();
        goto end;
    }
    analyzerCaller(returnedToken);
    int paramCount = 0; /////////////////gets parameter count
    identifier_list(&paramCount);
    (*currGreen).numParams = paramCount;
    match(4,1); //)
    if(match_results == -1){
        strcpy(expected, "')'");
        programSync();
        goto end;
    }
    analyzerCaller(returnedToken);
    match(13,2); // ;
    if(match_results == -1){
        strcpy(expected, "';'");
        programSync();
        goto end;
    }
    analyzerCaller(returnedToken);
    program_tail();
    match(15,0);// EOF
    if(match_results == -1){
        strcpy(expected, "'EOF'");
        programSync();
        goto end;
    }
end:;
}

void programSync(){
    fprintf(writePtr, "     SYNERROR:   Found ");
    fprintf(writePtr, (*returnedToken).tokenChars);
    fprintf(writePtr, " expected ");
    fprintf(writePtr, expected);
    fprintf(writePtr, "\n");
    do{
        analyzerCaller(returnedToken);
        match(15,0);
        if(match_results == 0){
            exit(1);
            break;
        }
    }while(match_results == -1);
}
