#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "Productions.h"
#include "../Analyizer/AnalyzerCaller.h"
#include "../DataType/LinkedList.h"
#include "../Analyizer/Print_Tokens/PrintHandler.h"

char expected[];

void procedure_statement(){
    if(match(7,9) == 0){ // call
        analyzerCaller(returnedToken);
        if(match(8, 10) == -1){ // var_id
            strcpy(expected, "'var_id'");
            procedure_statementSync();
            goto end;
        }
        struct node* checkCall = malloc(sizeof(struct node));
        checkCall = getProc();
        if(checkCall == NULL){
            fprintf(writePtr, "     SYMERROR:   called undefined procedure ");
            fprintf(writePtr, "\n");
        }else{
            offset = 0;
        }

        int typeList[50];
        int count = 0;

        analyzerCaller(returnedToken);
        procedure_statement_tail(&typeList, &count, checkCall);

        if(checkCall != NULL){
            for(int x = 0; x < count; x++){ //check if errors are already reported
                if(typeList[x] == 0){
                    goto end;
                }
            }

            for(int x = 0; x < count; x++){ //check if errors are already reported
                if(typeList[x] != (*checkCall).typeList[x]){
                    fprintf(writePtr, "     SYMERROR:   Incorrect argument types in procedure call ");
                    fprintf(writePtr, "\n");
                    goto end;
                }
            }
        }
    }
    else{
        strcpy(expected, "'var_id'");
        procedure_statementSync();
        goto end;
    }
end:;
}

void procedure_statementSync(){
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
