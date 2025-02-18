#include <stdio.h>
#include "./includes/ft.h"

int	main(void)
{
	int a;
	int b;

	ft_putchar('a');
	printf("\n");
	ft_putstr("String\n");
	printf("Diff entre d y f %d \n", ft_strcmp("d", "f"));
	printf("Len de hola %d \n", ft_strlen("hola"));
	a = 3;
	b = 5;
	ft_swap(&a, &b);
	printf("a %d b %d\n", a, b);

	return (0);
}
