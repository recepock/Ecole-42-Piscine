#include<unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strcmp(char *s1, char*s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if ((s1[i] == '\0' && s2[i] != '\0') || (s1[i] != '\0' && s2[i] == '\0'))
		return (s1[i] - s2[i]);
	return (0);
}

void	ft_swap(char **argv, int index, int min)
{
	char	*temp;

	temp = argv[index];
	argv[index] = argv[min];
	argv[min] = temp;
}

void	ft_sort(char **argv, int size)
{
	int	index;
	int	jndex;
	int	min;

	index = 0;
	while (++index < size - 1)
	{
		jndex = index;
		min = index;
		while (++jndex < size)
			if (ft_strcmp(argv[min], argv[jndex]) > 0)
				min = jndex;
		if (ft_strcmp(argv[index], argv[min]) >= 0)
			ft_swap(argv, index, min);
	}
}

int	main(int argc, char **argv)
{
	int	index;
	int	jndex;

	index = 0;
	if (argc > 1)
	{
		ft_sort(argv, argc);
		while (++index < argc)
		{
			jndex = -1;
			while (argv[index][++jndex] != '\0')
				ft_putchar(argv[index][jndex]);
			ft_putchar('\n');
		}
	}
	return (0);
}
