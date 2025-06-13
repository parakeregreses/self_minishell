/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:21:30 by jlaine-b          #+#    #+#             */
/*   Updated: 2024/10/26 16:09:58 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char			*s;
	void			*p;
	unsigned int	i;

	i = 0;
	if (size != 0)
	{
		if ((size * nmemb) / size != nmemb)
			return (NULL);
	}
	s = malloc(size * nmemb);
	if (!s)
		return (NULL);
	while (i < size * nmemb)
	{
		*(s + i) = 0;
		i++;
	}
	p = (void *) s;
	return (p);
}
