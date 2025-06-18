/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_x_in_str_exquote.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:42:16 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/06/17 14:42:26 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_x_char_in_str(char *str, char c, int x)
{
	int	i;
	int	j;

	if (ft_strlen(str) < (size_t) x)
		return (FALSE);
	i = x - 1;
	while (str[i] != 0)
	{
		j = 0;
		while (j != x)
		{
			if (str[i - j] != c)
			{
				i++;
				j = x;
			}
			else
			{
				j++;
				if (j == x)
					return (TRUE);
			}
		}
	}
	return (FALSE);
}