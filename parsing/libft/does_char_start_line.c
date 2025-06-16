/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   does_char_start_line.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 21:44:26 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/06/16 11:31:33 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	does_char_start_line(char *line, char c)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = ft_strchr(line, c);
	if (ptr == NULL)
		return (FALSE);
	while (&(line[i]) != ptr)
	{
		if (ft_iswhitespace(line[i]) != TRUE && line[i] != 0)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
