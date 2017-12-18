#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "Productions.h"
#include "../Analyizer/AnalyzerCaller.h"
#include "../DataType/LinkedList.h"

char expected[];

void sign(){
    if(match(1,0) == 0|| match(1,1) == 0){ // + -
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
        analyzerCaller(returnedToken);
        if(match(15,0) == 0){
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
    }while(match_results == -1);
}
