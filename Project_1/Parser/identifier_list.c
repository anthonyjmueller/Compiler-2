#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "Productions.h"
#include "../Analyizer/AnalyzerCaller.h"
#include "../DataType/LinkedList.h"

char expected[];

void identifier_list(){
    if(match(8,10) == 0){
        analyzerCaller(returnedToken);
        identifier_list_tail();
    }else{
        strcpy(expected, "'var_id'");
        identifier_listSync();
        goto end;
    }
end:;
}

void identifier_listSync(){
    fprintf(writePtr, "     SYNERROR:   Found ");
    fprintf(writePtr, (*returnedToken).tokenChars);
    fprintf(writePtr, " expected ");
    fprintf(writePtr, expected);
    fprintf(writePtr, "\n");
    do{
        analyzerCaller(returnedToken);
        if(match(15,0) == 0){
            break;
        }else if(match(4,1)  == 0){ // )
            break;
        }
    }while(match_results == -1);
}
