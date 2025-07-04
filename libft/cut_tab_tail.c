/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_tab_tail.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 22:26:55 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/06/09 22:26:56 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// cut tab tail, line n included. Returns tab head
char	**cut_tab_tail(char **tab, int n)
{
	int		i;
	int		size;
	char	**new_tab;

	size = tab_size(tab);
	if (n > size)
		return (NULL);
	i = 0;
	new_tab = malloc(sizeof(char *) * n);
	while (i < (n - 1))
	{
		new_tab[i] = ft_strdup(tab[i]);
		i++;
	}
	new_tab[i] = NULL;
	return (new_tab);
}
