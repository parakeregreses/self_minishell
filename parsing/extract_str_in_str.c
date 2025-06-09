/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_str_in_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:20:30 by jlaineb           #+#    #+#             */
/*   Updated: 2025/06/09 11:43:46 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_arg	*alloc_tab_extract(int len, t_segment s)
{
	// si len = s.end ? faire condition spéciale ?
	t_arg	*tab;

	tab = malloc(sizeof(t_arg) * 4);
	if (tab == NULL)
		return (NULL);
	(tab[0]).str = malloc(sizeof(char) * (s.start + 1));
	(tab[0]).quote = malloc(sizeof(int));
	if ((tab[0]).str == NULL || (tab[0]).quote == NULL)
		return (NULL);
	(tab[1]).str = malloc(sizeof(char) * (s.end - s.start + 1));
	(tab[1]).quote = malloc(sizeof(int));
	if ((tab[1]).str == NULL || (tab[1]).quote == NULL)
	{
		free_tab_arg(tab);
		return (NULL);
	}
	(tab[2]).str = malloc(sizeof(char) * (len - s.end + 1));
	(tab[2]).quote = malloc(sizeof(int));
	if ((tab[2]).str == NULL || (tab[1]).quote == NULL)
	{
		free_tab_arg(tab);
		return (NULL);
	}
	(tab[3]).str = NULL;
	return (tab);
}

//returns a tab of size 3, before str, str, after str
char	**extract_str_in_str(char *str, t_segment s)
{
	t_arg	*tab;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str);
	tab = alloc_tab_extract(len, s);
	while (i < s.start)
	{
		(tab[0]).str[i] = str[i];
		i++;
	}
	(tab[0]).str[i++] = 0;
	(tab[0]).quote = 0;
	while (i < s.end)
	{
		(tab[1]).str[i - s.start - 1] = str[i];
		i++;
	}
	(tab[1]).str[i - s.start - 1] = 0;
	(tab[1]).quote = 1;
	i++;
	while (i < len)
	{
		(tab[2]).str[i - s.end - 1] = str[i];
		i++;
	}
	(tab[2]).str[i - s.end - 1] = 0;
	(tab[2]).quote = 0;
	return (tab);
}
