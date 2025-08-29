/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 18:41:42 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/29 19:28:51 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_arg	fill_line(t_arg tab, char *str, int *i)
{
	int	n;
	int	j;

	j = *i;
	n = size_line(str + *i);
	*i = *i + n;
	tab.str = malloc(sizeof(char) * (n + 1));
	if (str[j] && str[j] == '$' && str[j + 1])
		return (fill_line1(tab, str, j));
	tab.quote = 0;
	return (fill_line2_dollar(tab, str, j));
}

t_arg	*fill_tab_expand(t_arg *tab, char *str, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i != n)
	{
		tab[i] = fill_line(tab[i], str, &j);
		i++;
	}
	tab[i].str = NULL;
	return (tab);
}

t_arg	*expand_tab(t_arg *tab, int status, char **envp)
{
	int	i;

	i = 0;
	while ((tab[i]).str != NULL)
	{
		if (tab[i].quote == 1)
			tab[i].str = dollar_signs(tab[i].str, status, envp);
		i++;
	}
	return (tab);
}
