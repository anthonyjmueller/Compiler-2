#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "Productions.h"
#include "../Analyizer/AnalyzerCaller.h"
#include "../DataType/LinkedList.h"

char expected[];

void standard_type(){
    if(match(10,0) == 0 || match(10,1) == 0){ //int real
    }
    else{
        strcpy(expected, "'int' or 'real'");
        standard_typeSync();
        goto end;
    }
end:;
}

void standard_typeSync(){
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
