/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:15:19 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/06/12 14:22:29 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_arg	*alloc_tab_2_begin(int len, t_segment s);
t_arg	*alloc_tab_2_end(t_segment s);
t_arg	*alloc_tab_3(int len, t_segment s);
t_arg	*alloc_tab_1(t_segment s);

// allow us to choose the correct configuration for the quoted string
t_arg	*alloc_tab(int len, t_segment s)
{
	t_arg	*tab;

	if (s.start != 0 && s.end != (len - 1))
		tab = alloc_tab_3(len, s);
	if (s.start == 0 && s.end != (len - 1))
		tab = alloc_tab_2_begin(len, s);
	if (s.start != 0 && s.end == (len - 1))
		tab = alloc_tab_2_end(s);
	if (s.start == 0 && s.end == (len - 1))
		tab = alloc_tab_1(s);
	return (tab);
}

// the full string is quoted
t_arg	*alloc_tab_1(t_segment s)
{
	t_arg	*tab;

	tab = malloc(sizeof(t_arg) * 2);
	if (tab == NULL)
		return (NULL);
	(tab[0]).str = malloc(sizeof(char) * (s.end - s.start));
	if ((tab[0]).str == NULL)
		return (free_tab_arg(tab));
	(tab[0]).quote = 1;
	(tab[1]).str = NULL;
	return (tab);
}

// string is quoted from the beginning but not till the end
t_arg	*alloc_tab_2_begin(int len, t_segment s)
{
	t_arg	*tab;

	tab = malloc(sizeof(t_arg) * 3);
	if (tab == NULL)
		return (NULL);
	(tab[0]).str = malloc(sizeof(char) * (s.end - s.start + 1));
	if ((tab[0]).str == NULL)
		return (free_tab_arg(tab));
	(tab[0]).quote = 1;
	(tab[1]).str = malloc(sizeof(char) * (len - s.end + 1));
	if ((tab[1]).str == NULL)
		return (free_tab_arg(tab));
	(tab[1]).quote = 0;
	(tab[2]).str = NULL;
	return (tab);
}

// string is not quoted from the beginning but the quote reaches the end
t_arg	*alloc_tab_2_end(t_segment s)
{
	t_arg	*tab;

	tab = malloc(sizeof(t_arg) * 3);
	if (tab == NULL)
		return (NULL);
	(tab[0]).str = malloc(sizeof(char) * (s.start + 1));
	if ((tab[0]).str == NULL)
		return (free_tab_arg(tab));
	(tab[0]).quote = 0;
	(tab[1]).str = malloc(sizeof(char) * (s.end - s.start + 1));
	if ((tab[1]).str == NULL)
		return (free_tab_arg(tab));
	(tab[1]).quote = 1;
	(tab[2]).str = NULL;
	return (tab);
}

// string is quoted but has unquote parts at beginning and end
t_arg	*alloc_tab_3(int len, t_segment s)
{
	t_arg	*tab;

	tab = malloc(sizeof(t_arg) * 4);
	if (tab == NULL)
		return (NULL);
	(tab[0]).str = malloc(sizeof(char) * (s.start + 1));
	if ((tab[0]).str == NULL)
		return (free_tab_arg(tab));
	(tab[0]).quote = 0;
	(tab[1]).str = malloc(sizeof(char) * (s.end - s.start + 1));
	if ((tab[1]).str == NULL)
		return (free_tab_arg(tab));
	(tab[0]).quote = 1;
	(tab[2]).str = malloc(sizeof(char) * (len - s.end + 1));
	if ((tab[2]).str == NULL)
		return (free_tab_arg(tab));
	(tab[2]).quote = 0;
	(tab[3]).str = NULL;
	return (tab);
}
