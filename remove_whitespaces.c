/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whitespaces.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 16:43:54 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/07/30 17:21:39 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_iswhitespace(char c)
{
	if (c == 32 || (9 <= c && c <= 13))
		return (TRUE);
	return (FALSE);
}

int	count(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (ft_iswhitespace(str[i]))
		{
			i++;
			while (str[i] && ft_iswhitespace(str[i]))
			{
				i++;
				n++;
			}
		}
		if (str[i])
			i++;
	}
	ft_printf("n = %d\n", n);
	return (n);
}

char	*remove_whitespaces(char *str)
{
	int		i;
	int		y;
	int		whitespaces;
	char	*result;

	i = 0;
	y = 0;
	whitespaces = count(str);
	result = malloc(sizeof(char) * (ft_strlen(str) - whitespaces + 1));
	if (!result)
		return (NULL);
	while (str[i])
	{
		if (ft_iswhitespace(str[i]))
		{
			result[y] = ' ';
			y++;
			while (str[i] && ft_iswhitespace(str[i]))
				i++;
		}
		if (str[i])
			result[y++] = str[i++];
	}
	result[y] = 0;
	return (result);
}

// int    main(void)
// {
// 	char *str;

// 	str = remove_whitespaces("   hello   les   amis   ");
//     printf("%s\n", str);
// 	free(str);
// }