/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_x_char_in_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:04:30 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/06/10 12:20:33 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
