/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaineb <jlaineb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:37:19 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/01/15 23:42:14 by jlaineb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ptr;
	char	*s1;

	if (s == NULL)
		return (NULL);
	s1 = (char *)s;
	i = 0;
	ptr = NULL;
	while (s1[i] != '\0')
	{
		if (s1[i] == (char) c)
		{
			ptr = &s1[i];
			return (ptr);
		}
		i++;
	}
	if ((char) c == '\0')
		ptr = &s1[i];
	return (ptr);
}
