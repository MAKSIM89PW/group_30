#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
    int n, data[NMAX];
    int e = input(data, &n);
    if (e == 0) {
        printf("n/a\n");
        return 0;
    }
    squaring(data, n);
    output(data, n);

    return 0;
}

int checkInput(int *e) {
    return (e == 0)? 0: 1;
}

int input(int *a, int *n) {
    char c;
    int e = scanf("%d%c", n, &c);
    if (e == 0 || c != '\n') {
        return 0;
    }
    for (int *p = a; p - a < *n; p++) {
        e = scanf("%d", p);
        if (e == 0) {
            return 0;
        }
    }
    return 1;
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        printf("%d ", *p);
    }
}

void squaring(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        *p = *p * *p;
    }
}


