/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:42:48 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/07/29 15:45:29 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_quotes(char *arg)
{
	int		i;
	int		found;
	char	quote;

	i = 0;
	found = 0;
	while (arg[i])
	{
		if (arg[i] == '"' || arg[i] == '\'')
		{
			found = 1;
			quote = arg[i];
			i++;
			while (arg[i] != quote && arg[i])
				i++;
			if (arg[i] != quote)
				return (FALSE);
			found = 0;
		}
		i++;
	}
	// if (found == 1)
	// 	return (FALSE);
	return (TRUE);
}

int	main(void)
{
	printf("1, %d\n", check_quotes("hello"));
	printf("0, %d\n", check_quotes("hel'lo"));
	printf("1 %d\n", check_quotes("hel'l'o"));
	printf("0 %d\n", check_quotes("hel'l''o"));
	printf("1 %d\n", check_quotes("hel'l''o'"));
	printf("1 %d\n", check_quotes("h\"el'l\"o"));
	printf("0 %d\n", check_quotes("'mot\"1''mot2'\"mot3'\""));
}