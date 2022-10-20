#include <stdio.h>
int main() {
    float f1, f2;
    int R = 25, per;
    per = scanf("%lf%lf", &f1, &f2);
    
    if (per == 2) {
        if ((f1*f1 + f2*f2) < R) {
            printf("GOTCHA\n");
            
        }else printf("MISS\n");
    }
    else printf("n/a\n");
    return 0;
}
