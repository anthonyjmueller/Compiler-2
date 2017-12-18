#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "Productions.h"
#include "../Analyizer/AnalyzerCaller.h"
#include "../DataType/LinkedList.h"

char expected[];

void statement_list_tail(){
    if(match(13 , 2) == 0 ){ // ;
        statement();
        statement_list_tail();
    }else if(match(7, 3) == 0){ // end
    }
    else{
        strcpy(expected, "';'");
        statement_list_tailSync();
        goto end;
    }
end:;
}

void statement_list_tailSync(){
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
