/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:26:24 by jlaine-b          #+#    #+#             */
/*   Updated: 2024/10/26 16:09:18 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_join(char *s1, char *s2, char *str)
{
	unsigned int	len;
	unsigned int	i;

	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	len = i;
	i = 0;
	while (s2[i] != '\0')
	{
		str[len + i] = s2[i];
		i++;
	}
	str[len + i] = '\0';
	return (str);
}

char	*ft_strjoinfree(char *s1, char *s2)
{
	char	*str;

	str = NULL;
	if (s1 == NULL && s2 == NULL)
		return (str);
	else if (s1 == NULL)
		str = ft_strdup(s2);
	else if (s2 == NULL)
		str = ft_strdup(s1);
	else
		str = ft_join(s1, s2, str);
	free(s1);
	free(s2);
	return (str);
}
