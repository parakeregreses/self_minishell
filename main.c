/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:14:26 by jlaineb           #+#    #+#             */
/*   Updated: 2025/07/06 18:36:06 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	// char 	*str = "cmd<infile|cmd|\'1|2\'\'|1|2\'bonjour|a|tous\"les|amiiis\"bienvenue|a|\'l|ecole|42\'arg|cmd|END";
	// char 	*str = "c\"md\"<i\"nfi\"le\"2\"|cmd|\'1|2|1|2\'bonjour|a|tous\"les|amiiis\"bienvenue|a|\'l|ecole|42\'arg|cmd|\"c\"md\"<i\"nfi\"le\"2\"END";
	t_exec	info;
	char 	*str = "cmd1 << jul | 'argu ments''lol' | cmd2 'bip|bap' | cmd3 < is_infile.c arg3";
	
	t_arg	*tab;
	tab = parsing_minishell(str);
	// ft_printf("str = %s. tab = \n", str);
	// print_tab_arg(tab);
	int i = 0;
	while ((tab[i]).str != NULL)
	{
		info = parse_bloc((tab[i++]).str);
		ft_printf("info.fdin = %d\n", info.fdin);
	}
	free_tab_arg(tab);
// }
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
// 	str[11] = "\"|\""; // issue
// 	str[12] = "mot1|mot2";
// 	str[13] = "\"quote1|quote1\"";
// 	str[14] = "\"quote1|quote1\"|mot";
// 	str[15] = "\"quote1|quote1\"|mot1|mot2";
// 	str[16] = "\"quote1|quote1\"mot1|mot2";
// 	str[17] = "\"quote1\"\"quote2|quote2\"|mot";
// 	str[18] = "\"quote1\"|\"quote2|quote2\"|mot";
// 	str[19] = "\"quote1\"|\"quote2|quote2\"mot";
// 	str[20] = "\"quote1\"|mot|\"quote2|quote2\"";
// 	str[21] = "\"quote1\"|mot1|mot2|\"quote2|quote2\""; // issue
// 	str[22] = "\"quote1\"mot1|mot2\"quote2|quote2\"";
// 	str[23] = "\"quote1\"\"quote2|quote2\"mot1|mot2";
// 	str[24] = "mot1|mot2|\"quote1\"\"quote2|quote2\"mot1|mot2"; // issue
// 	str[25] = "mot1|mot2\"quote1\"\"quote2|quote2\"mot1|mot2";
// 	str[26] = "'quote''quote''quote''quote''quote''quote'";
// 	str[27] = NULL;
// 	int i = 0;
// 	while (str[i] != NULL)
// 	{
// 		tab = parsing_minishell(str[i]);
// 		ft_printf("str[%d] = %s\ntab =\n", i, str[i]);
// 		print_tab_arg(tab);
// 		free_tab_arg(tab);
// 		i++;
// 	}
// 	free(str);
// }