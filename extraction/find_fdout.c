/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_fdout.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:07:55 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/07/31 17:36:28 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_fdout(char **tokens)
{
	int		fdout;
	int		i;
	char	*filename;

	fdout = 1;
	i = 0;
	while (tokens[i] != NULL)
	{
		if (tokens[i][0] && tokens[i][0] == '>')
		{
			filename = str_without_quotes(tokens[i] + 1);
			fdout = open(filename, O_WRONLY | O_TRUNC | O_CREAT, 0666);
			close(fdout);
			free(filename);
		}
		i++;
	}
	return (fdout);
}
