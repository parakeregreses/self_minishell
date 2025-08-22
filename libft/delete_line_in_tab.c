/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_line_in_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:14:22 by jlaineb           #+#    #+#             */
/*   Updated: 2025/08/22 20:58:17 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**delete_line_in_tab(char **old_tab, int i)
{
	int		len;
	int		j;
	char	**new_tab;

	j = 0;
	len = tab_size(old_tab);
	ft_printf("len = %d\n", len);
	new_tab = malloc(sizeof(char *) * len);
	if (new_tab == NULL)
		return (NULL);
	while (old_tab[j] != NULL && j != i)
	{
		new_tab[j] = ft_strdup(old_tab[j]);
		j++;
	}
	i++;
	while (old_tab[i] != NULL)
		new_tab[j++] = ft_strdup(old_tab[i++]);
	new_tab[j] = NULL;
	free_tab((void **)old_tab);
	return (new_tab);
}
