/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:41:57 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/07/24 10:45:00 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dup;
	size_t	i;

	if (src == NULL)
		return (NULL);
	i = 0;
	dup = (char *)malloc((sizeof(char) * ft_strlen(src)) + 1);
	if (dup == NULL)
		return (NULL);
	while (i < ft_strlen(src))
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	ft_bzero(dup, ft_strlen(src) + 1);
	return (dup);
}
