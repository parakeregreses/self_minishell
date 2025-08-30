/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 23:02:38 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/30 18:42:03 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	size_line3(char *str, int i)
{
	if (!str[i + 1])
		return (i + 1);
	return (i);
}

int	size_line2(char *str, int q, int i)
{
	while (str[i])
	{
		if (str[i] && str[i] == '\'' && q == 0)
			i = close_quote(str, i, str[i]);
		if (str[i] == 0)
			return (i);
		if (str[i] && str[i] == '"')
			q = ft_bool(q);
		if (str[i] && str[i] == '$')
		{
			if (!str[i + 1] || !(q == 1 && str[i + 1]
					&& ft_ischarinset(str[i + 1], "\" $")))
				return (size_line3(str, i));
			i++;
		}
		if (!str[i])
			return (i);
		i++;
	}
	return (i);
}

int	size_line(char *str)
{
	int	i;
	int	q;

	i = 0;
	q = 0;
	if (str[0] == '$')
		return (close_dollar(str, 1));
	else
		return (size_line2(str, q, i));
}
