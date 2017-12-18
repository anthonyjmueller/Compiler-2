#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "Productions.h"
#include "../Analyizer/AnalyzerCaller.h"
#include "../DataType/LinkedList.h"

char expected[];

void expression_list(){
    if(match(8, 10) == 0 || match(5,0) == 0 || match(6,0) == 0 || match(4,0) == 0 || match(12, 0) == 0 || match(1,0) == 0|| match(1,1) == 0){ // var_id num ( not + -
        expression();
        expression_list_tail();
    }
    else{
        strcpy(expected, "'var_id' or 'num' or '(' or 'not' or '+' or '-'");
        expression_listSync();
        goto end;
    }
end:;
}

void expression_listSync(){
    fprintf(writePtr, "     SYNERROR:   Found ");
    fprintf(writePtr, (*returnedToken).tokenChars);
    fprintf(writePtr, " expected ");
    fprintf(writePtr, expected);
    fprintf(writePtr, "\n");
    do{
        analyzerCaller(returnedToken);
        if(match(15,0) == 0){
            break;
        }else if(match(4,1) == 0){ // )
            break;
        }
    }while(match_results == -1);
}
