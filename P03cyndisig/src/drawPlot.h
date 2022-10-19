#ifndef SRC_DRAWPLOT_H_
#define SRC_DRAWPLOT_H_
#define NMAX 100
#define COLS 80  //  x
#define ROWS 25  //  y
#include "prefixN.h"
#include "calc.h"
void input(char* str);
void make_dots(char* str, double* data);
void normalize(double* data, int* a);
void output(const int* arr);
#endif  //  SRC_DRAWPLOT_H_
