/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:47:34 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/07/28 13:28:47 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_trim(char *str, char const *s1, char const *set, unsigned int n)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0' && (ft_ischarinset(s1[i], set) == 1))
		i++;
	while (s1[i] != '\0' && j < (ft_strlen(s1) - n))
		str[j++] = s1[i++];
	// printf("j = %u, lenstr = %lu\n", j, ft_strlen(s1) - n);
	str[j] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned int	s1len;
	char			*str;

	i = 0;
	s1len = ft_strlen(s1);
	if (s1 == NULL)
		return (NULL);
	while (s1[i] != '\0' && (ft_ischarinset(s1[i], set) == 1))
		i++;
	if (i != s1len)
	{
		while (s1len > 0 && (ft_ischarinset(s1[s1len - 1], set) == 1))
		{
			i++;
			s1len--;
		}
	}
	str = malloc(sizeof(char) * (ft_strlen(s1) - i + 1));
	if (!str)
		return (NULL);
	str = ft_trim(str, s1, set, i);
	return (str);
}

