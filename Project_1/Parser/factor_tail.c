#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "Productions.h"
#include "../Analyizer/AnalyzerCaller.h"
#include "../DataType/LinkedList.h"

char expected[];

void factor_tail(){
    if(match(4,2) == 0){ // [
            analyzerCaller(returnedToken);
            expression();
        if(match(4, 3) == -1){ // ]
            strcpy(expected, "']'");
            factor_tailSync();
            goto end;
        }
        analyzerCaller(returnedToken);
    }
    else if(match(4, 1) == 0 || match(13, 1) == 0 || match(4, 3) == 0 || match(7, 8) == 0 || match(7, 5) == 0 || match(7, 6) == 0 ||
            match(13, 2) == 0 || match(7, 3) == 0 || match(2, 0) == 0 || match(2,1) == 0 || match(2,2) == 0 || match(2,3) == 0 || match(2, 4) == 0 || match(1, 0) == 0 ||
            match(1,1) == 0 || match(3, 0) == 0 || match(3,1) == 0 || match(3,2) == 0 ) //) , ] do then else ; end relop addop mulop
    {
    }
    else{
        strcpy(expected, "'relop' or 'else' or ';' or 'end' or 'then' or 'do' or ']' or ',' or ')' or 'addop' or 'mulop' or '['");
        factor_tailSync();
        goto end;
    }
end:;
}

void factor_tailSync(){
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
        }else if(match(2, 0) == 0 || match(2,1) == 0 || match(2,2) == 0 || match(2,3) == 0 || match(2, 4) == 0){ // relop
            break;
        }else if(match(1, 0) == 0 || match(1,1) == 0 ){ // addop
            break;
        }else if(match(3, 0) == 0 || match(3,1) == 0 || match(3,2) == 0 ){ // mulop
            break;
        }
    }while(match_results == -1);
}
