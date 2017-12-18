#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "Productions.h"
#include "../Analyizer/AnalyzerCaller.h"
#include "../DataType/LinkedList.h"

char expected[];

void statement_list(){
    if(match(7 , 2) == 0 || match(8,10) == 0 || match(7 , 9) == 0 || match(7 , 4) == 0 || match(7 , 7) == 0){ // begin id call if while
        statement();
        statement_list_tail();
    }
    else{
        strcpy(expected, "'id' or 'call' or 'begin' or 'if' or 'while'");
        statement_listSync();
        goto end;
    }
end:;
}

void statement_listSync(){
    fprintf(writePtr, "     SYNERROR:   Found ");
    fprintf(writePtr, (*returnedToken).tokenChars);
    fprintf(writePtr, " expected ");
    fprintf(writePtr, expected);
    fprintf(writePtr, "\n");
    do{
        analyzerCaller(returnedToken);
        if(match(15,0) == 0){
            break;
        }else if(match(7, 3) == 0){ // end
            break;
        }
    }while(match_results == -1);
}
