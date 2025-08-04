/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:14:26 by jlaineb           #+#    #+#             */
/*   Updated: 2025/08/04 16:49:25 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char 	*str = "cmd1 < jul | bazar | 'argu ments''lol' | cmd2 'bip|bap' | cmd3 < triple_char.c arg3";
	t_exec	*infos;
	int		n;
	t_arg	*blocs;
	char	***processes;
	int		i;

	(void) argc;
	(void) argv;

	blocs = blocisation(str);
	if (blocs == NULL)
		return (0);
	n = tab_size_arg(blocs);
	processes = full_tokenisation(blocs, n);
	// 			i = 0;
	// 			while (processes[i] != NULL)
	// 			{
	// 				print_tab_char(processes[i]);
	// 				ft_printf("\n");
	// 				i++;
	// 			}
	infos = parsing_processes(processes, n);
	i = 0;
	while (i < n)
	{
		ft_printf("i = %d, fdin = %d, fdout = %d, cmd = %s, cmdarg = \n", i, (infos[i]).infile.fdin, (infos[i]).fdout, (infos[i]).cmdarg[0]);
		print_tab_char((infos[i]).cmdarg);
		ft_printf("\n");
		i++;
	}
	if (parse_commands(infos, n, envp) == FALSE)
		return (0);
	// int i = 0;
	// n = tab_size_arg(tab);
	// info = malloc(sizeof(t_exec) * n);
	// while ((tab[i]).str != NULL)
	// {
	// 	ft_printf("%s\n", (tab[i]).str);
	// 	info[i] = parse_bloc((tab[i]).str);
	// 	i++;
	// 	// ft_printf("str = %s, info.fdin = %d\n", (tab[i++]).str, info.fdin);
	// }
	// free(info);
	// free(str);
	pipex(infos, n, envp);
	free_tab_arg(blocs);
				i = 0;
				while (processes[i] != NULL)
				{
					free_tab((void **)processes[i]);
					free_tab((void **)(infos[i]).cmdarg);
					i++;
				}
	free(processes);
	free(infos);
}
