#include "graph.h"
int main() {
  char str[NMAX];
  char str_out[NMAX];
  str_out[0] = '\0';
  input(str);  //  input our function
  prefix_notation(str, str_out);  //  infix to prefix notation
  double *data = malloc(COLS * sizeof(double));
  int *out = malloc(COLS * sizeof(int));
  make_dots(str_out, data);  //  calculate dots coordinates
  normalize(data, out);  //  normalize dots
  output(out);  //  output graph in terminal
  free(data);
  free(out);
}
