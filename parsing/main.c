/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:14:26 by jlaineb           #+#    #+#             */
/*   Updated: 2025/06/12 14:32:01 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char 	*str = "cm1|cm2\"arg|\"|cm3";
	t_arg	*tab;

	tab = parsing_minishell(str);
	if (tab == NULL)
		return (0);
	print_tab_arg(tab);
	free_tab_arg(tab);
}