/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dollars_helper.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:38:28 by liulm             #+#    #+#             */
/*   Updated: 2025/08/25 14:47:30 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_final_length(char *str, char **envp)
{
	int		len;
	int		i;
	int		vlen;
	char	*var;
	char	*val;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1]
			&& (ft_isalpha(str[i + 1]) || str[i + 1] == '_'))
		{
			i++;
			vlen = var_name_len(&str[i]);
			var = ft_substr(str, i, vlen);
			if (!var)
				return (-1);
			val = check_env_value(var, envp);
			if (val)
				len += ft_strlen(val);
			free(var);
			i += vlen;
		}
		else
		{
			len++;
			i++;
		}
	}
	return (len);
}

static int	handle_dollar(char *res, char *var, int j)
{
	int	i;

	i = 0;
	while (var[i])
		res[j++] = var[i++];
	return (j);
}

void	dollar_helper(char *res, char *str, char *var)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1] == '?')
		{
			j = handle_dollar(res, var, j);
			i += 2;
		}
		else
			res[j++] = str[i++];
	}
	res[j] = '\0';
}
