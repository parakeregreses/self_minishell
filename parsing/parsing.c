/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 10:16:59 by jlaineb           #+#    #+#             */
/*   Updated: 2025/06/09 16:31:14 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_arg	**parsing_minishell(char *str);

t_arg	*select_quoted_str(char *str)
{
	t_arg	*tab1;
	t_arg	*tab2;
	int		n;
	char	separator;

	tab1 = NULL;
	if (ft_charinstr(str, '\'') == TRUE || ft_charinstr(str, '\"') == TRUE)
	{
		separator = which_separator(str, '\'', '\"');
		tab1 = extract_str_in_str(str, find_segment(str, separator));
	}
	n = tab_size_arg(tab1);
	while (ft_charinstr((tab1[n - 1]).str, '\'') == TRUE || ft_charinstr((tab1[n - 1]).str, '\"') == TRUE)
	{
		tab2 = select_quoted_str((tab1[n - 1]).str);
		tab1 = append_tabs_and_free_arg(delete_line_in_tab_arg(tab1, n - 1), tab2);
		n = tab_size_arg(tab1);
	}
	return (tab1);
}

// cut tab tail, line n included. Returns tab head
char	**cut_tab_tail(char **tab, int n)
{
	int		i;
	int		size;
	char	**new_tab;

	size = tab_size(tab);
	if (n > size)
		return (NULL);
	i = 0;
	new_tab = malloc(sizeof(char *) * n);
	while (i < (n - 1))
	{
		new_tab[i] = ft_strdup(tab[i]);
		i++;
	}
	new_tab[i] = NULL;
	return (new_tab);
}

// cut tab head, line n included. Returns tab tail
char	**cut_tab_head(char **tab, int n)
{
	int		i;
	int		size;
	char	**new_tab;

	size = tab_size(tab);
	if (n >= size)
		return (NULL);
	i = n + 1;
	new_tab = malloc(sizeof(char *) * (size - i + 1));
	while (i < size)
	{
		new_tab[i - n - 1] = ft_strdup(tab[i]);
		i++;
	}
	new_tab[i - n - 1] = NULL;
	return (new_tab);
}

// char	**separate_pipe(char **arg)
// {
// 	int		n;
// 	int		i;
// 	t_arg	**tab1;
// 	t_arg	**tab2;
// 	t_arg	**tab3;

// 	n = tab_size(arg);
// 	ft_printf("n = %d\n", n);
// 	tab1 = ft_split(arg[0], '|');
// 	arg = append_tabs_and_free(tab1, delete_line_in_tab(arg, 0));
// 	i = 0;
// 	ft_printf("\ni = %d\n", i);
// 	print_tab_char(arg);
// 	ft_printf("%d\n", i);
// 	i = i + 2;
// 	while (i < n)
// 	{
// 		ft_printf("%d\n", i);
// 		tab1 = cut_tab_tail(arg, i);
// 		// ft_printf("cut tail\n");
// 		tab2 = ft_split(arg[i], '|');
// 		// ft_printf("split\n");
// 		tab3 = cut_tab_head(arg, i);
// 		// ft_printf("head\n");
// 		free(arg);
// 		// ft_printf("free\n");
// 		arg = append_tabs_and_free(tab1, tab2);
// 		// ft_printf("append1\n");
// 		arg = append_tabs_and_free(arg, tab3);
// 		// ft_printf("append2\n");
// 		ft_printf("\ni = %d\n", i);
// 		print_tab_char(arg);
// 		i = i + 2;
// 	}
// 	return (arg);
// }

t_arg	**parsing_minishell(char *str)
{
	t_arg **arg;

	arg = select_quoted_str(str);
	print_tab_arg(arg);
	// ft_printf("on a separe les quotes\n");
	// arg = separate_pipe(arg);
	return (arg);
}
