/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_firstword.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:46:09 by jlaineb           #+#    #+#             */
/*   Updated: 2025/07/15 14:44:31 by jlaine-b         ###   ########.fr       */
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
	ft_printf("first_word : str = %s, i = %d, j = %d\n", str, i, j);
	word = malloc(sizeof(char) * (i - j + 1));
	while (j != i)
		word[k++] = str[j++];
	ft_printf("j = %d\n", j);
	word[k] = '\0';
	ft_printf("word = %s\n", word);
	return (word);
}
