#include "calc.h"
// analyze functions
void calc_functions(char *str, struct stackD *stack) {
    if (strncmp(str, "cos", 3) == 0) {
        double x = popD(stack);
        x = cos(x);
        pushD(x, stack);
    }
    if (strncmp(str, "sin", 3) == 0) {
        double x = popD(stack);
        x = sin(x);
        pushD(x, stack);
    }
    if (strncmp(str, "tan", 3) == 0) {
        double x = popD(stack);
        x = tan(x);
        pushD(x, stack);
    }
    if (strncmp(str, "ctg", 3) == 0) {
        double x = popD(stack);
        x = 1.0 / tan(x);
        pushD(x, stack);
    }
    if (strncmp(str, "ln", 2) == 0) {
        double x = popD(stack);
        x = log(x);
        pushD(x, stack);
    }
    if (strncmp(str, "sqrt", 4) == 0) {
        double x = popD(stack);
        x = sqrt(x);
        pushD(x, stack);
    }
}
// analyze operations
void calc_operations(const char *str, struct stackD *stack) {
    if (*str == '-') {
        double a = popD(stack);
        double b = popD(stack);
        pushD(b - a, stack);
    }
    if (*str == '*') {
        double a = popD(stack);
        double b = popD(stack);
        pushD(b * a, stack);
    }
    if (*str == '/') {
        double a = popD(stack);
        double b = popD(stack);
        pushD(b / a, stack);
    }
    if (*str == '+') {
        double a = popD(stack);
        double b = popD(stack);
        pushD(b + a, stack);
    }
}
double Stack(char *str, double x) {
    int i = 0;
    struct stackD *stack = initD();
    while (str[i] != '\n' && str[i] != '\0') {
    if (str[i] == 'x') {
      pushD(x, stack);
    }
    if (((str[i] >= '0' && str[i] <= '9') || str[i] == '.') || (str[i] == '-'
    && ((str[i + 1] >= '0'
    && str[i + 1] <= '9') || str[i + 1] == '.'))) {
      pushD(atof(str + i), stack);
      while (((str[i] >= '0' && str[i] <= '9') || str[i] == '.') || (str[i] == '-'
      && ((str[i + 1] >= '0'
      && str[i + 1] <= '9') || str[i + 1] == '.'))) {
        i++;
      }
    }
    calc_functions(str + i, stack);
    calc_operations(str + i, stack);
    i++;
  }
  double res = 0;
  if (emptyD(stack))
    res = popD(stack);
  destroyD(stack);
  return res;
}
