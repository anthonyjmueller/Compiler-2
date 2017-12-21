#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "Productions.h"
#include "../Analyizer/AnalyzerCaller.h"
#include "../DataType/LinkedList.h"
#include "../Analyizer/Print_Tokens/PrintHandler.h"

char expected[];

int expression_tail(int recType){
    if(match(2, 0) == 0 || match(2,1) == 0 || match(2,2) == 0 || match(2,3) == 0 || match(2, 4) == 0){ // relop
        analyzerCaller(returnedToken);
        int smpType = simple_expression();
        if(smpType == 1 && recType == 1){ //both ints
            return 5;
        }
        else if(smpType == 2 && recType == 2){ //both reals
            return 5;
        }
        else if(smpType == 0 || recType == 0){
            return 0;
        }else{
            fprintf(writePtr, "     SYMERROR:   Incompatible types for relop ");
            fprintf(writePtr, "\n");
            return 0;
        }
    }
    else if(match(4, 1) == 0 || match(13, 1) == 0 || match(4, 3) == 0 || match(7, 8) == 0 || match(7, 5) == 0 || match(7, 6) == 0 || match(13, 2) == 0 || match(7, 3) == 0) //) , ] do then else ; end
    {
        return recType;
    }
    else{
        strcpy(expected, "'relop' or 'else' or ';' or 'end' or 'then' or 'do' or ']' or ',' or ')'");
        expression_tailSync();
        return 0;
        goto end;
    }
end:;
return 0;
}

void expression_tailSync(){
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
        }else if(match(7, 3) == 0){ // end
            break;
        }else if(match(13, 2) == 0){ // ;
            break;
        }else if(match(7, 6) == 0){ // else
            break;
        }else if(match(7, 5) == 0){ // then
            break;
        }else if(match(7, 8) == 0){ // do
            break;
        }else if(match(4, 3) == 0){ // ]
            break;
        }else if(match(13, 1) == 0){ // ,
            break;
        }else if(match(4, 1) == 0){ // )
            break;
        }
    }while(match_results == -1);
}
