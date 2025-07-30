/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_processes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:00:40 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/07/30 19:05:29 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_exec	*parsing_processes(char ***processes, int n)
{
	int		i;
	t_exec	*infos;

	i = 0;
	infos = malloc(sizeof(t_exec) * (n + 1));
	while (processes[i] != NULL)
	{
		infos[i] = extract_infos(processes[i]);
		i++;
	}
	return (infos);
}