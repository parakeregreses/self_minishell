/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_without_quotes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:16:54 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/07/29 17:23:04 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int    count_quotes(char *str)
{
    int        count;
    char    c;
    int        i;

    count = 0;
    i = 0;
    while (str[i])
    {
        if (str[i] == '"' || str[i] == '\'')
        {
            c = str[i];
            i++;
            count++;
            while (str[i] != c && str[i])
                i++;
            if (str[i] == c)
                count++;
        }
        i++;
    }
    return (count);
}

static char    *remove_quotes(char *str, char *result, int i, int y)
{
    char    c;

    while (str[i])
    {
        if (str[i] == '"' || str[i] == '\'')
        {
            c = str[i];
            i++;
            while (str[i] != c)
            {
                result[y] = str[i];
                y++;
                i++;
            }
        }
        else
        {
            result[y] = str[i];
            y++;
        }
        i++;
    }
    return (result);
}
char    *str_without_quotes(char *str)
{
    int        i;
    int        y;
    int        quotes;
    char    *result;

    i = 0;
    y = 0;
    quotes = count_quotes(str);
    result = NULL;
    result = malloc(sizeof(char) * (ft_strlen(str) - quotes) + 1);
    if (!result)
        return (NULL);
    result = remove_quotes(str, result, i, y);
    return (result);
}

// int    main(void)
// {
// 	char *str;

// 	str = str_without_quotes("\"te\"s\"t\"");
//     printf("%s, %s\n", "\"te\"s\"t\"", str);
// 	str = str_without_quotes("\"te'st\"");
//     printf("%s, %s\n", "\"te'st\"", str);
// 	str = str_without_quotes("\"te\'s\'t\"");
//     printf("%s, %s\n", "\"te\'s\'t\"", str);
// 	str = str_without_quotes("\"te\"s\"t\"");
//     printf("%s, %s\n", "\"te\"s\"t\"", str);
// 	str = str_without_quotes("\'\"\'\"t\"\'\"\'");
//     printf("%s, %s\n", "\'\"\'\"t\"\'\"\'", str);
// }
