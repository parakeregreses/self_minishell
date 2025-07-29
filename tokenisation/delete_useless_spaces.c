/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_useless_spaces.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 21:49:33 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/07/29 16:24:45 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	next_char_pos(char *str, char c)
{
	int	i;

	i = 1;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == 0)
		return (-1);
	return (i);
}

void	ft_increase(int *i, int *len)
{
	*i = *i + 1;
	*len = *len + 1;
}

int	define_quoted_value(char *s, int i)
{
	if ((s[i] == '\'' || s[i] == '"') && s[i + 1])
		return (next_char_pos(s + i + 1, s[i]) + 1);
	return (0);
}

int	len_new_str(char *s, char *c)
{
	int	len;
	int	i;
	int	quotedlen;

	len = 0;
	i = 0;
	while (s[i] != 0)
	{
		while (s[i] && ft_iswhitespace(s[i]) == FALSE)
		{
			quotedlen = define_quoted_value(s, i);
			len = len + quotedlen + 1;
			i = i + quotedlen + 1;
		}
		if (s[i] == 0)
			return (len);
		else if ((((ft_ischarinset(s[i - 1], c) == 1))
				|| (s[i + 1] && ft_ischarinset(s[i + 1], c) == 1)))
			i++;
		if (ft_iswhitespace(s[i]) == 1
			&& s[i + 1] && ft_ischarinset(s[i + 1], c) == 0)
			ft_increase(&i, &len);
	}
	return (len);
}

char	*delete_useless_spaces(char	*str, char *set)
{
	char	*new_str;

	if (str == NULL || str[0] == 0 || set == NULL)
		return (str);
	new_str = malloc(sizeof(char) * len_new_str(str, set) + 1);
	new_str = delete_useless_spaces_fill(str, new_str, set);
	free(str);
	return (new_str);
}
