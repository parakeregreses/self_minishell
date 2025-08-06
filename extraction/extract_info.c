/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:06:15 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/04 16:22:58 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_exec	extract_info(char **tokens)
{
	t_exec	info;

	info.infile = find_infile(tokens);
	info.fdout = find_fdout(tokens);
	info.cmdarg = find_cmdarg(tokens);
	return (info);
}
