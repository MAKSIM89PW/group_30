#include <stdio.h>
void gen_field();
int racket();

int main()
{
gen_field();
    return 0;
}

void gen_field()
{
    int width = 25,
    large = 80;
    char field [width][large];
    
    for (int i = 1; i<=width;i++)
    {
        for (int j = 1; j<=large;j++)
        {
            if ((i==1 && j == 1) || (i== 1 && j == large) || (i == width && j == 1) || (i == width && j == large))
            {
            field[i-1][j-1] = '+';
            }
            else if (i==1 || i == width)
            {
            field[i-1][j-1] = '=';
            }
            else 
            if (j == 1 || j == large || j == 41 || j == 40)
            {
              field[i-1][j-1] = '|';
            }
            else {
               field[i-1][j-1] = ' ';
            }

        }
    }
    for (int i = 1; i<=width;i++)
    {
        for (int j = 1; j<=large;j++)
        {
            printf("%c", field[i-1][j-1]);
        }
     printf("\n");
    }
}
/*int racket(int a, int b, char field[25][80])
{

}

*/
