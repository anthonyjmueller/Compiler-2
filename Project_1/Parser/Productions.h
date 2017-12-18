#ifndef PRODUCTIONS
#define PRODUCTIONS
#include <stdio.h>
#include <stdlib.h>

#include "../DataType/LinkedList.h"

extern int match_results;
extern struct TokenReturn *returnedToken;

void program();
void program_tail();
void program_tail2();
void identifier_list();
void identifier_list_tail();
void declarations();
void declarations_tail();
void type();
void standard_type();
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
void variable();
void variable_tail();
void procedure_statement();
void procedure_statement_tail();
void expression_list();
void expression_list_tail();
void expression();
void expression_tail();
void simple_expression();
void simple_expression_tail();
void term();
void term_tail();
void factor();
void factor_tail();
void sign();

int match(int, int);


#endif // PRODUCTIONS
