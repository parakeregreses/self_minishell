/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:20:51 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/06/18 10:26:42 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strrchri(const char *s, int c)
{
	int		i;
	int		n;
	char	*s1;

	if (s == NULL)
		return (-1);
	s1 = (char *)s;
	i = 0;
	n = -1;
	while (s1[i] != '\0')
	{
		if (s1[i] == (char) c)
		{
			n = i;
		}
		i++;
	}
	if ((char) c == '\0')
		n = i;
	return (n);
}
