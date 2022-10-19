#ifndef SRC_CALC_H_
#define SRC_CALC_H_
#include <string.h>
#include <math.h>
#include "stack.h"
void calc_functions(char *str, struct stackD *stack);
void calc_operations(const char *str, struct stackD *stack);
double Stack(char *str, double x);
#endif  //  SRC_CALC_H_
