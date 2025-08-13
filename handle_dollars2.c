/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dollars2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:42:05 by lionelulm         #+#    #+#             */
/*   Updated: 2025/08/13 18:03:27 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
	while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
		i++;
	return (i);
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

int	fill_str(char *dst, char *src, char **envp, int i)
{
	int		j;
	int		len;
	char	*var;

	j = 0;
	while (src[i])
	{
		if (src[i] == '$' && src[i + 1]
			&& (ft_isalpha(src[i + 1]) || src[i + 1] == '_'))
		{
			i++;
			len = var_name_len(&src[i]);
			var = ft_substr(src, i, len);
			if (!var)
				return (-1);
			j += copy_var_value(&dst[j], var, envp);
			free(var);
			i += len;
		}
		else
			dst[j++] = src[i++];
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
	final_len = get_final_length(str, envp);
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

//int	main(int ac, char **av, char **envp)
//{
//	char	*input = "$? Coucou $USER blah $JEXISTEPAS blah $HOME! $?";
//	char	*expanded;

//	(void)ac;
//	(void)av;
//	expanded = dollar_signs(input, 2, envp);
//	if (expanded)
//	{
//		printf("%s\n", expanded);
//		free(expanded);
//	}
//	return (0);
//}
