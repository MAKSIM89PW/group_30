#include "stack.h"
// initializing double stack
struct stackD *initD() {
    struct stackD *stack = malloc(sizeof(struct stackD));
    stack -> top = NULL;
    return stack;
}
// IsEmpty stackD
int emptyD(struct stackD *stack) {
    int result = 1;
    if (stack -> top == NULL) {
        result = 0;
    }
    return result;
}
// add to top of the stackD
void pushD(double val, struct stackD *stack) {
    struct valD *n = malloc(sizeof(struct valD));
    n -> val = val;
    n -> next = stack -> top;
    stack -> top = n;
}
// return and remove the top in stackD
double popD(struct stackD *stack) {
    double result = 0.0;
    if (stack -> top -> next != NULL) {
        result = stack -> top -> val;
        struct valD *delim = stack -> top;
        stack -> top = stack -> top -> next;
        free(delim);
    } else {
        result = stack -> top -> val;
        struct valD *delim = stack -> top;
        free(delim);
        stack -> top = NULL;
    }
    return result;
}
// destroy stackD
void destroyD(struct stackD *stack) {
    if (stack -> top != NULL) {
        while (stack -> top -> next != NULL) {
            struct valD *delim = stack -> top;
            stack -> top = stack -> top -> next;
            free(delim);
        }
        free(stack -> top);
    }
    free(stack);
}
// initializing stack
struct stack *init() {
    struct stack *stack = malloc(sizeof(struct stack));
    stack -> top = NULL;
    return stack;
}
// IsEmpty stack
int empty(struct stack *stack) {
    int result = 1;
    if (stack -> top == NULL) {
        result = 0;
    }
    return result;
}
// add to top of the stack
void push(char val, struct stack *stack) {
    struct val *n = malloc(sizeof(struct val));
    n -> val = val;
    n -> next = stack -> top;
    stack -> top = n;
}
// return and remove the top in stack
double pop(struct stack *stack) {
    char result;
    if (stack -> top -> next != NULL) {
        result = stack -> top -> val;
        struct val *delim = stack -> top;
        stack -> top = stack -> top -> next;
        free(delim);
    } else {
        result = stack -> top -> val;
        struct val *delim = stack -> top;
        free(delim);
        stack -> top = NULL;
    }
    return result;
}
// destroy stack
void destroy(struct stack *stack) {
    if (stack -> top != NULL) {
        while (stack -> top -> next != NULL) {
            struct val *delim = stack -> top;
            stack -> top = stack -> top -> next;
            free(delim);
        }
        free(stack -> top);
    }
    free(stack);
}
