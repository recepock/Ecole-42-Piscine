#include <unistd.h>
#include "ft_bsq.h"

int	ft_atoi(char *str)
{
	int	nb;
	int	i;

	nb = 0;
	i = 0;
	while (*(str + i) <= 57 && *(str + i) >= 48)
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (nb);
}

void	ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (*(src + i))
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = src[i];
}

void	ft_put_result(char *str, int start)
{
	int	i;

	i = start;
	while (*(str + i))
		i++;
	write(1, &str[start], i - start);
}
