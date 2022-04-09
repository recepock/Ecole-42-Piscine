#include<stdio.h>

int	ft_is_prime(int nb)
{
	int	index;

	if (nb <= 1)
		return (0);
	if (nb == 2)
		return (1);
	index = 2;
	while (index < nb && index < 2147483647)
	{
		if (nb % index == 0)
			return (0);
		index++;
	}
	return (1);
}
