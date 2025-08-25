/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dollars_helper.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:38:28 by liulm             #+#    #+#             */
/*   Updated: 2025/08/25 16:13:32 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_final_length(char *str, char **envp, int i, int len)
{
	int		vlen;
	char	*var;
	char	*val;

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
			ft_increase(&len, &i);
	}
	return (len);
}

int	copy_var_value(char *dst, char *var_name, char **envp)
{
	char	*value;
	int		len;

	value = check_env_value(var_name, envp);
	if (!value)
		return (0);
	len = ft_strlen(value);
	ft_strlcpy(dst, value, len + 1);
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
