/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_whitespaces.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 16:43:54 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/13 18:43:07 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (ft_iswhitespace(str[i]))
		{
			i++;
			while (str[i] && ft_iswhitespace(str[i]))
			{
				i++;
				n++;
			}
		}
		if (str[i])
			i++;
	}
	return (n);
}

// Turns any group of whitespace into one SPACE.
char	*remove_whitespaces(char *str)
{
	int		i;
	int		y;
	int		whitespaces;
	char	*result;

	i = 0;
	y = 0;
	whitespaces = count(str);
	result = malloc(sizeof(char) * (ft_strlen(str) - whitespaces + 1));
	if (!result)
		return (NULL);
	while (str[i])
	{
		if (ft_iswhitespace(str[i]))
		{
			result[y] = ' ';
			y++;
			while (str[i] && ft_iswhitespace(str[i]))
				i++;
		}
		if (str[i])
			result[y++] = str[i++];
	}
	result[y] = 0;
	free(str);
	return (result);
}
