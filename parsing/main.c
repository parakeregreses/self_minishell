/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:14:26 by jlaineb           #+#    #+#             */
/*   Updated: 2025/06/10 17:13:44 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char 	*str = "'hello'end";
	t_arg	*tab;
	// char **tab1;

	// tab1 = ft_split(str, '|');
	// tab = cut_tab_tail(tab1, 3);
	// print_tab_char(tab);
	// free_tab((void **)tab);
	// free_tab((void **)tab1);

	tab = parsing_minishell(str);
	if (tab == NULL)
		return (0);
	print_tab_arg(tab);
	free_tab_arg(tab);
}
