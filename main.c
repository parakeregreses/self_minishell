/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:14:26 by jlaineb           #+#    #+#             */
/*   Updated: 2025/07/29 16:17:43 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char 	*str = "cmd1 < jul | 'argu ments''lol' | cmd2 'bip|bap' | cmd3 < hello < les < is_infile.c arg3";
	t_exec	*info;
	int		n;
	t_arg	*tab;

	tab = parsing_minishell(str);
	int i = 0;
	n = tab_size_arg(tab);
	info = malloc(sizeof(t_exec) * n);
	while ((tab[i]).str != NULL)
	{
		info[i] = parse_bloc((tab[i]).str);
		i++;
		// ft_printf("str = %s, info.fdin = %d\n", (tab[i++]).str, info.fdin);
	}
	free_tab_arg(tab);
}

// int	main(void)
// {
// 	//tests
// 	char **str;
// 	t_arg	*tab;

// 	str = malloc(sizeof(char *) * 28);

// 	str[0] = "";
// 	str[1] = "\"\"";
// 	str[2] = "mot";
// 	str[3] = "\"quote\"";
// 	str[4] = "\"quote\"mot";
// 	str[5] = "\"quote1\"\"quote2\"mot";
// 	str[6] = "mot\"quote\"";
// 	str[7] = "mot\"quote1\"\"quote2\"";
// 	str[8] = "mot1\"quote\"mot2";
// 	str[9] = "\"quote1\"mot\"quote2\"";
// 	str[10] = "hello";
// 	str[11] = "\"|\"";
// 	str[12] = "mot1|mot2";
// 	str[13] = "\"quote1|quote1\"";
// 	str[14] = "\"quote1|quote1\"|mot";
// 	str[15] = "\"quote1|quote1\"|mot1|mot2";
// 	str[16] = "\"quote1|quote1\"mot1|mot2";
// 	str[17] = "\"quote1\"\"quote2|quote2\"|mot";
// 	str[18] = "\"quote1\"|\"quote2|quote2\"|mot";
// 	str[19] = "\"quote1\"|\"quote2|quote2\"mot";
// 	str[20] = "\"quote1\"|mot|\"quote2|quote2\"";
// 	str[21] = "\"quote1\"|mot1|mot2|\"quote2|quote2\"";
// 	str[22] = "\"quote1\"mot1|mot2\"quote2|quote2\"";
// 	str[23] = "\"quote1\"\"quote2|quote2\"mot1|mot2";
// 	str[24] = "mot1|mot2|\"quote1\"\"quote2|quote2\"mot1|mot2";
// 	str[25] = "mot1|mot2\"quote1\"\"quote2|quote2\"mot1|mot2";
// 	str[26] = "'quote''quote''quote''quote''quote''quote'";
// 	str[27] = NULL;
// 	int i = 0;
// 	while (str[i] != NULL)
// 	{
// 		tab = parsing_minishell(str[i]);
// 		ft_printf("str[%d] =%s\ntab =\n", i, str[i]);
// 		print_tab_arg(tab);
// 		free_tab_arg(tab);
// 		i++;
// 	}
// 	free(str);
// }