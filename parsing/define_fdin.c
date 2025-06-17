/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_fdin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:50:26 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/06/17 12:06:24 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	define_fdin(char *str)
{
	int		i;
	char	*filename;

	filename = ft_firstword(str + 1, ' ');
	if (is_infile(filename) == FALSE)
	{
		free(filename);
		return(-1);
	}
	i = open(filename, O_RDONLY);
	close(i);
	free(filename);
	return (i);
}

int	parse_fdin(char *str)
{
	int		fdin;
	char	*ptr;

	if (is_x_char_in_str(str, '<', 3) == TRUE)
	{
		ft_printf("bash: syntax error near unexpected token `<'");
		return (-1);
	}
	if (is_x_char_in_str(str, '<', 1) == FALSE)
		return(0);
	ptr = ft_strrchr(str, '<');
	if (*(ptr - 1) == '<')
		return (0);
	fdin = define_fdin(ptr);
	return(fdin);
}