/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaineb <jlaineb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 10:16:59 by jlaineb           #+#    #+#             */
/*   Updated: 2025/05/23 10:25:14 by jlaineb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**parsing(char *str)
{
	char	**tab1;
	char	**tab2;
	char	**tab;
	
	if (ft_charinstr(str, '\'') == TRUE)
		tab1 = extract_str_in_str(str, find_segment(str, '\''));
	tab2 = ft_split(tab1[0], '|');
	tab = append_tabs_and_free(tab2, delete_line_in_tab(tab1, 0));
	return (tab);
}