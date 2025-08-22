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

t_exec	extract_info(char **tokens, int *status, char ***envp)
{
	t_exec	info;

	info = find_in_out_file(tokens, status, envp);
	// if (info.infile.here_doc == -1)
	// {
	// 	info.outfile.append = -1;
	// 	info.outfile.filename = NULL;
	// }
	// else
	// 	info.outfile = find_outfile(tokens, status, envp);
	info.cmdarg = find_cmdarg(tokens, status, envp);
	return (info);
}
