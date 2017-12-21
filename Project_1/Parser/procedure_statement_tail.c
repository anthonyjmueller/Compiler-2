#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "Productions.h"
#include "../Analyizer/AnalyzerCaller.h"
#include "../DataType/LinkedList.h"
#include "../Analyizer/Print_Tokens/PrintHandler.h"

char expected[];

void procedure_statement_tail(int *typeList[50], int *count, struct node *checkCall){
    if(match(4,0) == 0){ // (
        analyzerCaller(returnedToken);
        expression_list(typeList, count);

        if(checkCall != NULL){
            if(*count != (*checkCall).numParams){
                fprintf(writePtr, "     SYMERROR:   Incorrect number of arguments in procedure call ");
                fprintf(writePtr, "\n");
            }
        }

        if(match(4, 1) == -1){ // )
            strcpy(expected, "')'");
            procedure_statement_tailSync();
            goto end;
        }
        analyzerCaller(returnedToken);
    }
    else if(match(7, 6) == 0 || match(13, 2) == 0 || match(7, 3) == 0){ // else ; end
        if(checkCall != NULL){
            if(*count != (*checkCall).numParams && checkCall != NULL){
                fprintf(writePtr, "     SYMERROR:   Incorrect number of arguments in procedure call ");
                fprintf(writePtr, "\n");
            }
        }
    }
    else{
        strcpy(expected, "'(' or 'else' or ';' or 'end'");
        procedure_statement_tailSync();
        goto end;
    }
end:;
}

void procedure_statement_tailSync(){
    fprintf(writePtr, "     SYNERROR:   Found ");
    fprintf(writePtr, (*returnedToken).tokenChars);
    fprintf(writePtr, " expected ");
    fprintf(writePtr, expected);
    fprintf(writePtr, "\n");
    do{

        if(match(15,0) == 0){
            exit(1);
            break;
        }else if(match(7, 3) == 0){ // end
            break;
        }else if(match(13, 2) == 0){ // ;
            break;
        }else if(match(7, 6) == 0){ // else
            break;
        }
        analyzerCaller(returnedToken);
    }while(match_results == -1);
}
