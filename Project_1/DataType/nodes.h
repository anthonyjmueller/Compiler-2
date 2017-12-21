#ifndef NODES_H_INCLUDED
#define NODES_H_INCLUDED

struct node {
    int nodeType; //1 green 2 blue
    int numParams;
    int varType;
    int offset;
    int level;
    int lexID;
    char name[72];
    int typeList[50];
    struct node *next;
    struct node *prev;
};

int checkAddGreenNode();
int checkAddBlueNode(int type);
void popScope();
int getType();
struct node* getProc();

extern struct TokenReturn *returnedToken;
extern int level;
extern int offset;
extern struct node *currGreen;
extern struct node *currEnd;
extern FILE *writePtr;
extern FILE *memwritePtr;
extern char lineNum[];


#endif // NODES_H_INCLUDED
