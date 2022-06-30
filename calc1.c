#include <stdio.h>
#include <stdlib.h>

int main()

{
    int x, y;
    int i;
    printf("input x=");
    scanf("%d", &x);
    printf("input y=");
    scanf("%d", &y);

    printf("oper: \n1 = *\n2 = +\nselect code = ");
    scanf("%d", &i);

    if(i == 1)
    printf("%d * %d = %d", x, y, x * y);

    if(i == 2)
    printf("%d + %d = %d", x, y, x + y);

    return 0;
}


