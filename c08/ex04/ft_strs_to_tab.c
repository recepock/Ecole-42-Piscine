#include <stdio.h>
#include <stdlib.h>
#include "ft_stock_str.h"

int	len(char *str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*p;
	int		i;

	p = (char *)malloc((len(src) + 1) * sizeof(char));
	if (p == 0)
		return (0);
	i = 0;
	while (src[i] != 0)
	{
		p[i] = src[i];
		i++;
	}
	p[i] = 0;
	return (p);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*p;
	int					i;

	p = (struct s_stock_str *)malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		p[i].size = len(av[i]);
		p[i].str = av[i];
		p[i].copy = ft_strdup(av[i]);
		i++;
	}
	p[i].size = 0;
	p[i].str = NULL;
	p[i].copy = NULL;
	return (p);
}
