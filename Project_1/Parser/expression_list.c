#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "Productions.h"
#include "../Analyizer/AnalyzerCaller.h"
#include "../DataType/LinkedList.h"
#include "../Analyizer/Print_Tokens/PrintHandler.h"

char expected[];

void expression_list(int *typeList[50], int *count){
    if(match(8, 10) == 0 || match(5,0) == 0 || match(6,0) == 0 || match(4,0) == 0 || match(12, 0) == 0 || match(1,0) == 0|| match(1,1) == 0){ // var_id num ( not + -
        int eType = expression();
        typeList[*count] = eType;
        *count = (*count) + 1;
        expression_list_tail(typeList, count);
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
        if(match(15,0) == 0){
            exit(1);
            break;
        }else if(match(4,1) == 0){ // )
            break;
        }
        analyzerCaller(returnedToken);
    }while(match_results == -1);
}
