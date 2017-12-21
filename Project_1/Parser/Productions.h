#ifndef PRODUCTIONS
#define PRODUCTIONS
#include <stdio.h>
#include <stdlib.h>

#include "../DataType/LinkedList.h"
#include "../DataType/nodes.h"

extern int match_results;
extern struct TokenReturn *returnedToken;
extern struct node *currGreen;
extern struct node *currEnd;
extern int potenAdd;

void program();
void program_tail();
void program_tail2();
void identifier_list(int*);
void identifier_list_tail(int*);
void declarations();
void declarations_tail();
int type();
int standard_type();
void subprogram_declerations();
void subprogram_declarations_tail();
void subprogram_declaration();
void subprogram_declaration_tail();
void subprogram_declaration_tail2();
void subprogram_head();
void arguments();
void parameter_list();
void parameter_list_tail();
void compound_statement();
void optional_statements();
void statement_list();
void statement_list_tail();
void statement();
void statement_tail();
int variable();
int variable_tail();
void procedure_statement();
void procedure_statement_tail();
void expression_list();
void expression_list_tail();
int expression();
int expression_tail();
int simple_expression();
int simple_expression_tail();
int term();
int term_tail();
int factor();
int factor_tail();
void sign();

int match(int, int);


#endif // PRODUCTIONS
