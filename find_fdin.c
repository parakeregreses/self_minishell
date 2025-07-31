/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_fdin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 15:38:31 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/07/31 17:18:11 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_fdin(char **tokens)
{
	int		fdin;
	int		i;
	char	*lim;
	char	*filename;
	
	fdin = 0;
	i = 0;
	while (tokens[i] != NULL)
	{
		if (tokens[i][0] && tokens[i][0] == '<')
		{
			if (tokens[i][1] && tokens[i][1] == '<')
			{
				fdin = 0;
				lim = str_without_quotes(tokens[i] + 2);
				here_doc(lim);
				free(lim);
			}
			else
			{
				filename = str_without_quotes(tokens[i] + 1);
				if (is_infile(filename) == FALSE)
				{
					free(filename);
					return (-1);
				}
				fdin = open(filename, O_RDONLY);
				if (fdin == -1)
					
				close(fdin);
				free(filename);
			}
		}
		i++;
	}
	// ft_printf("fdin = %d\n", fdin);
	return(fdin);
}