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

// for each blocs, info holds the fdin, fdout, commands and command's arguments
t_exec	*extract_infos(char ***processes, int n, int *ex_code, char ***envp)
{
	int		i;
	t_exec	*infos;

	i = 0;
	infos = malloc(sizeof(t_exec) * (n + 1));
	while (processes[i] != NULL)
	{
		// print_tab_char(processes[i]);
		// ft_printf("i = %d\n\n", i);
		infos[i] = extract_info(processes[i], ex_code, envp);
		i++;
	}
	return (infos);
}
