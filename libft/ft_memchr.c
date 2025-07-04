/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaineb <jlaineb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:49:18 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/01/15 23:03:52 by jlaineb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	void			*ptr;
	unsigned char	*s1;
	unsigned char	c1;

	if (s == NULL)
		return (NULL);
	s1 = (unsigned char *)s;
	c1 = (unsigned char)c;
	i = 0;
	ptr = NULL;
	while (i < n)
	{
		if (s1[i] == c1)
		{
			ptr = &s1[i];
			return (ptr);
		}
		i++;
	}
	return (ptr);
}
