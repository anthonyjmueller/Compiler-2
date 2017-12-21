#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "Productions.h"
#include "../Analyizer/AnalyzerCaller.h"
#include "../DataType/LinkedList.h"
#include "../Analyizer/Print_Tokens/PrintHandler.h"

char expected[];

int variable_tail(int recType){
    if(match(4,2) == 0){ // [
        analyzerCaller(returnedToken);
        int eType = expression();
        if(match(4, 3) == -1){ // ]
            strcpy(expected, "']'");
            variable_tailSync();
            goto end;
        }
        analyzerCaller(returnedToken);
        if(recType == 3 && eType == 1){
            return 1;
        }else if(recType == 4 && eType == 2){
            return 2;
        }else if(recType == 0 || eType == 0){
            return 0;
        }else if(eType != 1 || eType != 2){
            fprintf(writePtr, "     SYMERROR:   Incompatible type for Array index ");
            fprintf(writePtr, "\n");
            return 0;
        }else{
            fprintf(writePtr, "     SYMERROR:   Attempted to index non-array variable ");
            fprintf(writePtr, "\n");
            return 0;
        }
    }
    else if(match(14, 0) == 0){ // assignop
        return recType;
    }
    else{
        strcpy(expected, "'[' or ':='");
        variable_tailSync();
        return 0;
        goto end;
    }
end:;
return 0;
}

void variable_tailSync(){
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
