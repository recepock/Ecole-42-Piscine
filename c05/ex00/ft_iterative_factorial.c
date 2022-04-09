#include<stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	index;
	int	factorial;

	if (nb < 0)
		return (0);
	index = 0;
	factorial = 1;
	while (++index <= nb)
		factorial = factorial * index;
	return (factorial);
}
