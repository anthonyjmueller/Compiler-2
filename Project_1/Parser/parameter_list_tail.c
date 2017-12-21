#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "Productions.h"
#include "../Analyizer/AnalyzerCaller.h"
#include "../DataType/LinkedList.h"
#include "../Analyizer/Print_Tokens/PrintHandler.h"

char expected[];

void parameter_list_tail(int *count){
    if(match(13 , 2) == 0){ // ;
        analyzerCaller(returnedToken);
        if(match(8,10) == -1){ // var_id
            strcpy(expected, "'var_id'");
            parameter_list_tailSync();
            goto end;
        }
        int succ = checkAddBlueNode(0); /////////////////blue node
        if(succ == -1){
            fprintf(writePtr, "     SYMERROR:   Variable name ");
            fprintf(writePtr, (*returnedToken).tokenChars);
            fprintf(writePtr, " already declared");
            fprintf(writePtr, "\n");
        }
        analyzerCaller(returnedToken);
        if(match(10, 2) == -1){ // :
            strcpy(expected, "':'");
            parameter_list_tailSync();
            goto end;
        }
        analyzerCaller(returnedToken);
        int tType = type();
        if (succ == 1){
            (*currEnd).varType = tType;
            offset += 0;
            potenAdd = 0;
        }
        (*currGreen).typeList[*count] = (*currEnd).varType;
        *count = *count + 1;
        parameter_list_tail(count);
    }else if(match(4,1) == 0){
    }
    else{
        strcpy(expected, "';' or ')'");
        parameter_list_tailSync();
        goto end;
    }
end:;
}

void parameter_list_tailSync(){
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
