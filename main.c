/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:14:26 by jlaineb           #+#    #+#             */
/*   Updated: 2025/07/30 19:02:57 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char 	*str = "cmd1 << jul | 'argu ments''lol' | cmd2 'bip|bap' | cmd3 < hello << les << is_infile.c arg3";
	t_exec	*infos;
	int		n;
	t_arg	*blocs;
	char	***processes;

	blocs = blocisation(str);
	if (blocs == NULL)
		return (0);
	n = tab_size_arg(blocs);
	processes = full_tokenisation(blocs, n);
				int i = 0;
				while (processes[i] != NULL)
				{
					print_tab_char(processes[i]);
					ft_printf("\n");
					i++;
				}
	infos = parsing_processes(processes, n);
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
	free_tab_arg(blocs);
}
