#include<stdio.h>

int	ft_sqrt(int nb)
{
	int	index;

	if (nb <= 0)
		return (0);
	index = 1;
	while (index * index <= nb && index < 46341)
		index++;
	index--;
	if (index * index == nb)
		return (index);
	return (0);
}
