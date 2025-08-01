/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blocisation_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 21:23:55 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/07/30 18:58:56 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	which_separator(char *s, char c1, char c2)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c1)
			return (c1);
		if (s[i] == c2)
			return (c2);
		i++;
	}
	return (0);
}

int	tab_size_arg(t_arg *tab)
{
	int	len;

	len = 0;
	if (tab == NULL)
		return (len);
	while ((tab[len]).str != NULL)
		len++;
	return (len);
}

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
		(new_tab[j]).quote = (old_tab[j]).quote;
		j++;
	}
	i++;
	while ((old_tab[i]).str != NULL)
	{
		(new_tab[j]).str = ft_strdup((old_tab[i]).str);
		(new_tab[j++]).quote = (old_tab[i++]).quote;
	}
	(new_tab[j]).str = NULL;
	(new_tab[j]).quote = 0;
	free_tab_arg(old_tab);
	return (new_tab);
}

t_arg	*free_tab_arg(t_arg *tab)
{
	int	i;

	if (tab == NULL)
		return (NULL);
	i = 0;
	while ((tab[i]).str != NULL)
		free((tab[i++]).str);
	free(tab);
	return (NULL);
}
