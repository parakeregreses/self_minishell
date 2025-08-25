/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dollars_helper.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:38:28 by liulm             #+#    #+#             */
/*   Updated: 2025/08/25 13:57:43 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	next_quote(char *str, int *i, int *len)
{
	*i = close_quote(str, *i, str[*i]);
	*i = *i + 1;
	*len = *len + *i;
}

//int	get_final_length(char *str, char **envp)
//{
//	int		len;
//	int		i;
//	int		vlen;
//	char	*var;
//	char	*val;

//	len = 0;
//	i = 0;
//	vlen = 0;
//	while (str[i])
//	{
//		if (str[i] == '\'')
//			next_quote(str, &i, &len);
//		else if (str[i] == '\\' && str[i + 1] == '$')
//		{
//			len++;
//			i += 2;
//		}
//		else if (str[i] == '$' && str[i + 1] && (ft_isalpha(str[i + 1])
//				|| str[i + 1] == '_'))
//		{
//			vlen = var_name_len(&str[++i]);
//			if (!(var = ft_substr(str, i, vlen)))
//				return (-1);
//			val = check_env_value(var, envp);
//			if (val)
//				len += ft_strlen(val);
//			free(var);
//			i += vlen;
//		}
//		else
//			(len++, i++);
//	}
//	return (len);
//}

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
		if (str[i] == '\'')
		{
			next_quote(str, &i, &len);
		}
		else if (str[i] == '\\' && str[i + 1] == '$')
		{
			len++;
			i += 2;
		}
		else if (str[i] == '$' && str[i + 1]
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
