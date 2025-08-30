/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 22:23:36 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/30 18:42:38 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	quote_check(char *str, int i, int *q)
{
	if (str[i] && str[i] == '\'' && q == 0)
		i = close_quote(str, i, str[i]);
	if (str[i] && str[i] == '"')
		*q = ft_bool(*q);
	return (i);
}

static int	n_lines2(char *str, int q, int n, int i)
{
	while (str[i] != 0)
	{
		i = quote_check(str, i, &q);
		if (str[i] && str[i] == '$')
		{
			if (!str[i + 1])
				return (n);
			if (!(q == 1 && (str[i + 1] && ft_ischarinset(str[i + 1], "\" $"))))
			{
				n++;
				i = close_dollar(str, i + 1);
				if (str[i] == 0)
					return (n);
				n++;
			}
			else
				i++;
		}
		if (!str[i])
			return (n);
		i++;
	}
	return (n);
}

static int	n_lines(char *str)
{
	int		n;
	int		i;
	bool	q;

	n = 0;
	q = 0;
	if (str[0] != '$')
		n = 1;
	i = 0;
	return (n_lines2(str, q, n, i));
}

char	*expand(char *str, int status, char **envp)
{
	int		n;
	t_arg	*tab;

	if (ft_strcmp(str, "$") == 0)
		return (ft_strdup(str));
	n = n_lines(str);
	tab = malloc(sizeof(t_arg) * (n + 1));
	tab = fill_tab_expand(tab, str, n);
	tab = expand_tab(tab, status, envp);
	return (delete_quote(tab));
}
