#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putstrnl(char *str)
{
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putnbr(nb / 10);
		ft_putchar('8');
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(-nb);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putchar((nb % 10) + '0');
	}
	else
	{
		ft_putchar((nb % 10) + '0');
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	while (par->str != NULL)
	{
		ft_putstrnl(par->str);
		ft_putnbr(par->size);
		write(1, "\n", 1);
		ft_putstrnl(par->copy);
		par++;
	}
}
