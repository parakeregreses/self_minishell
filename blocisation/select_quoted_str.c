/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_quoted_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 21:19:58 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/07/30 18:59:40 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	tab = fill_tab_blocs(tab, str, s, len);
	return (tab);
}

t_arg	*t1_separator(char *str)
{
	char	separator;
	t_arg	*t1;

	separator = which_separator(str, '\'', '\"');
	t1 = extract_quote(str, find_segment(str, separator));
	return (t1);
}

t_arg	*t1_no_separator(char *str)
{
	t_arg	*t1;

	t1 = malloc(sizeof(t_arg) * 2);
	if (!t1)
		return (NULL);
	(t1[0]).str = ft_strdup(str);
	(t1[0]).quote = 0;
	(t1[1]).str = NULL;
	(t1[1]).quote = 0;
	return (t1);
}

t_arg	*select_quoted_str(char *str)
{
	t_arg	*t1;
	t_arg	*t2;
	int		n;

	t1 = NULL;
	if (ft_charinstr(str, '\'') == TRUE || ft_charinstr(str, '\"') == TRUE)
		t1 = t1_separator(str);
	else
		t1 = t1_no_separator(str);
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
