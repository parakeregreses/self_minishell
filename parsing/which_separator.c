/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_separartor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:13:54 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/06/08 11:19:47 by jlaine-b         ###   ########.fr       */
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
