/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:33:40 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/06/04 14:33:41 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_initptr(char *rest)
{
	char	*str_buffer;
	int		i;

	i = 0;
	str_buffer = malloc(sizeof(char) * (ft_strlen(rest) + 1));
	if (!str_buffer)
		return (NULL);
	while (rest[i] != '\0')
	{
		str_buffer[i] = rest[i];
		i++;
	}
	str_buffer[i] = '\0';
	return (str_buffer);
}

int	find_newline(char *s)
{
	int	n;
	int	i;

	if (s == NULL)
		return (0);
	n = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n' && s[i + 1] != '\0')
			n++;
		i++;
	}
	return (n);
}

int	ft_index(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}
