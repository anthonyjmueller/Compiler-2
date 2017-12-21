#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "Productions.h"
#include "../Analyizer/AnalyzerCaller.h"
#include "../DataType/LinkedList.h"
#include "../Analyizer/Print_Tokens/PrintHandler.h"

char expected[];

void identifier_list(int *count){
    if(match(8,10) == 0){
        if(checkAddBlueNode(6) == 1){
            (*currGreen).typeList[*count] = 6;
            *count = *count + 1;
            offset += potenAdd;
            potenAdd = 0;
        }else{
            fprintf(writePtr, "     SYMERROR:   Variable name ");
            fprintf(writePtr, (*returnedToken).tokenChars);
            fprintf(writePtr, " already declared");
            fprintf(writePtr, "\n");
        }
        analyzerCaller(returnedToken);
        identifier_list_tail(count);
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
            exit(1);
            break;
        }else if(match(4,1)  == 0){ // )
            break;
        }
    }while(match_results == -1);
}
