/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separate_pipe2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:50:16 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/07 11:51:49 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// cut tab tail, line n included. Returns tab head
t_arg	*cut_tab_tail_arg(t_arg *tab, int n)
{
	int		i;
	int		size;
	t_arg	*new_tab;

	size = tab_size_arg(tab);
	if (n > size)
		return (NULL);
	i = 0;
	new_tab = malloc(sizeof(t_arg) * n);
	while (i < (n - 1))
	{
		(new_tab[i]).str = ft_strdup((tab[i]).str);
		(new_tab[i]).quote = (tab[i]).quote;
		i++;
	}
	(new_tab[i]).str = NULL;
	(new_tab[i]).quote = 0;
	return (new_tab);
}

// cut tab head, line n included. Returns tab tail
t_arg	*cut_tab_head_arg(t_arg *tab, int n)
{
	int		i;
	int		size;
	t_arg	*new_tab;

	size = tab_size_arg(tab);
	if (n >= size)
		return (NULL);
	i = n + 1;
	new_tab = malloc(sizeof(t_arg) * (size - i + 1));
	while (i < size)
	{
		(new_tab[i - n - 1]).str = ft_strdup((tab[i]).str);
		(new_tab[i - n - 1]).quote = (tab[i]).quote;
		i++;
	}
	(new_tab[i - n - 1]).str = NULL;
	(new_tab[i - n - 1]).quote = 0;
	return (new_tab);
}

t_arg	*ft_quoteiszero(t_arg *tab)
{
	int	i;

	i = 0;
	while ((tab[i]).str != NULL)
		(tab[i++]).quote = 0;
	return (tab);
}

int	is_pipe_left(int i, t_arg *arg)
{
	while ((arg[i]).str != NULL)
	{
		if ((arg[i]).quote == FALSE && ft_charinstr((arg[i]).str, '|') == TRUE)
			return (TRUE);
		i++;
	}
	return (FALSE);
}
