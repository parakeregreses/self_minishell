/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_firstword.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaineb <jlaineb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:46:09 by jlaineb           #+#    #+#             */
/*   Updated: 2025/04/14 17:46:57 by jlaineb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_firstword(char *str, char c)
{
	int		i;
	int		j;
	int		k;
	char	*word;

	i = 0;
	k = 0;
	while (str[i] == c && str[i] != '\0')
		i++;
	j = i;
	while (str[i] != c && str[i] != '\0')
		i++;
	word = malloc(sizeof(char) * (i - j + 1));
	while (j != i)
		word[k++] = str[j++];
	word[j] = '\0';
	return (word);
}
