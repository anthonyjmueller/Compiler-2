#ifndef LINKEDLIST
#define LINKEDLIST
#include<string.h>

struct ReserveWord {
    char resWord[10];
    char token[10];
    int atribute;
    struct ReserveWord *next;
};

struct SymbolTable {
    char name[75];
    int attribute;
    struct SymbolTable *next;
};

struct TokenReturn {
    int token;
    int atribute;
    char tokenChars[72];
};

struct ReserveWord* ReserveWordListCreator();

void ReserveWordInit(struct ReserveWord*);

void SymbolTableInit(struct SymbolTable*);

void TokenReturnInit(struct TokenReturn*);

#endif // LINKEDLIST_H_INCLUDED
