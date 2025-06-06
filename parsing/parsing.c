/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 10:16:59 by jlaineb           #+#    #+#             */
/*   Updated: 2025/06/06 14:29:58 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**parsing(char *str)
{
	char	**tab1;
	char	**tab2;
	int		n;
	char	separator;

	tab1 = NULL;
	if (ft_charinstr(str, '\'') == TRUE || ft_charinstr(str, '\"') == TRUE)
	{
		separator = which_separator(str);
		tab1 = extract_str_in_str(str, find_segment(str, '\''));
	}
	n = tab_size(tab1);
	while (ft_charinstr(tab1[n - 1], '\'') == TRUE)
	{
		tab2 = parsing(tab1[n - 1]);
		tab1 = append_tabs_and_free(delete_line_in_tab(tab1, n - 1), tab2);
		n = tab_size(tab1);
	}
	return (tab1);
}
