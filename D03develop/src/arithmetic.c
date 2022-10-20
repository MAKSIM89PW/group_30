#include <stdio.h>
int plus(int a, int b);
int minus(int a, int b);
int umno(int a, int b);

int main() {
    int a, b, sheet;
    char bukva;
    sheet = scanf ("%d %d%c", &a, &b, &bukva);
    if (sheet == 3  && bukva  == '\n') {
        printf("%d %d %d ", plus(a, b), minus(a, b), umno( a, b));
        if (b == 0) {
            printf("n/a\n");
            
        }else {
            printf ("%d\n", a / b);
            
        }
    }else printf( "n/a\n");
    return 0;
    
}
        
int plus(int a, int b) {
    return( a + b);
    
}

int minus(int a, int b) {
    return( a - b);
    
}

int umno(int a, int b) {
    return( a * b);
    
}
