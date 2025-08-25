/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dollars2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:42:05 by lionelulm         #+#    #+#             */
/*   Updated: 2025/08/25 16:13:17 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*check_env_value(char *str, char **envp)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	while (envp[i])
	{
		if (ft_strncmp(envp[i], str, len) == 0 && envp[i][len] == '=')
			return (envp[i] + len + 1);
		i++;
	}
	return (NULL);
}

int	var_name_len(char *str)
{
	int	i;

	i = 0;
	if (!str || !(ft_isalpha(str[0]) || str[0] == '_'))
		return (0);
	while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
		i++;
	return (i);
}

//int	fill_str(char *dst, char *src, char **envp, int i)
//{
//	int		j;
//	int		len;
//	char	*var;

//	j = 0;
//	while (src[i])
//	{
//		if (src[i] == '$' && src[i + 1]
//			&& (ft_isalpha(src[i + 1]) || src[i + 1] == '_'))
//		{
//			i++;
//			len = var_name_len(&src[i]);
//			var = ft_substr(src, i, len);
//			if (!var)
//				return (-1);
//			j += copy_var_value(&dst[j], var, envp);
//			free(var);
//			i += len;
//		}
//		else if (src[i] == '$' && ft_isdigit(src[i + 1]))
//			i += 2;
//		else
//			dst[j++] = src[i++];
//	}
//	dst[j] = '\0';
//	return (0);
//}
char	*fill_str2(char *dst, char *src, int *i, int *j)
{
	if (src[*i] == '$' && ft_isdigit(src[*i + 1]))
		*i = *i + 2;
	else
	{
		dst[*j] = src[*i];
		*j = *j + 1;
		*i = *i + 1;
	}
	return (dst);
}

int	fill_str(char *dst, char *src, char **envp, int i)
{
	int		j;
	int		len;
	char	*var;

	j = 0;
	len = 0;
	while (src[i])
	{
		if (src[i] == '$' && src[i + 1] && (ft_isalpha(src[i + 1])
				|| src[i + 1] == '_'))
		{
			len = var_name_len(&src[++i]);
			var = ft_substr(src, i, len);
			if (!var)
				return (-1);
			j += copy_var_value(&dst[j], var, envp);
			free(var);
			i += len;
		}
		dst = fill_str2(dst, src, &i, &j);
	}
	dst[j] = '\0';
	return (0);
}

char	*replace_dollar_var(char *str, char **envp)
{
	char	*result;
	int		final_len;
	int		i;

	i = 0;
	final_len = get_final_length(str, envp, 0, 0);
	if (final_len == -1)
		return (NULL);
	result = malloc(final_len + 1);
	if (!result)
		return (NULL);
	if (fill_str(result, str, envp, i) == -1)
	{
		free (result);
		return (NULL);
	}
	return (result);
}
