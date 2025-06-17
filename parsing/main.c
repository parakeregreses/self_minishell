/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:14:26 by jlaineb           #+#    #+#             */
/*   Updated: 2025/06/17 12:50:45 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char 	*str = "cmd<infile|cmd|\'1|2|1|2\'bonjour|a|tous\"les|amiiis\"bienvenue|a|\'l|ecole|42\'arg|cmd|cmd";
	// char 	*str = "cmd1\'1|2|\'bonjour\"les|amiiis\"cmd2";
	char *str2;
	t_arg	*tab;

	tab = parsing_minishell(str);
	if (tab == NULL)
		return (0);
	print_tab_arg(tab);
	str2 = reglue_quoted(tab);
	ft_printf("\n\n%s\n", str2);
	// parse_bloc((tab[0]).str);
	free_tab_arg(tab);
	free(str2);
}