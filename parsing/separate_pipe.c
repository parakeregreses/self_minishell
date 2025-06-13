/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separate_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 21:35:18 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/06/13 21:52:01 by jlaine-b         ###   ########.fr       */
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
	return (new_tab);
}

t_arg	*ft_quoteiszero(t_arg *tab)
{
	int	i;

	i = 0;
	while((tab[i]).str != NULL)
		(tab[i++]).quote = 0;
	return (tab);
}

int	is_pipe_left(int i, t_arg *arg)
{
	while ((arg[i]).str != NULL)
	{
		if ((arg[i]).quote == FALSE && ft_charinstr((arg[i]).str, '|') == TRUE )
			return (TRUE);
		i++;
	}
	return (FALSE);
}

int	does_pipe_end_line(char *line)
{
	char	*ptr;
	int		i;

	ptr = ft_strrchr(line, '|');
	i = 1;
	while (ptr[i] != 0)
	{
		if (ft_iswhitespace(ptr[i++]) != TRUE)
			return (TRUE);
	}
	return (FALSE);
}

t_arg	*separate_pipe(t_arg *arg)
{
	int		n;
	int		i;
	t_arg	*tab1;
	t_arg	*tab2;
	t_arg	*tab3;
	// int		pipe_ends_line;

	n = tab_size_arg(arg);
	i = 0;
	while (is_pipe_left(i, arg) == TRUE)
	{
		if ((arg[i]).quote == FALSE && ft_charinstr((arg[i]).str, '|') == TRUE)
		{
			tab1 = cut_tab_tail_arg(arg, i + 1);
			// pipe_ends_line = does_pipe_end_line((arg[i]).str);
			tab2 = ft_split_arg((arg[i]).str, '|');
			tab2 = ft_quoteiszero(tab2);
			tab3 = cut_tab_head_arg(arg, i);
			free_tab_arg(arg);
			arg = append_tabs_and_free_arg(tab1, tab2);
			arg = append_tabs_and_free_arg(arg, tab3);
			n = tab_size_arg(arg);
		}
		i++;
	}
	return (arg);
}