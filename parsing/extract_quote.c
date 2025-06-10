/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_quote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:20:30 by jlaineb           #+#    #+#             */
/*   Updated: 2025/06/10 17:15:43 by jlaine-b         ###   ########.fr       */
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

t_arg	*fill_tab_3(t_arg *tab, char *str, t_segment s, int len)
{
	int i;

	i = 0;
	while (i < s.start)
	{
		(tab[0]).str[i] = str[i];
		i++;
	}
	(tab[0]).str[i++] = 0;
	(tab[0]).quote = 0;
	while (i < s.end)
	{
		(tab[1]).str[i - s.start - 1] = str[i];
		i++;
	}
	(tab[1]).str[i++ - s.start - 1] = 0;
	(tab[1]).quote = 1;
	while (i < len)
	{
		(tab[2]).str[i - s.end - 1] = str[i];
		i++;
	}
	(tab[2]).str[i - s.end - 1] = 0;
	(tab[2]).quote = 0;
	return (tab);
}

t_arg	*fill_tab_1(t_arg *tab, char *str, t_segment s)
{
	int i;

	i = s.start;
	while (i < s.end)
	{
		(tab[0]).str[i] = str[i + 1];
		i++;
	}
	(tab[0]).str[i - 1] = 0;
	(tab[0]).quote = 1;
	return (tab);
}

t_arg	*fill_tab_2_end(t_arg *tab, char *str, t_segment s)
{
	int i;

	i = 0;
	while (i < s.start)
	{
		(tab[0]).str[i] = str[i];
		i++;
	}
	(tab[0]).str[i++] = 0;
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
	int i;

	i = s.start;
	while (i < s.end)
	{
		(tab[0]).str[i] = str[i + 1];
		i++;
	}
	(tab[0]).str[i++ - 1] = 0;
	(tab[0]).quote = 1;
	while (i < len)
	{
		(tab[1]).str[i - s.end - 1] = str[i];
		i++;
	}
	(tab[1]).str[i++ - s.end - 1] = 0;
	(tab[1]).quote = 0;
	return (tab);
}

//returns a tab with line 0 = before str, line 1 = str, line2 = after str
t_arg	*extract_quote(char *str, t_segment s)
{
	t_arg	*tab;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str);
	tab = alloc_tab(len, s);
	if (tab == NULL)
		return (NULL);
	tab = fill_tab(tab, str, s, len);
	// while (i < s.start)
	// {
	// 	(tab[0]).str[i] = str[i];
	// 	i++;
	// }
	// (tab[0]).str[i++] = 0;
	// (tab[0]).quote = 0;
	// ft_printf("firstline\n");
	// while (i < s.end)
	// {
	// 	(tab[1]).str[i - s.start - 1] = str[i];
	// 	i++;
	// }
	// (tab[1]).str[i - s.start - 1] = 0;
	// (tab[1]).quote = 1;
	// i++;
	// ft_printf("secondline\n");
	// while (i < len)
	// {
	// 	(tab[2]).str[i - s.end - 1] = str[i];
	// 	i++;
	// }
	// (tab[2]).str[i - s.end - 1] = 0;
	// (tab[2]).quote = 0;
	// ft_printf("quote extracted\n");
	return (tab);
}
