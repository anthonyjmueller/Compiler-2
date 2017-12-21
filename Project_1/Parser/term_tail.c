#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "Productions.h"
#include "../Analyizer/AnalyzerCaller.h"
#include "../DataType/LinkedList.h"
#include "../Analyizer/Print_Tokens/PrintHandler.h"

char expected[];

int term_tail(int recType){
    if(match(3, 0) == 0 || match(3,1) == 0 || match(3,2) == 0 || match(3,3) == 0 || match(3,4) == 0 ){ // mulop
        int table;
        if(match(3,3) == 0 || match(3,4) == 0){
            table = 1;
        }else if(match(3,2) == 0 ){
            table = 2;
        }else{
            table = 3;
        }
        analyzerCaller(returnedToken);
        int fType = factor();
        int returnType;
        //for * and /
        if(table == 1){
            if(fType == 1 && recType == 1){ //both ints
                returnType = 1;
            }
            else if(fType == 2 && recType == 2){ //both reals
                returnType = 2;
            }
            else if(fType == 0 || recType == 0){
                returnType = 0;
            }else{
                fprintf(writePtr, "     SYMERROR:   Incompatible types for mulop '*' or '/' ");
                fprintf(writePtr, "\n");
                returnType = 0;
            }
        }else if(table == 2){
            if(fType == 5 && recType == 5){ //both bools
                returnType = 5;
            }
            else if(fType == 0 || recType == 0){
                returnType = 0;
            }else{
                fprintf(writePtr, "     SYMERROR:   Incompatible types for mulop 'and' ");
                fprintf(writePtr, "\n");
                returnType = 0;
            }
        }else if(table == 3){
            if(fType == 1 && recType == 1){ //both int
                returnType = 1;
            }
            else if(fType == 0 || recType == 0){
                returnType = 0;
            }else{
                fprintf(writePtr, "     SYMERROR:   Incompatible types for mulop 'mod' or 'div' ");
                fprintf(writePtr, "\n");
                returnType = 0;
            }
        }
        return term_tail(returnType);
    }
    else if(match(4, 1) == 0 || match(13, 1) == 0 || match(4, 3) == 0 || match(7, 8) == 0 || match(7, 5) == 0 || match(7, 6) == 0 ||
            match(13, 2) == 0 || match(7, 3) == 0 || match(2, 0) == 0 || match(2,1) == 0 || match(2,2) == 0 || match(2,3) == 0 || match(2, 4) == 0 || match(1, 0) == 0 || match(1,1) == 0 || match(1,2) == 0) //) , ] do then else ; end relop addop
    {
        return recType;
    }
    else{
        strcpy(expected, "'relop' or 'else' or ';' or 'end' or 'then' or 'do' or ']' or ',' or ')' or 'addop' or 'mulop'");
        term_tailSync();
        goto end;
    }
end:;
return 0;
}

void term_tailSync(){
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
        }else if(match(1, 0) == 0 || match(1,1) == 0 || match(1,2) == 0){ // addop
            break;
        }
        analyzerCaller(returnedToken);
    }while(match_results == -1);
}
