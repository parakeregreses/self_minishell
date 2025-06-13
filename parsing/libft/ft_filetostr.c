/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filetostr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 11:32:15 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/01/11 11:32:17 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_filetostr(char *pathname)
{
	int		fd;
	int		n;
	char	*str;
	char	*buffer;

	fd = open(pathname, O_RDONLY);
	n = 5;
	buffer = malloc(sizeof(char) * (n + 1));
	str = NULL;
	while (n == 5)
	{
		n = read(fd, buffer, n);
		buffer[n] = '\0';
		str = ft_strjoinfree(str, buffer);
		buffer = malloc(sizeof(char) * (n + 1));
	}
	free(buffer);
	return (str);
}
