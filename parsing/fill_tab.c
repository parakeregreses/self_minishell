/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:16:47 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/06/16 12:22:28 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_arg	*fill_tab_3(t_arg *tab, char *str, t_segment s, int len);
t_arg	*fill_tab_1(t_arg *tab, char *str, t_segment s);
t_arg	*fill_tab_2_end(t_arg *tab, char *str, t_segment s);
t_arg	*fill_tab_2_begin(t_arg *tab, char *str, t_segment s, int len);

t_arg	*fill_tab(t_arg *tab, char *str, t_segment s, int len)
{
	int	n;

	n = tab_size_arg(tab);
	if (n == 3)
		return (fill_tab_3(tab, str, s, len));
	if (n == 1)
		return (fill_tab_1(tab, str, s));
	if (n == 2)
	{
		if ((tab[0]).quote == 0)
			return (fill_tab_2_end(tab, str, s));
		if ((tab[0]).quote == 1)
			return (fill_tab_2_begin(tab, str, s, len));
	}
	return (NULL);
}

t_arg	*fill_tab_1(t_arg *tab, char *str, t_segment s)
{
	int	i;

	i = 0;
	while (i <= s.end)
	{
		(tab[0]).str[i] = str[i];
		i++;
	}
	(tab[0]).str[i - 1] = 0;
	(tab[0]).quote = 1;
	return (tab);
}

t_arg	*fill_tab_2_end(t_arg *tab, char *str, t_segment s)
{
	int	i;

	i = 0;
	while (i <= s.start)
	{
		(tab[0]).str[i] = str[i];
		i++;
	}
	(tab[0]).str[i] = 0;
	(tab[0]).quote = 0;
	while (i < s.end)
	{
		(tab[1]).str[i - s.start - 1] = str[i];
		i++;
	}
	(tab[1]).str[i++ - s.start - 1] = 0;
	(tab[1]).quote = 1;
	return (tab);
}

t_arg	*fill_tab_2_begin(t_arg *tab, char *str, t_segment s, int len)
{
	int	i;

	i = s.start + 1;
	while (i < s.end)
	{
		(tab[0]).str[i] = str[i];
		i++;
	}
	(tab[0]).str[i] = 0;
	(tab[0]).quote = 1;
	while (i < len)
	{
		(tab[1]).str[i - s.end] = str[i];
		i++;
	}
	(tab[1]).str[i++ - s.end] = 0;
	(tab[1]).quote = 0;
	return (tab);
}

t_arg	*fill_tab_3(t_arg *tab, char *str, t_segment s, int len)
{
	int	i;

	i = 0;
	while (i < s.start + 1)
	{
		(tab[0]).str[i] = str[i];
		i++;
	}
	(tab[0]).str[i] = 0;
	(tab[0]).quote = 0;
	while (i < s.end)
	{
		(tab[1]).str[i - s.start - 1] = str[i];
		i++;
	}
	(tab[1]).str[i - s.start - 1] = 0;
	(tab[1]).quote = 1;
	while (i < len)
	{
		(tab[2]).str[i - s.end] = str[i];
		i++;
	}
	(tab[2]).str[i - s.end] = 0;
	(tab[2]).quote = 0;
	return (tab);
}
