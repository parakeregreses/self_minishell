int	str_without_quotes_len(char *str, char *c)
{
	int j;
	int	len;
	
	j = 0;
	len = 0;
	while (str[j])
	{
		if (*c != 0)
		{
			while (str[j] && str[j] != *c)
			{
				len ++;
				j++;
			}
			if (str[j] == 0)
			{
				ft_printf("1len in i = %d\n",len);
				return (len);
			}
			j++;
			*c = 0;
		}
		while (str[j] && *c == 0)
		{
			if (str[j] && !ft_ischarinset(str[j], "'\""))
			{
				len++;
				j++;
			}
			if (!str[j])
			{
				ft_printf("2len in i = %d\n",len);
				return (len);
			}
			*c = str[j];
		}
		if (!str[j])
		{
			ft_printf("3len in i = %d\n",len);
			return (len);
		}
		j++;
	}
	ft_printf("0len in i = %d\n",len);
	return (len);
}