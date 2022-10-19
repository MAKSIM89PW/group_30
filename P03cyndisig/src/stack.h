#ifndef SRC_STACK_H_
#define SRC_STACK_H_
#include <stdio.h>
#include <stdlib.h>
struct stackD {
    struct valD *top;
};
struct valD {
    double val;
    struct valD *next;
};
// char
struct stack {
    struct val *top;
};
struct val {
    char val;
    struct val *next;
};
// Double stack
struct stackD *initD();
int emptyD(struct stackD *stack);
void pushD(double val, struct stackD *stack);
double popD(struct stackD *stack);
void destroyD(struct stackD *stack);
// Stack
struct stack *init();
int empty(struct stack *stack);
void push(char val, struct stack *stack);
double pop(struct stack *stack);
void destroy(struct stack *stack);
#endif  //  SRC_STACK_H_
