/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaineb <jlaineb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:42:16 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/01/16 00:14:04 by jlaineb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	if (big == NULL || little == NULL || little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] != '\0' && i <= len)
	{
		j = 0;
		if (big[i] == little[j])
		{
			k = i;
			while (big[k++] == little[j++] && k <= len)
			{
				if (little[j] == '\0')
					return ((char *)&big[i]);
				if (big[k] == '\0')
					return (NULL);
			}
		}
		i++;
	}
	return (NULL);
}
