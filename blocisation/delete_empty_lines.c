/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_empty_lines.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 17:18:10 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/22 21:02:42 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_only_whitespaces(char *str)
{
	int	i;

	if (str == NULL)
		return (TRUE);
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_iswhitespace(str[i]) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

char	**delete_empty_lines(char **tab)
{
	int	i;

	if (tab == NULL)
		return (NULL);
	i = 0;
	while (tab[i] != NULL)
	{
		if (is_only_whitespaces(tab[i]) == TRUE)
			tab = delete_line_in_tab(tab, i);
		else
			i++;
	}
	return (tab);
}
