/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   does_pipe_end_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 21:44:26 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/06/13 21:44:27 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	does_pipe_end_line(char *line)
{
	char	*ptr;
	int		i;

	ptr = ft_strrchr(line, '|');
	while (ptr[i] != 0)
	{
		if (is_whitespace(ptr[i++]) != TRUE)
			return (TRUE);
	}
	return (FALSE);
}