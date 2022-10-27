/*
    Search module for the desired value from data array.

    Returned value must be:
        - "even"
        - ">= mean"
        - "<= mean + 3 * sqrt(variance)"
        - "!= 0"

        OR

        0
*/

#include <stdio.h>
#include <math.h>

#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);
void search(int *a, int n);

void output_result(int max_v,
                   int min_v,
                   double mean_v,
                   double variance_v);

int main() {
    int n, data[NMAX];
    int e = input(data, &n);
    if (e == 0) {
        printf("n/a\n");
        return 0;
    }
    search(data, n);
    return 0;
}

void search(int *a, int n) {
    double m = mean(a, n);
    double v = variance(a, n);
    for (int *p = a; p - a < n; p++) {
        if (*p % 2 == 0 && *p >= m && *p <= (m + 3 * sqrt(v))) {
            printf("%d", *p);
            break;
        }
    }
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
    printf("\n");
}

int max(int *a, int n) {
    int max = *a;
    for (int *p = a + 1; p - a < n; p++) {
        max = (*p > max)? *p : max;
    }
    return max;
}

int min(int *a, int n) {
    int min = *a;
    for (int *p = a + 1; p - a < n; p++) {
        min = (*p < min)? *p : min;
    }
    return min;
}

double mean(int *a, int n) {
    double m = 0;
    for (int *p = a; p - a < n; p++) {
        m += *p;
    }
    return m / n;
}

double variance(int *a, int n) {
    double var = 0, m = mean(a, n);
    for (int *p = a; p - a < n; p++) {
        var += pow(*p - m, 2) / n;
    }
    return var;
}

void output_result(int max_v,
                   int min_v,
                   double mean_v,
                   double variance_v) {
    printf("%d %d %.6lf %.6lf", max_v, min_v, mean_v, variance_v);
}


