/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_infos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:00:40 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/05 12:42:51 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_exec	*extract_infos(char ***processes, int n, int *status, char ***envp)
{
	int		i;
	t_exec	*infos;

	i = 0;
	infos = malloc(sizeof(t_exec) * (n + 1));
	while (processes[i] != NULL)
	{
		infos[i] = extract_info(processes[i], status, envp);
		if (ft_strcmp((infos[i]).infile.tempfilename, "sigint") == 0)
		{
			free_tab((void **)(infos[i]).cmdarg);
			free((infos[i]).infile.filename);
			free((infos[i]).outfile.filename);
			free((infos[i]).infile.tempfilename);
			full_delete_minishell(infos, i);
			return (NULL);
		}
		i++;
	}
	return (infos);
}
