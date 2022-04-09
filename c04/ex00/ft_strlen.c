int	ft_strlen(char *str)
{
	char	*metin;
	int		basamak;

	metin = str;
	basamak = 0;
	while (*metin != 0)
	{
		basamak++;
		metin++;
	}
	return (basamak);
}
