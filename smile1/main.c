#include <stdio.h>

void  ft_putchar(char c)
{
	write(1, &c, 1);

}

int main(void)
{
	ft_putchar(':');
	ft_putchar(')');
	ft_putchar('\n');
	return 0;
}