#ifndef PRINTHANDLER
#define PRINTHANDLER

extern FILE *writePtr;

void ListingPrinter(struct TokenReturn*, int);

void InitTokenFile(FILE*);

void printToken(struct TokenReturn*, char[], FILE*);

#endif // PRINTHANDLER
