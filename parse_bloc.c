/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:23:15 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/06/18 10:42:11 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_exec	parse_bloc(char *str)
{
	// int		error;
	t_exec	info;
	t_arg	*tab;

	tab = select_quoted_str(str);
	// print_tab_arg(tab);
	info.fdin = parse_fdin(tab);
	// printf("%d\n", info.fdin);
	free_tab_arg(tab);
	return (info);
}