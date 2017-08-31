#ifndef MAINANALYZER
#define MAINANALYZER

void analyzer(char[77], struct TokenReturn*);// int*, int*);

extern int forwadPosition;
extern int backPosition;
extern struct ReserveWord *startReserve;
extern struct SymbolTable *startSymbol;
extern int varCountID;
#endif // MAINANALYZER
