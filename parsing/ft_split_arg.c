/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 07:09:04 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/06/20 20:03:09 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static unsigned int	ft_nwords(char const *s, char c)
{
	unsigned int	n;
	unsigned int	i;

	if (s == NULL)
		return (0);
	n = 0;
	if (s[0] != c && s[0] != '\0')
		n = 1;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != '\0' && s[i + 1] != c)
			n++;
		i++;
	}
	return (n);
}

static char	*ft_fill(unsigned int j, char const *s, char c)
{
	unsigned int	k;
	unsigned int	l;
	char			*tabi;

	k = 0;
	l = j;
	while (s[l] != '\0' && s[l] != c)
		l++;
	tabi = calloc(sizeof(char), (l - j + 1));
	if (!tabi)
		return (NULL);
	while (s[j] != '\0' && s[j] != c)
		tabi[k++] = s[j++];
	tabi[k] = '\0';
	return (tabi);
}

t_arg	*ft_split_arg(char const *s, char c)
{
	t_arg			*tab;
	unsigned int	j;
	unsigned int	i;

	i = 0;
	j = 0;
	tab = calloc(sizeof(t_arg), (ft_nwords(s, c) + 1));
	if (!tab)
		return (NULL);
	while (i < ft_nwords(s, c))
	{
		while (s[j] != '\0' && s[j] == c)
			j++;
		(tab[i++]).str = ft_fill(j, s, c);
		if ((tab[i - 1]).str == NULL)
		{
			free_tab_arg(tab);
			return (NULL);
		}
		while (s[j] != '\0' && s[j] != c)
			j++;
	}
	(tab[i]).str = NULL;
	return (tab);
}
