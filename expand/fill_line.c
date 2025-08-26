/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 22:53:37 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/26 15:19:32 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_arg	fill_line1(t_arg tab, char *str, int j)
{
	int	k;

	k = 0;
	tab.quote = 1;
	tab.str[k++] = str[j++];
	if (str[j] && ft_isnum(str[j]))
	{
		while (str[j] && ft_isnum(str[j]))
			tab.str[k++] = str[j++];
		tab.str[k] = 0;
		return (tab);
	}
	else
	{
		while (str[j] && !ft_ischarinset(str[j], "\'\" $"))
			tab.str[k++] = str[j++];
		tab.str[k] = 0;
		return (tab);
	}
}

t_arg	fill_line21(t_arg tab, int k, char c)
{
	tab.str[k++] = c;
	tab.str[k] = 0;
	return (tab);
}

t_arg	fill_line22(t_arg tab, int k)
{
	tab.str[k] = 0;
	return (tab);
}

char	*close_quote_str(char *str1, int *i, int *j, char *str2)
{
	str1[*i] = str2[*j];
	*i = *i + 1;
	*j = *j + 1;
	while (str2[*j] && str2[*j] != '\'')
	{
		str1[*i] = str2[*j];
		*i = *i + 1;
		*j = *j + 1;
	}
	if (str2[*j])
	{
		str1[*i] = str2[*j];
		*i = *i + 1;
		*j = *j + 1;
	}
	return (str1);
}

t_arg	fill_line2_dollar(t_arg tab, char *str, int j)
{
	int	k;
	int	q;

	k = 0;
	q = 0;
	while (str[j])
	{
		if (str[j] == '\'' && q == 0)
			tab.str = close_quote_str(tab.str, &k, &j, str);
		if (str[j] && str[j] == '"')
			q = ft_bool(q);
		if (str[j] && str[j] == '$')
		{
			if (!str[j + 1])
				return (fill_line21(tab, k, str[j]));
			if (!(q == 1 && str[j + 1] && ft_ischarinset(str[j + 1], "\" $")))
				return (fill_line22(tab, k));
			else
				tab.str[k++] = str[j++];
		}
		if (str[j])
			tab.str[k++] = str[j++];
	}
	tab.str[k] = 0;
	return (tab);
}
