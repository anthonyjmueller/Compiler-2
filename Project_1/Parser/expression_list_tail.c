#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "Productions.h"
#include "../Analyizer/AnalyzerCaller.h"
#include "../DataType/LinkedList.h"
#include "../Analyizer/Print_Tokens/PrintHandler.h"

char expected[];

void expression_list_tail(int *typeList[50], int *count){
    if(match(13, 1) == 0){ // ,
        analyzerCaller(returnedToken);
        int eType = expression();
        typeList[*count] = eType;
        *count = (*count) + 1;
        expression_list_tail(typeList, count);
    }
    else if(match(4,1) == 0){ // )
    }
    else{
        strcpy(expected, "'(' or 'else' or ';' or 'end'");
        expression_list_tailSync();
        goto end;
    }
end:;
}

void expression_list_tailSync(){
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
