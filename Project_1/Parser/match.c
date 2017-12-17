#include<stdlib.h>
#include<stdio.h>

#include "Productions.h"
#include "../Analyizer/AnalyzerCaller.h"
#include "../DataType/LinkedList.h"

int match(int token, int attribute){
    int temptok = (*returnedToken).token;
    int tempatt = (*returnedToken).atribute;
    if( temptok == 8 && tempatt >= 10 && token == 8 && attribute >= 10){
        match_results = 0;
    }
    else if( temptok == token && tempatt == attribute){
        match_results = 0;
    }else{
        match_results = -1;
    }
    return match_results;
}
