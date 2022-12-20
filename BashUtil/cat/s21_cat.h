#ifndef CAT_C3_SIMPLEBASHUTILS_0_SRC_CAT_S21_CAT_H_
#define CAT_C3_SIMPLEBASHUTILS_0_SRC_CAT_S21_CAT_H_
#include <stdio.h>
#include <string.h>

struct flags {
  int b;
  int e;
  int v;
  int n;
  int s;
  int t;
};

void parseFlag(char *argv[], struct flags *options, int *error, int argc);
void readAndPrintFile(char *filename, struct flags *options);
void checkFiles(int argc, char *argv[], struct flags options);

#endif  // CAT_C3_SIMPLEBASHUTILS_0_SRC_CAT_S21_CAT_H_
