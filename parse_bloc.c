/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:23:15 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/07/29 16:14:59 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_exec	parse_bloc(char *str)
{
	// int		error;
	t_exec	info;
	char	**tab;
	int 	n;

	tab = token_bloc(str);
	n = tab_size(tab);
	// info.fdin = define_fdin(str, tab);
	// info.hd = is_here_doc(str, tab, n);
	// printf("%d\n", info.fdin);
	free_tab((void **)tab);
	return (info);
}