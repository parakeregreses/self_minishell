/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_bloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 20:40:28 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/09 16:43:15 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	allow_tab(char *str, char *set)
{
	int		i;
	int		ntoken;

	i = 0;
	ntoken = 1;
	while (ft_ischarinset(str[i], set) == TRUE)
		i++;
	while (str[i] != 0)
	{
		if (str[i] && ft_ischarinset(str[i], "\"'") == TRUE)
		{
			i = close_quote(str, i, str[i]);
			i++;
		}
		if (str[i] && ft_ischarinset(str[i], set) == TRUE)
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

static char	*fill_line2(int j, int i, char *line, char *str)
{
	int	k;

	k = 0;
	while (j != i)
		line[k++] = str[j++];
	line[k] = 0;
	return (line);
}

// fill the line until a set caracter (outside quote) is found
static char	*fill_line(char *str, int *i, char *set)
{
	int		j;
	char	*line;

	j = *i;
	if (ft_ischarinset(str[*i], "\"'") == FALSE)
	{
		*i = *i + 1;
		if (str[*i] && ft_ischarinset(str[*i], set) == TRUE
			&& str[*i] == str[*i - 1])
			*i = *i + 1;
	}
	while (str[*i] && ft_ischarinset(str[*i], set) == FALSE)
	{
		if (str[*i] && ft_ischarinset(str[*i], "\"'") == TRUE)
			*i = close_quote(str, *i, str[*i]);
		*i = *i + 1;
	}
	line = malloc(sizeof(char) * (*i - j) + 1);
	if (!line)
		return (NULL);
	return (fill_line2(j, *i, line, str));
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

// returns a tab of the differents elements
// (starting by <, <<, >, >>, - or SPACE)
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
	tab = trim_tab_free(tab, " ");
	tab = tab_without_quotes(tab);
	// print_tab_char(tab);
	free(set);
	free(str);
	return (tab);
}
