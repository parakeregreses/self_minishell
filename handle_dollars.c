/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dollars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:38:49 by lionelulm         #+#    #+#             */
/*   Updated: 2025/08/25 13:57:56 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_new_length(char *str, char *var_str)
{
	int		i;
	int		len;
	int		var_len;

	i = 0;
	len = 0;
	var_len = ft_strlen(var_str);
	while (str[i])
	{
		if (str[i] == '\'')
		{
			i = close_quote(str, i, str[i]);
			len += i;
			i++;
		}
		else if (str[i] == '\\' && str[i + 1] == '$' && str[i + 2] == '?')
		{
			len += 2;
			i += 3;
		}
		else if (str[i] == '$' && str[i + 1] == '?')
		{
			len += var_len;
			i += 2;
		}
		else
		{
			len++;
			i++;
		}
	}
	return (len);
}

void	dollar_helper(char *result, char *str, char *var_str)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\'')
		{
			result[j++] = str[i++];
			while (str[i] && str[i] != '\'')
				result[j++] = str[i++];
			result[j++] = str[i++];
		}
		else if (str[i] == '\\' && str[i + 1] == '$' && str[i + 2] == '?')
		{
			result[j++] = '$';
			result[j++] = '?';
			i += 3;
		}
		else if (str[i] == '$' && str[i + 1] == '?')
		{
			k = 0;
			while (var_str[k])
				result[j++] = var_str[k++];
			i += 2;
		}
		else
		{
			result[j++] = str[i++];
		}
	}
	result[j] = '\0';
}

char	*replace_dollar_mark(char *str, int var)
{
	char	*result;
	char	*var_str;

	var_str = ft_itoa(var);
	if (!var_str)
		return (NULL);
	result = malloc(sizeof(char) * (count_new_length(str, var_str) + 1));
	if (!result)
		return (NULL);
	dollar_helper(result, str, var_str);
	free(var_str);
	return (result);
}

char	*dollar_signs(char *str, int var, char **envp)
{
	char	*tmp;
	char	*final;

	if (str[0] == '$' && str[1] == 0)
	{
		free(str);
		return (ft_strdup(""));
	}
	tmp = replace_dollar_mark(str, var);
	if (!tmp)
		return (NULL);
	final = replace_dollar_var(tmp, envp);
	free(tmp);
	free(str);
	return (final);
}
