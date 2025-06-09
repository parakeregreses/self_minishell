/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_tabs_and_free_arg.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 09:58:33 by jlaineb           #+#    #+#             */
/*   Updated: 2025/06/09 17:24:37 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// create one tab, which is the concatenation of tab1 and tab2
// free tab1 and tab2
t_arg	*append_tabs_and_free_arg(t_arg *tab1, t_arg *tab2)
{
	t_arg	*new_tab;
	int		i;
	int		len1;

	i = 0;
	new_tab = malloc(sizeof(t_arg) * (tab_size_arg(tab1) + tab_size_arg(tab2) + 1));
	if (!new_tab)
		return (NULL);
	while ((tab1[i]).str != NULL)
	{
		(new_tab[i]).str = ft_strdup((tab1[i]).str);
		(new_tab[i]).quote = (tab1[i]).quote;
		i++;
	}
	len1 = i;
	while ((tab2[i - len1]).str != NULL)
	{
		(new_tab[i]).str = ft_strdup((tab2[i - len1]).str);
		(new_tab[i]).quote = (tab2[i - len1]).quote;
		i++;
	}
	(new_tab[i]).str = NULL;
	free_tab_arg(tab1);
	free_tab_arg(tab2);
	return (new_tab);
}
