#ifndef SRC_PREFIXN_H_
#define SRC_PREFIXN_H_
#include <string.h>
#include "stack.h"
void parse_functions(struct stack *stack, char *str);
int parse_numbers(char *str, char *str_out);
void parse_operators(char *str, char *str_out, struct stack *stack);
void prefix_notation(char *str, char *str_out);
#endif  //  SRC_PREFIXN_H_
