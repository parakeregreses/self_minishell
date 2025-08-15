/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_outfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:07:55 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/15 21:59:08 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_outfile	find_outfile(char **tokens)
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
				outfile.filename = tokens[i] + 2;
				outfile.append = 1;
			}
			else
				outfile.filename = tokens[i] + 1;;
		}
		i++;
	}
	return (outfile);
}
