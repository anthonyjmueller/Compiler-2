#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "Productions.h"
#include "../Analyizer/AnalyzerCaller.h"
#include "../DataType/LinkedList.h"
#include "../Analyizer/Print_Tokens/PrintHandler.h"

char expected[];

void statement(){
    if(match(8,10) == 0){ //var_id
        int vType = variable();
        if(match(14, 0) == -1){ // assignop
            strcpy(expected, "':='");
            statementSync();
            goto end;
        }
        analyzerCaller(returnedToken);
        int eType = expression();

        if(vType == 1 && eType == 1){

        }else if(vType == 2 && eType == 2){
        }
        else if(vType == 0 || eType == 0){
        }else{
            fprintf(writePtr, "     SYMERROR:   Incompatible types for assignment ");
            fprintf(writePtr, "\n");
        }
    }
    else if( match(7 , 9) == 0){ //call
        procedure_statement();
    }
    else if(match(7 , 2) == 0){ //begin
        compound_statement();
    }
    else if( match(7 , 4) == 0 ){ //if
        analyzerCaller(returnedToken);
        int eType = expression();
        if(eType != 0 && eType != 5){
            if(eType != 1 || eType != 2){
            fprintf(writePtr, "     SYMERROR:   Non-boolean statement ");
            fprintf(writePtr, "\n");
            }
        }
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
        int eType = expression();
        if(eType != 0 && eType != 5){
            if(eType != 1 || eType != 2){
            fprintf(writePtr, "     SYMERROR:   Non-boolean statement ");
            fprintf(writePtr, "\n");
            }
        }
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
        analyzerCaller(returnedToken);
    }while(match_results == -1);
}
