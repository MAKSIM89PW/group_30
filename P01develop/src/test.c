#include <stdio.h>
int main()
{
int width = 25,
    large = 80;
    char field [width][large];
    
    for (int i = 1; i<=width;i++)
    {
        for (int j = 1; j<=large;j++)
        {
            if (i==1 || i == width)
            {
            field[i-1][j-1] = '=';
            }
            else 
            if (j == 1 || j == large)
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
    return 0;
}