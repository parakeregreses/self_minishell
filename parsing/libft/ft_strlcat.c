/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:04:26 by jlaine-b          #+#    #+#             */
/*   Updated: 2024/10/30 11:31:47 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	len = ft_strlen(dst);
	if (size < (len + 1))
		return (ft_strlen(src) + size);
	else
	{
		while ((len + i + 1) < size && src[i] && i < (len + ft_strlen(src)))
		{
			dst[len + i] = src[i];
			i++;
		}
		dst[len + i] = '\0';
		return (len + ft_strlen(src));
	}
}
