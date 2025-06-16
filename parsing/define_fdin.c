/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_fdin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:50:26 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/06/16 17:34:06 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	define_fdin(char *str)
{
	int	i;
	char *filename;

	filename = NULL;
	i = 0;
	while (str[i] != 0)
	{
		if (str[i++] == '<')
		{
			if (str[i] == '<')
				return (0);
			filename = ft_firstword(str + i, ' ');
		}
	}
	ft_printf("filename = %s\n", filename);
	if (is_infile(filename) == FALSE)
		return(-1);
	i = open(filename, O_RDONLY);
	return (i);
}