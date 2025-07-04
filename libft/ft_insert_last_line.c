/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_last_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaineb <jlaineb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:31:51 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/05/22 19:24:14 by jlaineb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_lines(char **text)
{
	int	i;

	i = 0;
	while (text[i] != NULL)
		i++;
	return (i);
}

char	**ft_insert_last_line(char **text, char *line)
{
	int		nlines;
	char	**new_text;
	int		i;

	nlines = ft_count_lines(text);
	new_text = malloc(sizeof(char *) * (nlines + 2));
	i = 0;
	while (i < nlines)
	{
		new_text[i] = ft_strdup(text[i]);
		i++;
	}
	new_text[i++] = ft_strdup(line);
	new_text[i] = NULL;
	free_tab((void **)text);
	return (new_text);
}
