/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:14:26 by jlaineb           #+#    #+#             */
/*   Updated: 2025/08/06 13:23:15 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_exec	*infos;
	int		n;
	t_arg	*blocs;
	char	***processes;

	if (argc == 1)
		return (0);
	blocs = blocisation(argv[1]);
	if (blocs == NULL)
		return (0);
	n = tab_size_arg(blocs);
	processes = full_tokenisation(blocs, n);
	infos = extract_infos(processes, n);
	if (parse_commands(infos, n, envp) == FALSE)
		return (full_delete_minishell(blocs, processes, infos, n));
	pipex(infos, n, envp);
	full_delete_minishell(blocs, processes, infos, n);
}
