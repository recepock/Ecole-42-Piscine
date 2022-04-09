#include "ft_bsq.h"

int	g_x;
int	g_y;
int	g_start;

int	ft_bigger_sqr(char *str, int position[2], t_instr *info, int size)
{
	g_x = size - 1;
	g_y = 0;
	g_start = info->length + position[0] + (position[1]) * (info->width + 1);
	if (position[0] + size > info->width)
		return (0);
	else if (position[1] + size > info->height)
		return (0);
	while (g_y < size - 1)
	{
		if (str[g_start + g_x + g_y * (info->width + 1)] == info->empty)
			g_y++;
		else
			return (0);
	}
	g_x = 0;
	while (g_x < size)
	{	
		if (str[g_start + g_x + g_y * (info->width + 1)] == info->empty)
			g_x++;
		else
			return (0);
	}
	return (1);
}
