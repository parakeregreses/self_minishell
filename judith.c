/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   judith.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:14:26 by jlaineb           #+#    #+#             */
/*   Updated: 2025/08/15 16:20:15 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	judith(char *str, char ***envp)
{
	t_exec	*infos;
	int		n;
	t_arg	*blocs;
	char	***processes;

	blocs = blocisation(str);
	if (blocs == NULL)
		return (0);
	n = tab_size_arg(blocs);
	processes = full_tokenisation(blocs, n);
	infos = extract_infos(processes, n, envp);
	if (parse_commands(infos, n, envp) == FALSE)
		return (full_delete_minishell(blocs, processes, infos, n));
	pipex(infos, n, envp);
	ft_printf("\n\n\n\n\n\n\n\n\n");
	print_tab_char(*envp);
	full_delete_minishell(blocs, processes, infos, n);
	return (0);
}

// int	main(int argc, char **argv, char **envp)
// {
// 	(void) argc;

// 	judith(argv[1], envp);
// }

//blocisation test
// int    main(void)
// {
//     char **str;
// 	t_arg	*blocs;

//     str = malloc(sizeof(char *) * 28);

//     str[0] = "";
//     str[1] = "\"\"";
//     str[2] = "mot";
//     str[3] = "\"quote\"";
//     str[4] = "\"quote\"mot";
//     str[5] = "\"quote1\"\"quote2\"mot";
//     str[6] = "mot\"quote\"";
//     str[7] = "mot\"quote1\"\"quote2\"";
//     str[8] = "mot1\"quote\"mot2";
//     str[9] = "\"quote1\"mot\"quote2\"";
//     str[10] = "hello";
//     str[11] = "\"|\"";
//     str[12] = "mot1|mot2";
//     str[13] = "\"quote1|quote1\"";
//     str[14] = "\"quote1|quote1\"|mot";
//     str[15] = "\"quote1|quote1\"|mot1|mot2";
//     str[16] = "\"quote1|quote1\"mot1|mot2";
//     str[17] = "\"quote1\"\"quote2|quote2\"|mot";
//     str[18] = "\"quote1\"|\"quote2|quote2\"|mot";
//     str[19] = "\"quote1\"|\"quote2|quote2\"mot";
//     str[20] = "\"quote1\"|mot|\"quote2|quote2\"";
//     str[21] = "\"quote1\"|mot1|mot2|\"quote2|quote2\"";
//     str[22] = "\"quote1\"mot1|mot2\"quote2|quote2\"";
//     str[23] = "\"quote1\"\"quote2|quote2\"mot1|mot2";
//     str[24] = "mot1|mot2|\"quote1\"\"quote2|quote2\"mot1|mot2";
//     str[25] = "mot1|mot2\"quote1\"\"quote2|quote2\"mot1|mot2";
//     str[26] = "'quote''quote''quote''quote''quote''quote'";
//     str[27] = NULL;
//     int i = 0;
//     while (str[i] != NULL)
//     {
// 		blocs = blocisation(str[i]);
// 		ft_printf("str = %s, blocs = \n", str[i]);
// 		print_tab_arg(blocs);
// 		ft_printf("\n");
// 		free_tab_arg(blocs);
// 		i++;
//     }
//     free(str);
// }
