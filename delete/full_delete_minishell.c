/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_delete_minishell.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 12:44:56 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/15 20:05:08 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	full_delete_minishell(char **blocs, char ***processes, t_exec *infos, int n)
{
	int	i;

	i = 0;
	free_tab((void **) blocs);
	delete_tempfiles(infos, n);
	while (i != n)
	{
		free_tab((void **)processes[i]);
		free_tab((void **)(infos[i]).cmdarg);
		free((infos[i]).cmdpath);
		free((infos[i]).infile.filename);
		i++;
	}
	free(processes);
	free(infos);
	return (0);
}
