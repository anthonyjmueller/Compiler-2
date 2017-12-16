#ifndef ANALYZERCALLER
#define ANALYZERCALLER

void analyzerCaller(struct TokenReturn*, FILE *writePtr, FILE *tokenWrite, FILE *readPtr);// int*, int*);

extern int forwadPosition;
extern int backPosition;
extern struct ReserveWord *startReserve;
extern struct SymbolTable *startSymbol;
extern int varCountID;
extern char lineNum[5];
extern int currLine;
extern char readingBuff[77];

#endif // ANALYZERCALLER_H_INCLUDED
