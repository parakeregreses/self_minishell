/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_quote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:20:30 by jlaineb           #+#    #+#             */
/*   Updated: 2025/06/10 11:34:38 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_arg	*alloc_tab_2_begin(int len, t_segment s);
t_arg	*alloc_tab_2_end(int len, t_segment s);
t_arg	*alloc_tab_3(int len, t_segment s);

static t_arg	*alloc_tab(int len, t_segment s)
{
	t_arg	*tab;
	
	if (s.start != 0 && s.end != len)
		tab = alloc_tab_3(len, s);
	if (s.start == 0 && s.end != len)
		tab = alloc_tab_2_begin(len, s);
	if (s.start != 0 && s.end == len)
		tab = alloc_tab_2_end(len, s);
	// if (s.start == 0 && s.end == len)
	// 	tab = alloc_tab_1(len, s);
	else
		tab = NULL; //temporaire
	return (tab);
}

t_arg	*alloc_tab_2_begin(int len, t_segment s)
{
	t_arg	*tab;

	tab = malloc(sizeof(t_arg) * 3);
	if (tab == NULL)
		return (NULL);
	(tab[0]).str = malloc(sizeof(char) * (s.end - s.start + 1));
	if ((tab[0]).str == NULL)
	{
		free_tab_arg(tab);
		return (NULL);
	}
	(tab[1]).str = malloc(sizeof(char) * (len - s.end + 1));
	if ((tab[1]).str == NULL)
	{
		free_tab_arg(tab);
		return (NULL);
	}
	(tab[2]).str = NULL;
	return (tab);
}

t_arg	*alloc_tab_2_end(int len, t_segment s)
{
	// si len = s.end ? faire condition spéciale ?
	t_arg	*tab;

	tab = malloc(sizeof(t_arg) * 3);
	if (tab == NULL)
		return (NULL);
	(tab[0]).str = malloc(sizeof(char) * (s.start + 1));
	if ((tab[0]).str == NULL)
		return (NULL);
	(tab[1]).str = malloc(sizeof(char) * (s.end - s.start + 1));
	if ((tab[1]).str == NULL)
	{
		free_tab_arg(tab);
		return (NULL);
	}
	(tab[2]).str = malloc(sizeof(char) * (len - s.end + 1));
	if ((tab[2]).str == NULL)
	{
		free_tab_arg(tab);
		return (NULL);
	}
	(tab[2]).str = NULL;
	return (tab);
}

t_arg	*alloc_tab_3(int len, t_segment s)
{
	// si len = s.end ? faire condition spéciale ?
	t_arg	*tab;

	tab = malloc(sizeof(t_arg) * 4);
	if (tab == NULL)
		return (NULL);
	(tab[0]).str = malloc(sizeof(char) * (s.start + 1));
	if ((tab[0]).str == NULL)
		return (NULL);
	(tab[1]).str = malloc(sizeof(char) * (s.end - s.start + 1));
	if ((tab[1]).str == NULL)
	{
		free_tab_arg(tab);
		return (NULL);
	}
	(tab[2]).str = malloc(sizeof(char) * (len - s.end + 1));
	if ((tab[2]).str == NULL)
	{
		free_tab_arg(tab);
		return (NULL);
	}
	(tab[3]).str = NULL;
	return (tab);
}

//returns a tab of size 3, before str, str, after str
t_arg	*extract_quote(char *str, t_segment s)
{
	t_arg	*tab;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str);
	tab = alloc_tab(len, s);
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
	(tab[1]).str[i - s.start - 1] = 0;
	(tab[1]).quote = 1;
	i++;
	while (i < len)
	{
		(tab[2]).str[i - s.end - 1] = str[i];
		i++;
	}
	(tab[2]).str[i - s.end - 1] = 0;
	(tab[2]).quote = 0;
	return (tab);
}
