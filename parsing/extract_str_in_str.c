/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_str_in_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaineb <jlaineb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:20:30 by jlaineb           #+#    #+#             */
/*   Updated: 2025/05/23 10:15:14 by jlaineb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**alloc_tab_extract(int len, t_segment s)
{
	// si len = s.end ? faire condition spéciale ?
	char	**tab;

	tab = malloc(sizeof(char *) * 4);
	if (tab == NULL)
		return (NULL);
	tab[0] = malloc(sizeof(char) * (s.start + 1));
	if (tab[0] == NULL)
		return (NULL);
	tab[1] = malloc(sizeof(char) * (s.end - s.start + 1));
	if (tab[1] == NULL)
	{
		free_tab((void *)tab);
		return (NULL);
	}
	tab[2] = malloc(sizeof(char) * (len - s.end + 1));
	if (tab[2] == NULL)
	{
		free_tab((void *)tab);
		return (NULL);
	}
	tab[3] = NULL;
	return (tab);
}

//returns a tab of size 3, before str, str, after str
char	**extract_str_in_str(char *str, t_segment s)
{
	char	**tab;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str);
	tab = alloc_tab_extract(len, s);
	while (i < s.start)
	{
		tab[0][i] = str[i];
		i++;
	}
	tab[0][i++] = 0;
	while (i < s.end)
	{
		tab[1][i - s.start - 1] = str[i];
		i++;
	}
	tab[1][i - s.start - 1] = 0;
	i++;
	while (i < len)
	{
		tab[2][i - s.end - 1] = str[i];
		i++;
	}
	tab[2][i - s.end - 1] = 0;
	return (tab);
}
