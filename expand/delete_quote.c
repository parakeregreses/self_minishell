/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 22:40:43 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/24 22:49:56 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	fill_str_without_quotes_return(char **str, int i)
{
	str[0][i] = 0;
	return (i);
}

int	fill_str_without_quotes(char **str, int i, char *str2, char *c)
{
	int	j;

	j = 0;
	while (str2[j])
	{
		if (*c != 0)
		{
			while (str2[j] && str2[j] != *c)
				str[0][i++] = str2[j++];
			j++;
			*c = 0;
		}
		while (str2[j] && *c == 0)
		{
			while (str2[j] && !ft_ischarinset(str2[j], "'\""))
				str[0][i++] = str2[j++];
			if (!str2[j])
				return (fill_str_without_quotes_return(str, i));
			*c = str2[j];
		}
		if (!str2[j])
			return (fill_str_without_quotes_return(str, i));
		j++;
	}
	return (fill_str_without_quotes_return(str, i));
}

static char	*fill_str(t_arg *tab, char *str)
{
	int		i;
	int		j;
	int		k;
	char	*c;

	i = 0;
	j = 0;
	c = malloc(sizeof(char));
	*c = 0;
	while ((tab[i]).str != NULL)
	{
		if ((tab[i]).quote == 1)
		{
			k = 0;
			while ((tab[i]).str[k])
				str[j++] = (tab[i]).str[k++];
		}
		else
			j = fill_str_without_quotes(&str, j, (tab[i]).str, c);
		str[j] = 0;
		i++;
	}
	free(c);
	return (str);
}

char	*delete_quote(t_arg *tab)
{
	int		len;
	char	*str;

	len = ft_len_delete_quote(tab);
	str = malloc(sizeof(char) * (len + 1));
	str = fill_str(tab, str);
	free_tab_arg(tab);
	return (str);
}
