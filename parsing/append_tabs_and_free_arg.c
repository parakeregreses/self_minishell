/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_tabs_and_free_arg.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 18:56:42 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/07/06 19:11:01 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_arg	*fill_new_tab(t_arg *t1, t_arg *t2, t_arg *new_tab);

// create one tab, which is the concatenation of tab1 and tab2
// free tab1 and tab2
t_arg	*append_tabs_and_free_arg(t_arg *t1, t_arg *t2)
{
	t_arg	*new_tab;

	if (t1 == NULL)
		return (t2);
	if (t2 == NULL)
		return (t1);
	new_tab = ft_calloc(sizeof(t_arg), tab_size_arg(t1) + tab_size_arg(t2) + 1);
	if (!new_tab)
		return (NULL);
	new_tab = fill_new_tab(t1, t2, new_tab);
	free_tab_arg(t1);
	free_tab_arg(t2);
	return (new_tab);
}

t_arg	*fill_new_tab(t_arg *t1, t_arg *t2, t_arg *new_tab)
{
	int	i;
	int	len1;

	i = 0;
	while ((t1[i]).str != NULL)
	{
		(new_tab[i]).str = ft_strdup((t1[i]).str);
		(new_tab[i]).quote = (t1[i]).quote;
		i++;
	}
	len1 = i;
	while ((t2[i - len1]).str != NULL)
	{
		(new_tab[i]).str = ft_strdup((t2[i - len1]).str);
		(new_tab[i]).quote = (t2[i - len1]).quote;
		i++;
	}
	(new_tab[i]).str = NULL;
	(new_tab[i]).quote = 0;
	return (new_tab);
}
