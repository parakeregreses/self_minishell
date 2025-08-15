/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_closed_quotes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:05:10 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/15 20:33:48 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// returns FALSE if there is an unclosed quote (' or "),
// returns TRUE if the quotes are closed correctly
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
