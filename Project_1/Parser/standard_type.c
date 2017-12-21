#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "Productions.h"
#include "../Analyizer/AnalyzerCaller.h"
#include "../DataType/LinkedList.h"
#include "../Analyizer/Print_Tokens/PrintHandler.h"

char expected[];

int standard_type(){
    if(match(10,0) == 0 || match(10,1) == 0){ //int real
        if(match(10,0) == 0){ ///////int
            analyzerCaller(returnedToken);
            potenAdd = 4;
            return 1; ///////int
        }else if(match(10,1) == 0){ //real
            analyzerCaller(returnedToken);
            potenAdd = 8;
            return 2;   //aing
        }
    }
    else{
        strcpy(expected, "'integer' or 'real'");
        standard_typeSync();
        return 0;
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
