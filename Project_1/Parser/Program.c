#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "Productions.h"
#include "../Analyizer/AnalyzerCaller.h"
#include "../DataType/LinkedList.h"

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
    analyzerCaller(returnedToken);
    match(4,0); //)
    if(match_results == -1){
        strcpy(expected, "'('");
        programSync();
        goto end;
    }
    //identifier_list();
    analyzerCaller(returnedToken);
    match(4,1); //)
    if(match_results == -1){
        strcpy(expected, "')'");
        programSync();
        goto end;
    }
    //program_tail();
    analyzerCaller(returnedToken);
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
            break;
        }
    }while(match_results == -1);
}
