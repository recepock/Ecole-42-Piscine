#include<unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	int	index;
	int	jndex;

	index = 1;
	if (argc > 1)
	{
		while (index < argc)
		{
			jndex = -1;
			while (argv[index][++jndex] != '\0')
				ft_putchar(argv[index][jndex]);
			ft_putchar('\n');
			index++;
		}
	}
	return (0);
}
