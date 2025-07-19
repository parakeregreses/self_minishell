/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenisation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 20:35:47 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/07/19 21:47:48 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 07:09:04 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/07/03 12:59:38 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static unsigned int	ft_nwords(char const *s, char *set)
{
	unsigned int	n;
	unsigned int	i;

	if (s == NULL)
		return (0);
	n = 0;
	if (ft_ischarinset(s[0], set) == FALSE && s[0] != '\0')
		n = 1;
	i = 0;
	while (s[i] != '\0')
	{
		if (ft_ischarinset(s[i], set) == TRUE && s[i + 1] != '\0' && ft_ischarinset(s[i + 1], set) == FALSE)
			n++;
		i++;
	}
	return (n);
}

static char	*ft_fill(unsigned int j, char const *s, char *set)
{
	unsigned int	k;
	unsigned int	l;
	char			*tabi;

	k = 0;
	l = j;
	while (s[l] != '\0' && ft_ischarinset(s[l], set) == FALSE) // a la fin du mot, on elimine tout le set !
		l++;
	ft_printf("j = %d, l = %d\n", j, l);
	tabi = calloc(sizeof(char), (l - j + 1));
	if (!tabi)
		return (NULL);
	while (s[j] != '\0' && ft_ischarinset(s[j], set) == FALSE)
	{
		tabi[k++] = s[j++];
	}
	tabi[k] = '\0';
	return (tabi);
}

t_arg	*tokenisation(char const *s, char *set)
{
	t_arg			*tab;
	unsigned int	j;
	unsigned int	i;

	i = 0;
	j = 0;
	tab = calloc(sizeof(t_arg), (ft_nwords(s, set) + 1));
	ft_printf("nwords = %d\n", ft_nwords(s, set));
	if (!tab)
		return (NULL);
	while (i < ft_nwords(s, set))
	{
		s = ft_strtrim(s, set);
		while (s[j] != '\0' && ft_iswhitespace(s[j]) == TRUE) // au debut du mot, on elimine seulement les whitespaces
			j++;
		(tab[i++]).str = ft_fill(j, s, set);
		if ((tab[i - 1]).str == NULL)
		{
			free_tab_arg(tab);
			return (NULL);
		}
		while (s[j] != '\0' && ft_ischarinset(s[j], set) == FALSE)
			j++;
	}
	(tab[i]).str = NULL;
	(tab[i]).quote = 0;
	return (tab);
}

int	main(void)
{
	t_arg	*tab;
	
	tab = tokenisation("cmd<file < file2 argarg > outfile1>outfile2", "<>-");
	print_tab_arg(tab);
	free_tab_arg(tab);
}
