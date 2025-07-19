/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_useless_spaces.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 21:49:33 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/07/19 23:03:11 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	len_new_str(char *s, char *c)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (s[i] != 0)
	{
		while (s[i] && ft_iswhitespace(s[i]) == FALSE)
		{
			len++;
			i++;
		}
		if (s[i] == 0)
			return (len);
		while (ft_iswhitespace(s[i]) == 1 && ((ft_ischarinset(s[i - 1], c) == 1)
				|| (s[i + 1] != 0 && ft_ischarinset(s[i + 1], c) == TRUE)))
			i++;
		if (ft_iswhitespace(s[i]) == TRUE
			&& s[i + 1] != 0 && ft_ischarinset(s[i + 1], c) == FALSE)
		{
			i++;
			len++;
		}
	}
	return (len);
}

char	*fill_new_str(char *str, char *new_str, char *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != 0)
	{
		while (str[i] && ft_iswhitespace(str[i]) == FALSE)
			new_str[j++] = str[i++];
		if (str[i] == 0)
			return (new_str);
		while (ft_iswhitespace(str[i]) == TRUE
			&& ((str[i + 1] != 0 && ft_ischarinset(str[i + 1], set) == TRUE)
				|| ft_ischarinset(str[i - 1], set) == TRUE))
			i++;
		if (ft_iswhitespace(str[i]) == TRUE
			&& str[i + 1] != 0 && ft_ischarinset(str[i + 1], set) == FALSE)
			new_str[j++] = str[i++];
	}
	new_str[j] = 0;
	return (new_str);
}

char	*delete_useless_spaces(char	*str, char *set)
{
	char	*new_str;

	str = ft_strtrim(str, WHITESPACES);
	if (str == NULL || str[0] == 0 || set == NULL)
		return (str);
	new_str = malloc(sizeof(char) * len_new_str(str, set) + 1);
	new_str = fill_new_str(str, new_str, set);
	free(str);
	return (new_str);
}

// int    main(void)
// {
//     //tests
//     char	**str;
// 	char	*str2;

//     str = malloc(sizeof(char *) * 3);

//     str[0] = ft_strdup("cmd<infile>outfile");
//     str[1] = ft_strdup("cmd-a arg arg arg < infile > outfile");
//     str[2] = NULL;
//     int i = 0;
//     while (str[i] != NULL)
//     {
// 		str2 = delete_useless_spaces(str[i], "<>-");
// 		printf("%s\n%s\n\n", str[i], str2);
// 		free(str2);
// 		free(str[i]);
// 		i++;
//     }
//     free(str);
// }