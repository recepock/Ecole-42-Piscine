#include "ft_bsq.h"
#define BUFF1 1000000
#define BUFF2 8000000

void	ft_strconcat(char *dest, char *src, int *size, int buff_size)
{
	int		i;
	int		c;

	i = 0;
	if ((*size) > buff_size && (*size) % buff_size == 0)
	{
		if (dest[*size - buff_size])
			i = *size - buff_size;
	}
	c = 0;
	while (dest[i])
		i++;
	while (src[c] && c < buff_size)
	{
		dest[i] = src[c];
		i++;
		c++;
	}
	while (c >= 0)
	{
		src[c] = '\0';
		c--;
	}
	dest[i] = '\0';
}

void	ft_check_infinity(int *size, char *str, int buf)
{
	if (*size == buf)
	{
		if (ft_strlen_mod(str) == 0)
		{
			ft_putstr("");
			*size = -1;
		}
	}
}
int		g_size;

char	*ft_read(int fd, int buff_size)
{
	char	*buff;
	char	*str;
	char	*temp;

	g_size = 0;
	buff = (char *)malloc(sizeof(*str) * (buff_size + 1));
	str = (char *)malloc(sizeof(*str) * (g_size + 1));
	temp = (char *)malloc(sizeof(*str) * (g_size + 1));
	str[0] = 0;
	temp[0] = 0;
	while (read(fd, buff, buff_size) && str && temp && g_size >= 0)
	{
		g_size += buff_size;
		ft_strcpy(temp, str);
		free(str);
		str = (char *)malloc(sizeof(*str) * (g_size + 1));
		ft_strcpy(str, temp);
		ft_strconcat(str, buff, &g_size, buff_size);
		str[g_size] = '\0';
		free(temp);
		temp = (char *)malloc(sizeof(*temp) * (g_size + 1));
		ft_check_infinity(&g_size, str, buff_size);
	}
	free(temp);
	return (str);
}

int		g_i;
int		g_fd;

int	main(int argc, char **argv)
{
	char	*str;

	str = NULL;
	g_i = 0;
	if (argc != 1)
	{
		while (++g_i < argc)
		{
			g_fd = open(argv[g_i], O_RDONLY);
			if (g_fd > 0)
			{
				str = ft_read(g_fd, BUFF2);
				ft_start(str);
				close(g_fd);
			}
			else
				ft_putstr("map error\n");
		}
	}
	else
	{
		str = ft_read(0, BUFF1);
		ft_start(str);
	}
	return (0);
}
