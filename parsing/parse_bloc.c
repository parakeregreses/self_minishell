/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:23:15 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/06/17 11:56:15 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_exec	parse_bloc(char *str)
{
	// int		error;
	t_exec	info;

	info.fdin = parse_fdin(str);
	return (info);
}