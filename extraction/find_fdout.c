/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_fdout.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:07:55 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/09 16:01:30 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	redirect(char *filename)
{
	int		fdout;

	fdout = open(filename, O_WRONLY | O_TRUNC | O_CREAT, 0666);
	close(fdout);
	return (fdout);
}

int	redirect_append_mode(char *filename)
{
	int		fdout;

	fdout = open(filename, O_WRONLY | O_APPEND | O_CREAT, 0666);
	close(fdout);
	return (fdout);
}

int	find_fdout(char **tokens)
{
	int		fdout;
	int		i;

	fdout = 1;
	i = 0;
	while (tokens[i] != NULL)
	{
		if (tokens[i][0] && tokens[i][0] == '>')
		{
			if (tokens[i][1] && tokens[i][1] == '>')
				fdout = redirect_append_mode(tokens[i] + 1);
			else
				fdout = redirect(tokens[i] + 1);
		}
		i++;
	}
	return (fdout);
}
