#include "prefixN.h"
// priority of operations
int priority(char c) {
    int flag = 0;
    switch (c) {
        case ')':
        case '(':
            flag = 0;
            break;
        case '*':
        case '/':
            flag = 2;
            break;
        case '+':
        case '-':
            flag = 1;
            break;
        case 's':
        case 'q':
        case 'r':
        case 't':
        case 'c':
        case 'o':
        case 'i':
        case 'n':
        case 'l':
            flag = 1;
            break;
    }
    return flag;
}
// analyze function & push it to stack
void parse_functions(struct stack *stack, char *str) {
    if (strncmp(str, "cos", 3) == 0) {
        push('s', stack);
        push('o', stack);
        push('c', stack);
    }
    if (strncmp(str, "sin", 3) == 0) {
        push('n', stack);
        push('i', stack);
        push('s', stack);
    }
    if (strncmp(str, "tan", 3) == 0) {
        push('n', stack);
        push('a', stack);
        push('t', stack);
    }
    if (strncmp(str, "ctg", 3) == 0) {
        push('g', stack);
        push('t', stack);
        push('c', stack);
    }
    if (strncmp(str, "sqrt", 4) == 0) {
        push('t', stack);
        push('r', stack);
        push('q', stack);
        push('s', stack);
    }
    if (strncmp(str, "ln", 2) == 0) {
        push('n', stack);
        push('l', stack);
    }
}
// analyze numbers & return it
int parse_numbers(char *str, char *str_out) {
    int i = 0;
    if (((str[i] >= '0' && str[i] <= '9') || str[i] == '.') || (str[i] == '-'
    && ((str[i + 1] >= '0'
    && str[i + 1] <= '9') || str[i +1] == '.'))) {
        while (((str[i] >= '0' && str[i] <= '9') || str[i] == '.') || (str[i] == '-'
        && ((str[i + 1] >= '0' &&
        str[i + 1] <= '9') || str[i +1] == '.'))) {
            i++;
        }
        strncat(str_out, str, i);
        strncat(str_out, " ", i);
    }
    return i;
}
// analyze operators & push it to stack
void parse_operators(char *str, char *str_out, struct stack *stack) {
    if (*str == '-' || *str == '+' || *str == '/' || *str == '*') {
        while (empty(stack) && priority(stack -> top -> val) >= priority(*str)) {
            char sym[2];
            sym[0] = pop(stack);
            sym[1] = '\0';
            strncat(str_out, sym, 1);
            if (priority(sym[0]) != 0) {
                strncat(str_out, " ", 1);
            }
            push(*str, stack);
        }
    }
}
// main function of prefix notation
void prefix_notation(char *str, char *str_out) {
    int i = 0;
    struct stack *stack = init();
    while (str[i] != '\n' && str[i] != '\0') {
        i += parse_numbers(str + i, str_out);
        parse_functions(stack, str + i);
        if (str[i] == 'x') {
            char sym[2];
            sym[0] = 'x';
            sym[1] = ' ';
            strncat(str_out, sym, 2);
        }
        parse_operators(str + i, str_out, stack);
        if (str[i] == '(') {
            push(str[i], stack);
        }
        if (str[i] == ')') {
            while (stack -> top -> val != '(') {
                char sym[1];
                sym[0] = pop(stack);
                strncat(str_out, sym, 1);
            }
            pop(stack);
        }
        i++;
    }
    while (empty(stack)) {
        char sym[2];
        sym[0] = pop(stack);
        sym[1] = '\0';
        strncat(str_out, sym, 1);
    }
    destroy(stack);
}
