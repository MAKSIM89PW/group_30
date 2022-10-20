#include <stdio.h>
#include <math.h>
int main() {
double x1, res;
char x2;
scanf("%lf%c", &x1, &x2);
    if (x2 != '\n') {
        printf("n/a");
return 0;
    }
res = 7e-3 * pow(x1, 4) + ((22.8 * pow(x1, (1/3)) - 1e3) * x1+3)
    / (x1 * x1 / 2) - x1 * pow((10 + x1), (2/x1)) - 1.01;
printf("%.1lf\n", res);
}
