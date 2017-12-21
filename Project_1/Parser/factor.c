#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "Productions.h"
#include "../Analyizer/AnalyzerCaller.h"
#include "../DataType/LinkedList.h"
#include "../Analyizer/Print_Tokens/PrintHandler.h"

char expected[];

int factor(){
    if(match(8, 10) == 0){ // var_id
        int idType = getType();
        analyzerCaller(returnedToken);
        return factor_tail(idType);
    }
    else if(match(6,0) == 0 || match(5,0) == 0){ //num
        if(match(6,0) == 0){
            analyzerCaller(returnedToken);
            return 2;
        }else if(match(5,0) == 0){
            analyzerCaller(returnedToken);
            return 1;
        }
    }
    else if(match(4,0) == 0){ // (
        analyzerCaller(returnedToken);
        int eType = expression();
        if(match(4,1) == -1){ // )
            strcpy(expected, "')'");
            factorSync();
            goto end;
        }
        analyzerCaller(returnedToken);
        return eType;
    }
    else if( match(12, 0) == 0){ //not
        analyzerCaller(returnedToken);
        int fType = factor();
        if(fType == 5){
            return 5;
        }else if (fType == 0){
            return 0;
        }else{
            fprintf(writePtr, "     SYMERROR:   Incompatible type for boolean not operator ");
            fprintf(writePtr, "\n");
            return 0;
        }
    }
    else{
        strcpy(expected, "'var_id' or 'num' or '(' or 'not'");
        factorSync();
        goto end;
    }
end:;
return 0;
}

void factorSync(){
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
        }else if(match(3, 0) == 0 || match(3,1) == 0 || match(3,2) == 0 || match(3,3) == 0 || match(3,4) == 0 ){ // mulop
            break;
        }
    }while(match_results == -1);
}
