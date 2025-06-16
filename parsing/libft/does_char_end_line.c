/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   does_pipe_end_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 21:44:26 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/06/16 11:24:26 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	does_char_end_line(char *line, char c)
{
	char	*ptr;
	int		i;

	i = 1;
	ptr = ft_strrchr(line, c);
	if (ptr == NULL)
		return (FALSE);
	while (ptr[i] != 0)
	{
		if (ft_iswhitespace(ptr[i]) != TRUE && ptr[i] != 0)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
