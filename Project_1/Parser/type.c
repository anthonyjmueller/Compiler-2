#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "Productions.h"
#include "../Analyizer/AnalyzerCaller.h"
#include "../DataType/LinkedList.h"

char expected[];

void type(){
    if(match(10,0) == 0 || match(10,1) == 0){ //int real
        standard_type();
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
        standard_type();

    }else{
        strcpy(expected, "'int' or 'real' or 'array'");
        typeSync();
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
        analyzerCaller(returnedToken);
        if(match(15,0) == 0){
            break;
        }else if(match(13, 2) == 0){ // ;
            break;
        }else if(match(4,1) == 0){ // )
            break;
        }
    }while(match_results == -1);
}
