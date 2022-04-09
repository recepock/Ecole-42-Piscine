#include<stdio.h>
#include<stdbool.h>

int	ft_is_prime(int nb)
{
	int	index;

	index = 2;
	while (index < nb)
	{
		if (nb % index == 0)
			return (0);
		index++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	while (nb < 2147483647 && !(ft_is_prime(nb)))
		nb++;
	return (nb);
}
