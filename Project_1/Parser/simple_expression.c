#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "Productions.h"
#include "../Analyizer/AnalyzerCaller.h"
#include "../DataType/LinkedList.h"
#include "../Analyizer/Print_Tokens/PrintHandler.h"

char expected[];

int simple_expression(){
    if(match(8, 10) == 0 || match(5,0) == 0 || match(6,0) == 0 || match(4,0) == 0 || match(12, 0) == 0){ // var_id num ( not
        int tType = term();
        return simple_expression_tail(tType);
    }
    else if(match(1,0) == 0|| match(1,1) == 0){ // + -
        sign();
        int tType = term();
        if(tType != 5 || tType != 6 || tType != 0){
            fprintf(writePtr, "     SYMERROR:   Incompatible types for sign ");
            fprintf(writePtr, "\n");
            tType = 0;
        }
        return simple_expression_tail(tType);
    }
    else{
        strcpy(expected, "'var_id' or 'num' or '(' or 'not' or '+' or '-'");
        simple_expressionSync();
        goto end;
    }
end:;
return 0;
}

void simple_expressionSync(){
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
        }else if(match(2, 0) == 0 || match(2,1) == 0 ||match(2,2) == 0 || match(2,3) == 0 || match(2, 4) == 0){ // relop
            break;
        }
         analyzerCaller(returnedToken);
    }while(match_results == -1);
}

