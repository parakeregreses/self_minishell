/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triple_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:17:53 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/09/05 19:33:27 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	triple_char(t_arg *tab, int n, char c)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if ((tab[i]).quote == 0 && is_x_char_in_str((tab[i]).str, c, 3) == 1)
			return (1);
		i++;
	}
	return (0);
}

int	double_char(t_arg *tab, int n, char c)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if ((tab[i]).quote == 0 && is_x_char_in_str((tab[i]).str, c, 2) == 1)
			return (1);
		i++;
	}
	return (0);
}
