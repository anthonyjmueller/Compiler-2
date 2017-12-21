#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "Productions.h"
#include "../Analyizer/AnalyzerCaller.h"
#include "../DataType/LinkedList.h"
#include "../Analyizer/Print_Tokens/PrintHandler.h"

char expected[];

int factor_tail(int recType){
    if(match(4,2) == 0){ // [
            analyzerCaller(returnedToken);
            int eType = expression();
        if(match(4, 3) == -1){ // ]
            strcpy(expected, "']'");
            factor_tailSync();
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
    else if(match(4, 1) == 0 || match(13, 1) == 0 || match(4, 3) == 0 || match(7, 8) == 0 || match(7, 5) == 0 || match(7, 6) == 0 ||
            match(13, 2) == 0 || match(7, 3) == 0 || match(2, 0) == 0 || match(2,1) == 0 || match(2,2) == 0 || match(2,3) == 0 || match(2, 4) == 0 || match(1, 0) == 0 ||
            match(1,1) == 0 || match(1,2) == 0 || match(3, 0) == 0 || match(3,1) == 0 || match(3,2) == 0 || match(3,3) == 0 || match(3,4) == 0 ) //) , ] do then else ; end relop addop mulop
    {
        return recType;
    }
    else{
        strcpy(expected, "'relop' or 'else' or ';' or 'end' or 'then' or 'do' or ']' or ',' or ')' or 'addop' or 'mulop' or '['");
        factor_tailSync();
        goto end;
    }
end:;
return 0;
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
        }else if(match(1, 0) == 0 || match(1,1) == 0 || match(1,2) == 0){ // addop
            break;
        }else if(match(3, 0) == 0 || match(3,1) == 0 || match(3,2) == 0 || match(3,3) == 0 || match(3,4) == 0){ // mulop
            break;
        }
    }while(match_results == -1);
}
