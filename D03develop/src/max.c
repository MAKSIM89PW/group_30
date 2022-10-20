#include <stdio.h>
int prov(int a, int b);

int main()
{
    int a, b, sheet;
    char bukva;
 
    sheet = scanf ("%d %d%c", &a, &b, &bukva);
    if (sheet == 3  && bukva  == '\n')
    {
        printf ("%d\n", prov(a, b));
    }
    else printf( "n/a\n");
}

int prov(int a, int b)
{
    
    
    if (b < a) {
        return a;
    }
     else
    
         return b;

}

