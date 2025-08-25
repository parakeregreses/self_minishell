/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_quote2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 22:49:23 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/24 22:50:49 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	str_without_quotes_len(char *str, char *c, int j, int len)
{
	while (str[j])
	{
		if (*c != 0)
		{
			while (str[j] && str[j] != *c)
				ft_increase(&len, &j);
			if (str[j] == 0)
				return (len);
			j++;
			*c = 0;
		}
		while (str[j] && *c == 0)
		{
			while (str[j] && !ft_ischarinset(str[j], "'\""))
				ft_increase(&len, &j);
			if (!str[j])
				return (len);
			*c = str[j];
		}
		if (!str[j])
			return (len);
		j++;
	}
	return (len);
}

int	ft_len_delete_quote(t_arg *tab)
{
	int		len;
	int		i;
	char	c;

	len = 0;
	i = 0;
	c = 0;
	while ((tab[i]).str != NULL)
	{
		if ((tab[i]).quote == 1)
			len = len + ft_strlen((tab[i]).str);
		else
			len = len + str_without_quotes_len((tab[i]).str, &c, 0, 0);
		i++;
	}
	return (len);
}
