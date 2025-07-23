/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_bloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 20:40:28 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/07/23 21:24:51 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**allow_tab(char *str, char *set)
{
	int	i;
	int	ntoken;

	i = 0;
	ntoken = 1;
	while (str[i])
	{
		if (ft_ischarinset(str[i], set) == TRUE)
		{
			ntoken++;
			if (str[i] == str[i + 1])
				i++;
		}
		i++;
	}
	printf("n = %d\n", ntoken);
	return (malloc (sizeof(char *) * ntoken + 1));
}

int	main(void)
{
	allow_tab("hello<les<<lim>amis arg", "<>- ");
}

// char	**token_bloc(char *str)
// {
// 	char	**tab;

// 	str = ft_strtrim(str, WHITESPACES);
// 	str = delete_useless_spaces(str, "<>-");
// 	tab = allow_tab(str, "<>-");
// }