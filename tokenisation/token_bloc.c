/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_bloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 20:40:28 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/07/29 16:26:45 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	allow_tab(char *str, char *set)
{
	int		i;
	int		ntoken;
	char	c;

	i = 0;
	ntoken = 1;
	while (ft_ischarinset(str[i], set) == TRUE)
		i++;
	while (str[i] != 0)
	{
		if (str[i] && ft_ischarinset(str[i], "\"'") == TRUE)
		{
			c = str[i++];
			while (str[i] != c)
				i++;
			i++;
		}
		if (ft_ischarinset(str[i], set) == TRUE)
		{
			ntoken++;
			if (str[i + 1] && str[i] == str[i + 1])
				i++;
		}
		if (str[i] && ft_ischarinset(str[i], "\"'") == FALSE)
			i++;
	}
	return (ntoken);
}

static char	*fill_line(char *str, int *i, char *set)
{
	int		j;
	int		k;
	char	*line;
	char	c;

	j = *i;
	*i = *i + 1;
	if (str[*i] && ft_ischarinset(str[*i], set) == TRUE && str[*i] == str[*i - 1])
		*i = *i + 1;
	while (str[*i] && ft_ischarinset(str[*i], set) == FALSE)
	{
		if (str[*i] && ft_ischarinset(str[*i], "\"'") == TRUE)
		{
			c = str[*i];
			*i = *i + 1;
			while (str[*i] != c)
				*i = *i + 1;
			*i = *i + 1;
		}
		*i = *i + 1;
	}
	line = malloc(sizeof(char) * (*i - j) + 1);
	if (!line)
		return (NULL);
	k = 0;
	while (j != *i)
		line[k++] = str[j++];
	line[k] = 0;
	return (line);
}

static char	**fill_tab(char **tab, char *str, char *set, int nlines)
{
	int	line;
	int	i;

	line = 0;
	i = 0;
	while (line < nlines)
	{
		tab[line] = fill_line(str, &i, set);
		line++;
	}
	tab[line] = NULL;
	return (tab);
}

char	**token_bloc(char *str)
{
	char	**tab;
	char	*set;
	int		n;

	set = ft_strdup("<>- ");
	str = ft_strtrim(str, WHITESPACES);
	str = delete_useless_spaces(str, set);
	n = allow_tab(str, set);
	tab = malloc (sizeof(char *) * (n + 1));
	if (tab == NULL)
		return (NULL);
	tab = fill_tab(tab, str, set, n);
	free(set);
	free(str);
	return (tab);
}
