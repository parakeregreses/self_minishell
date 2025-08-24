/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_closed_quotes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:05:10 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/23 17:31:42 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_closed_quotes(char *arg)
{
	int		i;
	char	quote;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == '"' || arg[i] == '\'')
		{
			quote = arg[i];
			i++;
			while (arg[i] != quote && arg[i])
				i++;
			if (arg[i] != quote)
				return (FALSE);
		}
		i++;
	}
	return (TRUE);
}
