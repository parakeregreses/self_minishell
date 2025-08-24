/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:14:26 by jlaineb           #+#    #+#             */
/*   Updated: 2025/08/24 18:23:37 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// parse the command and execute it
int	command(char *str, char ***envp, int *status)
{
	t_exec	*infos;
	int		n;
	char	**blocs;
	char	***processes;

	blocs = blocisation(str, status);
	if (blocs == NULL)
		return (0);
	n = tab_size(blocs);
	processes = full_tokenisation(blocs, n);
	free_tab((void **) blocs);
	infos = extract_infos(processes, n, status, envp);
	free_tab_3d(processes);
	parse_commands(infos, n, envp, status);
	pipex(infos, n, envp, status);
	full_delete_minishell(infos, n);
	return (0);
}
