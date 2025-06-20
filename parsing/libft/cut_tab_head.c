/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_tab_head.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 22:26:45 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/06/09 22:26:48 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// cut tab head, line n included. Returns tab tail
char	**cut_tab_head(char **tab, int n)
{
	int		i;
	int		size;
	char	**new_tab;

	size = tab_size(tab);
	if (n >= size)
		return (NULL);
	i = n + 1;
	new_tab = malloc(sizeof(char *) * (size - i + 1));
	while (i < size)
	{
		new_tab[i - n - 1] = ft_strdup(tab[i]);
		i++;
	}
	new_tab[i - n - 1] = NULL;
	return (new_tab);
}
