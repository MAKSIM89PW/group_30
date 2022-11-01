#include <stdio.h>
#include <stdlib.h>

int input(int **a, int *n);
void bubbleSort(int *a, int n);
void output(int *a, int n, int er);

int main(void) {
  int *a = NULL;
  int n, er;
    er = input(&a, &n);
  if (!er) {
    bubbleSort(a, n);
  }
  output(a, n, er);
  free(a);
  return 0;
}

int input(int **a, int *n) {
  int er = 0;
  if (1 != scanf("%d", n)) {
      er = 1;
  }
  if (er || (*a = malloc(*n * sizeof(int))) == NULL) {
      er = 1;
  }
  for (int i = 0; i < *n && !er; i++) {
    if (1 != scanf("%d", *a + i)) {
        er = 1;
    }
  }
  return er;
}

void bubbleSort(int *a, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (a[j] > a[j + 1]) {
        int temp = a[j];
          a[j] = a[j + 1];
          a[j + 1] = temp;
      }
    }
  }
}

void output(int *a, int n, int er) {
  if (er) {
    printf("n/a");
  } else {
    for (int i = 0; i < n - 1; i++) {
      printf("%d ", a[i]);
    }
    printf("%d", a[n - 1]);
  }
}
