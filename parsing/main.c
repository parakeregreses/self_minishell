/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:14:26 by jlaineb           #+#    #+#             */
/*   Updated: 2025/06/13 11:36:17 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char 	*str = "\'de|but\'fin|fin";
	//"\'1|2|1|2\'bonjour|a|tous\"les|amiiis\"bienvenue|a|\'l|ecole|42\'
	t_arg	*tab;

	tab = parsing_minishell(str);
	if (tab == NULL)
		return (0);
	print_tab_arg(tab);
	free_tab_arg(tab);
}