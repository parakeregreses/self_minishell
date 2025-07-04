/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:33:32 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/06/04 14:33:33 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_fill_new_buffer(size_t len, char *str, char *buffer)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	new_str = malloc(sizeof(char) * (len + 1));
	i = 0;
	while (str[i] != '\0')
		new_str[j++] = str[i++];
	i = 0;
	while (buffer[i] != '\0')
		new_str[j++] = buffer[i++];
	new_str[j] = '\0';
	return (new_str);
}

ssize_t	ft_read(char **adr_str, int fd)
{
	ssize_t	nbytes_read;
	char	*buffer;
	char	*new_str;
	size_t	len;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (-1);
	nbytes_read = read(fd, buffer, BUFFER_SIZE);
	if (nbytes_read == -1)
	{
		free(buffer);
		return (nbytes_read);
	}
	buffer[nbytes_read] = '\0';
	ft_strlen(*adr_str);
	len = ft_strlen(*adr_str) + nbytes_read;
	new_str = ft_fill_new_buffer(len, *adr_str, buffer);
	free(buffer);
	free(*adr_str);
	*adr_str = new_str;
	return (nbytes_read);
}

char	*ft_line(char	**adr_str)
{
	char	*line;
	int		i;

	i = 0;
	while (adr_str[0][i] != '\n' && adr_str[0][i] != '\0')
		i++;
	line = malloc(sizeof(char) * i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (adr_str[0][i] != '\n' && adr_str[0][i] != '\0')
	{
		line[i] = adr_str[0][i];
		i++;
	}
	if (adr_str[0][i] == '\n')
	{
		line[i] = adr_str[0][i];
		i++;
	}
	line[i] = '\0';
	free(*adr_str);
	return (line);
}

char	*get_next_line(int fd)
{
	char		**adr_str;
	char		*str_buffer;
	ssize_t		nbytes_read;
	static char	rest[BUFFER_SIZE];
	int			i;

	str_buffer = ft_initptr(rest);
	adr_str = &str_buffer;
	nbytes_read = BUFFER_SIZE;
	while (nbytes_read == BUFFER_SIZE && (find_newline(*adr_str) == 0))
		nbytes_read = ft_read(adr_str, fd);
	if (nbytes_read == -1 || (nbytes_read == 0 && *adr_str[0] == '\0'))
	{
		free(*adr_str);
		return (NULL);
	}
	i = ft_index(*adr_str);
	nbytes_read = 0;
	while (adr_str[0][i] != '\0')
		rest[nbytes_read++] = adr_str[0][i++];
	rest[nbytes_read] = '\0';
	return (ft_line(adr_str));
}
