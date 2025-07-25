/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_bloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 20:40:28 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/07/24 10:46:03 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	allow_tab(char *str, char *set)
{
	int	i;
	int	ntoken;

	i = 0;
	ntoken = 1;
	while (str[i] != 0)
	{
		// printf("i = %d, str[i] = %c\n", i, str[i]);
		if (str[i] && ft_ischarinset(str[i], set) == TRUE)
		{
			ntoken++;
			if (str[i + 1] && str[i] == str[i + 1])
				i++;
		}
		if (str[i])
			i++;
	}
	// printf("i = %d, str[i] = %c\n", i, str[i - 1]);
	// printf("i = %d, n = %d\n", i, ntoken);
	// tab = malloc (sizeof(char *) * ntoken + 1);
	return (ntoken);
}

static char	*fill_line(char *str, int *i, char *set)
{
	int		j;
	int		k;
	char	*line;

	*i = *i + 1;
	j = *i;
	while (str[*i] && ft_ischarinset(str[*i], set) == FALSE)
		*i = *i + 1;
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

static char	**fill_tab(char **tab, char *str, char *set)
{
	int	line;
	int	i;

	line = 0;
	i = 0;
	printf("lestgo\n");
	while (line < 6)
	{
		tab[line] = fill_line(str, &i, set);
		// printf("i = %d\n", i);
		printf("line[%d] = %s\n", line, tab[line]);
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
	printf("ok?\n");
	str = ft_strtrim(str, WHITESPACES);
	printf("trimmed\n");
	str = delete_useless_spaces(str, set);
	printf("deleted\n");
	n = allow_tab(str, set);
	tab = malloc (sizeof(char *) * n + 1);
	if (tab == NULL)
		return(NULL);
	printf("allowed\n");
	tab = fill_tab(tab, str, set);
	free(set);
	return (tab);
}

int	main(void)
{
	char	**tab;
	char	*str;

	str = ft_strdup("hello<les<lim>amis arg");
	tab = token_bloc(str);
	free(str);
	print_tab_char(tab);
	free_tab((void **)tab);
}