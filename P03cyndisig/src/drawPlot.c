#include "drawPlot.h"
// input function
void input(char *str) {
  char c = getchar();
  int i = 0;
  while (c != '\n') {
    str[i] = c;
    c = getchar();
    i++;
  }
  str[i] = c;
}
// make dots
void make_dots(char* str, double* data) {
    double dx = (4.0 * M_PI) / COLS;
    for (int i = 0; i < COLS; i++) {
        data[i] = Stack(str, i*dx);
    }
}
// normalize dots
void normalize(double *data, int *a) {
  double dy = 2.0 / (ROWS - 1);
  for (int i = 0; i < COLS; i++) {
    if (isnan(data[i])) {
      a[i] = -1000;
    } else {
      a[i] = round((data[i] + 1) / dy);
    }
  }
}
// Draw field
void output(const int *arr) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      if (arr[j] == i) {
        printf("*");
      } else {
        printf(".");
      }
    }
    printf("\n");
  }
}
