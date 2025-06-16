/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:14:26 by jlaineb           #+#    #+#             */
/*   Updated: 2025/06/16 12:14:21 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char 	*str = "cmd|cmd|\'1|2|1|2\'bonjour|a|tous\"les|amiiis\"bienvenue|a|\'l|ecole|42\'arg|cmd|cmd";
	// char *str = "cmd0|cmd1'bis|ous'arg2|cmd4";
	t_arg	*tab;

	tab = parsing_minishell(str);
	if (tab == NULL)
		return (0);
	print_tab_arg(tab);
	free_tab_arg(tab);
}