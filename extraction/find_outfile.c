/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_outfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 22:14:44 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/20 11:18:24 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_outfile	find_outfile(char **tokens, int *status, char ***envp)
{
	t_outfile	outfile;
	int			i;

	outfile.filename = NULL;
	outfile.append = 0;
	i = 0;
	while (tokens[i] != NULL)
	{
		if (tokens[i][0] && tokens[i][0] == '>')
		{
			if (tokens[i][1] && tokens[i][1] == '>')
			{
				outfile.filename = expand_and_unquote(tokens[i] + 2, *status, *envp);
				outfile.append = 1;
			}
			else
				outfile.filename = expand_and_unquote(tokens[i] + 1, *status, *envp);
		}
		i++;
	}
	return (outfile);
}
