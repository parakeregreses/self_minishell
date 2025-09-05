/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_verifications.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:05:14 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/09/05 20:12:36 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_pipe_near_chevron(char *str)
{
	int	i;

	if (!str[1])
		return (FALSE);
	i = 1;
	while (str[i])
	{
		if (str[i] == '|' && (str[i - 1] == '<' || str[i - 1] == '>'))
			return (TRUE);
		i++;
	}
	return (FALSE);
}

int	pipe_near_chevron(t_arg *tab, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if ((tab[i]).quote == 0 && is_pipe_near_chevron((tab[i]).str) == 1)
			return (1);
		i++;
	}
	return (0);
}

int	second_verifications(t_arg *tab)
{
	int	n;

	n = tab_size_arg(tab);
	if (pipe_near_chevron(tab, n) == TRUE)
	{
		write(2, "minishell: syntax error near unexpected token `|'\n", 50);
		return (FALSE);
	}
	if (triple_char(tab, n, '<') == TRUE)
	{
		write(2, "minishell: syntax error near unexpected token `<<'\n", 51);
		return (FALSE);
	}
	if (triple_char(tab, n, '>') == TRUE)
	{
		write(2, "minishell: syntax error near unexpected token `>>'\n", 51);
		return (FALSE);
	}
	if (double_char(tab, n, '|') == TRUE)
	{
		write(2, "minishell: syntax error near unexpected token `|'\n", 50);
		return (FALSE);
	}
	return (TRUE);
}
