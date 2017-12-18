#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "Productions.h"
#include "../Analyizer/AnalyzerCaller.h"
#include "../DataType/LinkedList.h"

char expected[];

void expression_tail(){
    if(match(2, 0) == 0 || match(2,1) == 0 || match(2,2) == 0 || match(2,3) == 0 || match(2, 4) == 0){ // relop
        analyzerCaller(returnedToken);
        simple_expression();
    }
    else if(match(4, 1) == 0 || match(13, 1) == 0 || match(4, 3) == 0 || match(7, 8) == 0 || match(7, 5) == 0 || match(7, 6) == 0 || match(13, 2) == 0 || match(7, 3) == 0) //) , ] do then else ; end
    {
    }
    else{
        strcpy(expected, "'relop' or 'else' or ';' or 'end' or 'then' or 'do' or ']' or ',' or ')'");
        expression_tailSync();
        goto end;
    }
end:;
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
