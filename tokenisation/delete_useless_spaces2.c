/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_useless_spaces2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:24:16 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/07/29 16:25:48 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fill_till_char(char **new_str, char *str, int *i, int *j)
{
	char	c;

	c = str[*i];
	new_str[0][*j] = str[*i];
	*j = *j + 1;
	*i = *i + 1;
	while (str[*i] && str[*i] != c)
	{
		new_str[0][*j] = str[*i];
		*j = *j + 1;
		*i = *i + 1;
	}
}

char	*delete_useless_spaces_fill(char *str, char *new_str, char *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != 0)
	{
		while (str[i] && ft_iswhitespace(str[i]) == FALSE)
		{
			if (str[i] == '\'' || str[i] == '"')
				fill_till_char(&new_str, str, &i, &j);
			new_str[j++] = str[i++];
		}
		if (str[i] == 0)
		{
			new_str[j] = 0;
			return (new_str);
		}
		while (ft_iswhitespace(str[i]) == TRUE
			&& ((str[i + 1] != 0 && ft_ischarinset(str[i + 1], set) == TRUE)
				|| ft_ischarinset(str[i - 1], set) == TRUE))
			i++;
		if (str[i] && ft_iswhitespace(str[i]) == 1
			&& str[i + 1] && ft_ischarinset(str[i + 1], set) == 0)
			new_str[j++] = str[i++];
	}
	new_str[j] = 0;
	return (new_str);
}
