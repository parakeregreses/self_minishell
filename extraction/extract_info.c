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

t_exec	init_info(void)
{
	t_exec	info;

	info.outfile.filename = NULL;
	info.outfile.append = 0;
	info.infile.filename = NULL;
	info.infile.tempfilename = NULL;
	info.infile.here_doc = 0;
	return (info);
}

t_exec	extract_info(char **tokens, int *status, char ***envp)
{
	t_exec	info;

	info = init_info();
	info = find_in_out_file(tokens, status, envp, info);
	info.cmdarg = find_cmdarg(tokens, status, envp);
	return (info);
}
