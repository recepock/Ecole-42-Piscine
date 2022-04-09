#include <unistd.h>

void	ft_putstr(char *str)
{
	char	*metin;

	metin = str;
	while (*metin != 0)
	{
		write(1, metin, 1);
		metin++;
	}
}
