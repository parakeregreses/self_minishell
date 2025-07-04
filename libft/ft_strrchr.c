/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaineb <jlaineb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:20:51 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/01/16 00:16:27 by jlaineb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
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
		}
		i++;
	}
	if ((char) c == '\0')
		ptr = &s1[i];
	return (ptr);
}
