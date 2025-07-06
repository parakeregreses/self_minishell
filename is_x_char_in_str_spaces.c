/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_x_char_in_str_spaces.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 17:59:54 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/07/06 18:30:37 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

int	ft_is_x_char(char *str, char c, int i, int x)
{
	int	j;

	j = 1;
	while (j != x)
	{
		while (ft_iswhitespace(str[i]) == TRUE)
			i++;
		if (str[i] != c)
			return (FALSE);
		else
		{
			j++;
			i++;
		}
	}
	return (TRUE);
}

int	is_x_char_in_str_spaces(char *str, char c, int x)
{
	int	i;

	if (str == NULL || ft_strlen(str) < (size_t) x)
		return (FALSE);
	i = x - 1;
	while (str[i] != 0)
	{
		if (str[i] == c)
		{
			if (ft_is_x_char(str, c, i, x) == TRUE)
				return (TRUE);
		}
		i++;
	}
	return (FALSE);
}
