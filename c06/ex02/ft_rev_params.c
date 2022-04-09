#include<unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int ac, char **av)
{
	int	index;

	while (ac - 1)
	{
		index = -1;
		while (av[ac - 1][++index] != '\0')
			ft_putchar(av[ac - 1][index]);
		ft_putchar('\n');
		ac--;
	}
	return (0);
}
