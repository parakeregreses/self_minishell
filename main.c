/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:14:26 by jlaineb           #+#    #+#             */
/*   Updated: 2025/07/29 17:34:37 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char 	*str = "cmd1 << jul | 'argu ments''lol' | cmd2 'bip|bap' | cmd3 < hello << les <<< is_infile.c arg3";
	t_exec	*info;
	int		n;
	t_arg	*tab;

	tab = parsing_minishell(str);
	int i = 0;
	n = tab_size_arg(tab);
	info = malloc(sizeof(t_exec) * n);
	while ((tab[i]).str != NULL)
	{
		ft_printf("%s\n", (tab[i]).str);
		info[i] = parse_bloc((tab[i]).str);
		i++;
		// ft_printf("str = %s, info.fdin = %d\n", (tab[i++]).str, info.fdin);
	}
	free(info);
	free_tab_arg(tab);
}
