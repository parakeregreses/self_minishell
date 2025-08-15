/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_closed_quotes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaineb <jlaineb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:05:10 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/15 12:56:57 by jlaineb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// returns FALSE if there is an unclosed quote (' or "),
// returns TRUE if the quotes are closed correctly
int	check_closed_quotes(char *arg)
{
	int		i;
	// int		found;
	char	quote;

	i = 0;
	// found = 0;
	while (arg[i])
	{
		if (arg[i] == '"' || arg[i] == '\'')
		{
			// found = 1;
			quote = arg[i];
			i++;
			while (arg[i] != quote && arg[i])
				i++;
			if (arg[i] != quote)
				return (FALSE);
			// found = 0;
		}
		i++;
	}
	return (TRUE);
}
