/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:14:26 by jlaineb           #+#    #+#             */
/*   Updated: 2025/06/09 17:51:12 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char 	*str = "\'cmd1|\'cmd2 \"bla|bla\"|cmd3|cmd4|cmd6\'blou|blouh\'";
	t_arg	*tab;
	// char **tab1;

	// tab1 = ft_split(str, '|');
	// tab = cut_tab_tail(tab1, 3);
	// print_tab_char(tab);
	// free_tab((void **)tab);
	// free_tab((void **)tab1);

	tab = parsing_minishell(str);
	print_tab_arg(tab);
	free_tab_arg(tab);
}
