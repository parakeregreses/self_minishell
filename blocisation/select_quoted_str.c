/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_quoted_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 21:19:58 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/15 20:31:34 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//returns a tab with line 0 = before str, line 1 = str, line2 = after str
t_arg	*extract_quote(char *str, t_segment s)
{
	t_arg	*tab;
	int		len;

	len = ft_strlen(str);
	tab = alloc_tab(len, s);
	if (tab == NULL)
		return (NULL);
	tab = fill_tab_blocs(tab, str, s, len);
	return (tab);
}

t_arg	*tab1_separator(char *str)
{
	char	separator;
	t_arg	*tab1;

	separator = which_separator(str, '\'', '\"');
	tab1 = extract_quote(str, find_segment(str, separator));
	return (tab1);
}

t_arg	*tab1_no_separator(char *str)
{
	t_arg	*tab1;

	tab1 = malloc(sizeof(t_arg) * 2);
	if (!tab1)
		return (NULL);
	(tab1[0]).str = ft_strdup(str);
	(tab1[0]).quote = 0;
	(tab1[1]).str = NULL;
	(tab1[1]).quote = 0;
	return (tab1);
}

// Splits a string into segments based on quotes ' or ". 
// Each segment is labeled 0 (unquoted segment) or 1 (quoted segment)
// basically, the string "word "quoted" word 'quoted''quoted'" will turn into :
// 0 word
// 1 "quoted"
// 0 word
// 1 'quoted'
// 1 'quoted' 
t_arg	*select_quoted_str(char *str)
{
	t_arg	*t1;
	t_arg	*t2;
	int		n;

	t1 = NULL;
	if (ft_charinstr(str, '\'') == TRUE || ft_charinstr(str, '\"') == TRUE)
		t1 = tab1_separator(str);
	else
		t1 = tab1_no_separator(str);
	if (t1 == NULL)
		return (NULL);
	n = tab_size_arg(t1);
	while ((t1[n - 1]).quote == 0
		&& (ft_charinstr((t1[n - 1]).str, '\'') == TRUE
			|| ft_charinstr((t1[n - 1]).str, '\"') == TRUE))
	{
		t2 = select_quoted_str((t1[n - 1]).str);
		t1 = append_tabs_and_free_arg(delete_line_in_tab_arg(t1, n - 1), t2);
		n = tab_size_arg(t1);
	}
	return (t1);
}
