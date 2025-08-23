/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   judith.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:14:26 by jlaineb           #+#    #+#             */
/*   Updated: 2025/08/23 17:11:30 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	judith(char *str, char ***envp, int *status)
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
	if (parse_commands(infos, n, envp, status) == FALSE)
		return (full_delete_minishell(infos, n));
	pipex(infos, n, envp, status);
	full_delete_minishell(infos, n);
	return (0);
}
