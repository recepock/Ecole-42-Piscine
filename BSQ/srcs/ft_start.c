#include "ft_bsq.h"

int	g_i;
int	g_c;
int	g_lines;

int	ft_get_width(char *st, t_instr inf, int width)
{
	g_i = inf.length - 1;
	g_c = 0;
	g_lines = 0;
	while (st[++g_i])
	{
		if (st[g_i] == '\n')
		{
			if (width != -1 && width != g_c)
				return (-1);
			width = g_c;
			g_c = 0;
			g_lines++;
		}
		else if (st[g_i] != inf.empty && st[g_i] != inf.obst)
			return (-1);
		else if (g_c == 2147483647)
			return (-1);
		else
			g_c++;
	}
	if (g_lines == inf.height)
		return (width);
	return (-1);
}

void	ft_start(char *str)
{
	t_instr		*info;
	t_record	*record;
	int			width;

	info = ft_first_line(str);
	record = ft_new_record();
	if (info)
	{
		width = -1;
		info->width = ft_get_width(str, *info, width);
		if (info->width > 0)
		{
			ft_get_record(info, str, record);
			ft_fill_board(record, str, info);
			ft_put_result(str, info->length);
			free(str);
		}
		else
			ft_putstr("map error\n");
	}
	else
		ft_putstr("map error\n");
}
