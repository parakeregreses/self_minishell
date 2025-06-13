/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_tabs_and_free.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 09:58:33 by jlaineb           #+#    #+#             */
/*   Updated: 2025/06/09 22:25:10 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// create one tab, which is the concatenation of tab1 and tab2
// free tab1 and tab2
char	**append_tabs_and_free(char **tab1, char **tab2)
{
	char	**new_tab;
	int		i;
	int		len1;

	i = 0;
	new_tab = malloc(sizeof(char *) * (tab_size(tab1) + tab_size(tab2) + 1));
	if (!new_tab)
		return (NULL);
	while (tab1[i] != NULL)
	{
		new_tab[i] = ft_strdup(tab1[i]);
		i++;
	}
	len1 = i;
	while (tab2[i - len1] != NULL)
	{
		new_tab[i] = ft_strdup(tab2[i - len1]);
		i++;
	}
	new_tab[i] = NULL;
	free_tab((void *)tab1);
	free_tab((void *)tab2);
	return (new_tab);
}
