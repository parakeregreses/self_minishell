/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_bloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 20:40:28 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/07/28 16:36:30 by jlaine-b         ###   ########.fr       */
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
	ft_printf("n = %d\n", ntoken);
	return (ntoken);
}

// int	main(void)
// {
// 	allow_tab("'<<'outfile<outi<out", "<> -");
// }

static char	*fill_line(char *str, int *i, char *set)
{
	int		j;
	int		k;
	char	*line;
	char	c;

	// if (nline != 0)
	// 	*i = *i + 1;
	// j = *i;
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
	// printf("inside : i = %d\n", *i);
	return (line);
}

static char	**fill_tab(char **tab, char *str, char *set, int nlines)
{
	int	line;
	int	i;

	line = 0;
	i = 0;
	// printf("lestgo\n");
	while (line < nlines)
	{
		tab[line] = fill_line(str, &i, set);
		// printf("i = %d\n", i);
		// printf("fill : line[%d] = %s\n", line, tab[line]);
		line++;
	}
	tab[line] = NULL;
	// printf("fill : line[%d] = %s\n", line, tab[line]);
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
		return(NULL);
	tab = fill_tab(tab, str, set, n);
	free(set);
	free(str);
	return (tab);
}

int	main(void)
{
	//tests
	char **str;
	char	**tab;

	str = malloc(sizeof(char *) * 12);

	str[0] = ft_strdup("");
	str[1] = ft_strdup(" ");
	str[2] = ft_strdup("hello");
	str[3] = ft_strdup("hello les amis");
	str[4] = ft_strdup("hello<les<amis");
	str[5] = ft_strdup("hello < les < amis");
	str[6] = ft_strdup("hello<<les < amis");
	str[7] = ft_strdup("hell'o l'es amis");
	str[8] = ft_strdup("hell'o<l'es<amis");
	str[9] = ft_strdup("hell'o < l'es < amis");
	str[10] = ft_strdup("hell'o<<l'es < amis");
	str[11] = NULL;
	int i = 0;
	while (str[i] != NULL)
	{
		tab = token_bloc(str[i]);
		ft_printf("str = %s\n tab = \n", str[i]);
		print_tab_char(tab);
		// ft_printf("\n");
		free(str[i]);
		free_tab((void **)tab);
		i++;
	}
	free(str);
}