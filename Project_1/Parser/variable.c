#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "Productions.h"
#include "../Analyizer/AnalyzerCaller.h"
#include "../DataType/LinkedList.h"
#include "../Analyizer/Print_Tokens/PrintHandler.h"

char expected[];

int variable(){
    if(match(8, 10) == 0){ // else
            int type = getType();
            if(type == 0){
                fprintf(writePtr, "     SYMERROR:   Variable name ");
                fprintf(writePtr, (*returnedToken).tokenChars);
                fprintf(writePtr, " not in scope");
                fprintf(writePtr, "\n");
            }
            analyzerCaller(returnedToken);
            return variable_tail(type);
    }
    else{
        strcpy(expected, "'id_var'");
        variableSync();
        goto end;
    }
end:;
return 0;
}

void variableSync(){
    fprintf(writePtr, "     SYNERROR:   Found ");
    fprintf(writePtr, (*returnedToken).tokenChars);
    fprintf(writePtr, " expected ");
    fprintf(writePtr, expected);
    fprintf(writePtr, "\n");
    do{
        if(match(15,0) == 0){
            exit(1);
            break;
        }else if(match(14, 0) == 0){ // assignop
            break;
        }
        analyzerCaller(returnedToken);
    }while(match_results == -1);
}
