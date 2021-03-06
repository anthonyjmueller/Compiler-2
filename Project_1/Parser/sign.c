#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "Productions.h"
#include "../Analyizer/AnalyzerCaller.h"
#include "../DataType/LinkedList.h"
#include "../Analyizer/Print_Tokens/PrintHandler.h"

char expected[];

void sign(){
    if(match(1,0) == 0|| match(1,1) == 0){ // + -
        analyzerCaller(returnedToken);
    }
    else{
        strcpy(expected, "'+' or '-'");
        signSync();
        goto end;
    }
end:;
}

void signSync(){
    fprintf(writePtr, "     SYNERROR:   Found ");
    fprintf(writePtr, (*returnedToken).tokenChars);
    fprintf(writePtr, " expected ");
    fprintf(writePtr, expected);
    fprintf(writePtr, "\n");
    do{

        if(match(15,0) == 0){
            exit(1);
            break;
        }
        else if(match(8, 10) == 0){ // var_id
            break;
        }
        else if(match(6,0) == 0 || match(5,0) == 0){ //num
            break;
        }
        else if(match(4,0) == 0){ //(
            break;
        }
        else if(match(12, 0) == 0){ //(not
            break;
        }
        analyzerCaller(returnedToken);
    }while(match_results == -1);
}
