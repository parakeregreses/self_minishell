/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaineb <jlaineb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 09:19:11 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/01/15 23:15:42 by jlaineb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *d, const void *s, size_t n)
{
	size_t	i;

	i = 0;
	if (d == NULL || s == NULL)
		return (NULL);
	while (i < n)
	{
		*((char *)d + i) = *((char *)s + i);
		i++;
	}
	return (d);
}
