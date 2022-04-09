int	hata_kontrol_in_base(char *base)
{
	char	*kontrolbase;
	int		i_kontrol;

	kontrolbase = base;
	if (*base == 0 || *(base + 1) == 0)
		return (0);
	while (*kontrolbase)
	{
		if (*kontrolbase == '+' || *kontrolbase == '-'
			|| *kontrolbase == ' ' || *kontrolbase <= 31)
			return (0);
		i_kontrol = 1;
		while (*(kontrolbase + i_kontrol))
		{
			if (*(kontrolbase + i_kontrol) == *kontrolbase)
				return (0);
			i_kontrol++;
		}
		kontrolbase++;
	}
	return (1);
}

int	ft_strlen(char *str)
{
	char	*charptr;
	int		iterator;

	charptr = str;
	iterator = 0;
	while (*charptr != 0)
	{
		iterator++;
		charptr++;
	}
	return (iterator);
}

char	*is_in_base(char *base, char *to_find)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (*to_find == base[i])
			return (base + i);
		i++;
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	unsigned int	nombre;
	int				signe;
	char			*charptr;

	nombre = 0;
	signe = 1;
	if (hata_kontrol_in_base(base))
	{
		charptr = str;
		while (*charptr == ' ' || (*charptr >= 9 && *charptr <= 13))
			charptr++;
		while (*charptr == '-' || *charptr == '+')
		{
			if (*charptr == '-')
				signe *= -1;
			charptr++;
		}
		while (is_in_base(base, charptr))
		{
			nombre *= ft_strlen(base);
			nombre += (unsigned int)(is_in_base(base, charptr) - base);
			charptr++;
		}
	}
	return ((int)(nombre * signe));
}
