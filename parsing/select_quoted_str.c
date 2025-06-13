/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_quoted_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 21:19:58 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/06/13 21:32:36 by jlaine-b         ###   ########.fr       */
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
	tab = fill_tab(tab, str, s, len);
	return (tab);
}

t_arg	*select_quoted_str(char *str)
{
	t_arg	*tab1;
	t_arg	*tab2;
	int		n;
	char	separator;

	tab1 = NULL;
	if (ft_charinstr(str, '\'') == TRUE || ft_charinstr(str, '\"') == TRUE)
	{
		separator = which_separator(str, '\'', '\"');
		tab1 = extract_quote(str, find_segment(str, separator));
		if (tab1 == NULL)
			return (NULL);
	}
	else
	{
		tab1 = malloc(sizeof(t_arg) * 2);
		if (!tab1)
			return (NULL);
		(tab1[0]).str = ft_strdup(str);
		(tab1[0]).quote = 0;
		(tab1[1]).str = NULL;
		return (tab1);
	}
	n = tab_size_arg(tab1);
	while ((tab1[n - 1]).quote == 0 && (ft_charinstr((tab1[n - 1]).str, '\'') == TRUE || ft_charinstr((tab1[n - 1]).str, '\"') == TRUE))
	{
		tab2 = select_quoted_str((tab1[n - 1]).str);
		tab1 = append_tabs_and_free_arg(delete_line_in_tab_arg(tab1, n - 1), tab2);
		n = tab_size_arg(tab1);
	}
	return (tab1);
}