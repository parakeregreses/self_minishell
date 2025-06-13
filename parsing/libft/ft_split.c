/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 07:09:04 by jlaine-b          #+#    #+#             */
/*   Updated: 2024/11/02 08:11:20 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static void	ft_free(char **tab, unsigned int imax)
{
	unsigned int	i;

	i = 0;
	while (i < imax)
		free(tab[i++]);
	free(tab);
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
	tabi = malloc(sizeof(char) * (l - j + 1));
	if (!tabi)
		return (NULL);
	while (s[j] != '\0' && s[j] != c)
		tabi[k++] = s[j++];
	tabi[k] = '\0';
	return (tabi);
}

char	**ft_split(char const *s, char c)
{
	char			**tab;
	unsigned int	j;
	unsigned int	i;

	i = 0;
	j = 0;
	tab = malloc(sizeof(char *) * (ft_nwords(s, c) + 1));
	if (!tab)
		return (NULL);
	while (i < ft_nwords(s, c))
	{
		while (s[j] != '\0' && s[j] == c)
			j++;
		tab[i++] = ft_fill(j, s, c);
		if (tab[i - 1] == NULL)
		{
			ft_free(tab, i - 1);
			return (NULL);
		}
		while (s[j] != '\0' && s[j] != c)
			j++;
	}
	tab[i] = NULL;
	return (tab);
}
