/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:14:26 by jlaineb           #+#    #+#             */
/*   Updated: 2025/06/18 12:39:52 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	// char 	*str = "cmd<infile|cmd|\'1|2|1|2\'bonjour|a|tous\"les|amiiis\"bienvenue|a|\'l|ecole|42\'arg|cmd|END";
	char 	*str = "c\"md\"<i\"nfi\"le\"2\"|cmd|\'1|2|1|2\'bonjour|a|tous\"les|amiiis\"bienvenue|a|\'l|ecole|42\'arg|cmd|\"c\"md\"<i\"nfi\"le\"2\"END";
	// char 	*str = "cmd1\'1|2|\'bonjour\"les|amiiis\"cmd2";
	t_arg	*tab;

	tab = parsing_minishell(str);
	if (tab == NULL)
		return (0);
	ft_printf("tab apres separations des pipes :\n");
	print_tab_arg(tab);
	// parse_bloc((tab[0]).str);
	free_tab_arg(tab);
}