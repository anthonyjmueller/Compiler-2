#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "Productions.h"
#include "../Analyizer/AnalyzerCaller.h"
#include "../DataType/LinkedList.h"
#include "../Analyizer/Print_Tokens/PrintHandler.h"

char expected[];

void optional_statements(){
    if(match(7 , 2) == 0 || match(8,10) == 0 || match(7 , 9) == 0 || match(7 , 4) == 0 || match(7 , 7) == 0){ // begin id call if while
        statement_list();
    }else if(match(7,3) == 0){
    }
    else{
        strcpy(expected, "'id' or 'call' or 'begin' or 'if' or 'while'");
        optional_statementsSync();
        goto end;
    }
end:;
}

void optional_statementsSync(){
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
        }
        analyzerCaller(returnedToken);
    }while(match_results == -1);
}
