#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "Productions.h"
#include "../Analyizer/AnalyzerCaller.h"
#include "../DataType/LinkedList.h"
#include "../Analyizer/Print_Tokens/PrintHandler.h"

char expected[];

int term(){
    if(match(8, 10) == 0 || match(5,0) == 0 || match(6,0) == 0 || match(4,0) == 0 || match(12, 0) == 0){ // var_id num ( not
        int fType = factor();
        return term_tail(fType);
    }
    else{
        strcpy(expected, "'var_id' or 'num' or '(' or 'not'");
        termSync();
        goto end;
    }
end:;
return 0;
}

void termSync(){
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
        }else if(match(2, 0) == 0 || match(2,1) == 0 || match(2,2) == 0 || match(2,3) == 0 || match(2, 4) == 0){ // relop
            break;
        }else if(match(1, 0) == 0 || match(1,1) == 0 || match(1,2) == 0 ){ // addop
            break;
        }
        analyzerCaller(returnedToken);
    }while(match_results == -1);
}
