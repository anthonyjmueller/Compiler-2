#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "Productions.h"
#include "../Analyizer/AnalyzerCaller.h"
#include "../DataType/LinkedList.h"
#include "../Analyizer/Print_Tokens/PrintHandler.h"

char expected[];

int type(){
    if(match(10,0) == 0 || match(10,1) == 0){ //int real
        return standard_type();
    }
    else if(match(9,0) == 0){ //array
        analyzerCaller(returnedToken);
        if(match(4, 2) == -1){ // [
            strcpy(expected, "'['");
            typeSync();
            goto end;
        }
        analyzerCaller(returnedToken);
        if(match(5,0) == -1){ // int
            strcpy(expected, "'num'");
            typeSync();
            goto end;
        }
        long num1 = strtol((*returnedToken).tokenChars, NULL, 10);
        analyzerCaller(returnedToken);
        if(match(9,2) == -1){ // ...
            strcpy(expected, "'..'");
            typeSync();
            goto end;
        }
        analyzerCaller(returnedToken);
        if(match(5,0) == -1){ // int
            strcpy(expected, "'num'");
            typeSync();
            goto end;
        }
        long num2 = strtol((*returnedToken).tokenChars, NULL, 10);
        analyzerCaller(returnedToken);
        if(match(4,3) == -1){ // ]
            strcpy(expected, "']'");
            typeSync();
            goto end;
        }
        analyzerCaller(returnedToken);
        if(match(9,1) == -1){ // of
            strcpy(expected, "'of'");
            typeSync();
            goto end;
        }
        analyzerCaller(returnedToken);
        int retstdtype = standard_type();
        if(retstdtype == 0){
            return 0;
        }else if(retstdtype == 1){ //int
            potenAdd = (num2 - num1 + 1) * 4;
            return 3;   //aing
        }else if(retstdtype == 2){ //real
            potenAdd = (num2 - num1 + 1) * 8;
            return 4;   //areal
        }

    }else{
        strcpy(expected, "'integer' or 'real' or 'array'");
        typeSync();
        return 0;
        goto end;
    }
end:;
}

void typeSync(){
    fprintf(writePtr, "     SYNERROR:   Found ");
    fprintf(writePtr, (*returnedToken).tokenChars);
    fprintf(writePtr, " expected ");
    fprintf(writePtr, expected);
    fprintf(writePtr, "\n");
    do{

        if(match(15,0) == 0){
            exit(1);
            break;
        }else if(match(13, 2) == 0){ // ;
            break;
        }else if(match(4,1) == 0){ // )
            break;
        }
        analyzerCaller(returnedToken);
    }while(match_results == -1);
}
