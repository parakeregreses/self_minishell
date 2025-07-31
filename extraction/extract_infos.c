/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_infos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:06:15 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/07/31 17:35:31 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_exec	extract_infos(char **tokens)
{
	t_exec	info;

	info.fdin = find_fdin(tokens);
	info.fdout = find_fdout(tokens);
	info.cmdarg = find_cmdarg(tokens);
	return (info);
}
