/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_line_in_tab_arg.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:14:22 by jlaineb           #+#    #+#             */
/*   Updated: 2025/06/09 16:39:30 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_arg	*delete_line_in_tab_arg(t_arg *old_tab, int i)
{
	int		len;
	int		j;
	t_arg	*new_tab;

	j = 0;
	len = tab_size_arg(old_tab);
	new_tab = malloc(sizeof(t_arg) * len);
	if (new_tab == NULL)
		return (NULL);
	while ((old_tab[j]).str != NULL && j != i)
	{
		(new_tab[j]).str = ft_strdup((old_tab[j]).str);
		j++;
	}
	i++;
	while ((old_tab[i]).str != NULL)
		(new_tab[j++]).str = ft_strdup((old_tab[i++]).str);
	(new_tab[j]).str = NULL;
	free_tab_arg(old_tab);
	return (new_tab);
}
