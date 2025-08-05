/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:14:26 by jlaineb           #+#    #+#             */
/*   Updated: 2025/08/05 13:24:12 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	// char 	*str = "cmd1 < jul | bazar | 'argu ments''lol' | cmd2 'bip|bap' | cmd3 < triple_char.c arg3";
	char	*str = "cmd1 < note.txt << lim1 < noexist1 | cmd2 < note.txt << lim2 | cmd3 < no_exist3 << lim3 | cmd4 << lim4 < note.txt | cmd5 << lim51 << lim52 | cmd6 << lim6 < no_exist6 < note.txt | cmd7 < note.txt << lim7 < noexist7";
	t_exec	*infos;
	int		n;
	t_arg	*blocs;
	char	***processes;

	(void) argc;
	(void) argv;

	blocs = blocisation(str);
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
