#ifndef PRINTHANDLER
#define PRINTHANDLER

void ListingPrinter(struct TokenReturn*, int);

void InitTokenFile(FILE*);

void printToken(struct TokenReturn*, char[], FILE*);

#endif // PRINTHANDLER
