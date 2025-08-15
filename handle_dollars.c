/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dollars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:38:49 by lionelulm         #+#    #+#             */
/*   Updated: 2025/08/15 21:01:42 by jlaine-b         ###   ########.fr       */
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
		if (str[i] == '\'')
		{
			i = close_quote(str, i, str[i]);
			i++;
		}
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
			i++;
		}
		if (str[i] == '$' && str[i + 1] == '?')
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
		if (str[i++] == '\'')
		{
			while (str[i] && str[i] != '\'')
				result[j++] = str[i++];
			i++;
		}
		if (str[i] == '$' && str[i + 1] == '?')
		{
			k = 0;
			while (var_str[k])
				result[j++] = var_str[k++];
			i += 2;
		}
		else
			result[j++] = str[i++];
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

	tmp = replace_dollar_mark(str, var);
	if (!tmp)
		return (NULL);
	final = replace_dollar_var(tmp, envp);
	free(tmp);
	return (final);
}

// int main()
// {
// 	char *result;

// 	result = replace_dollar_mark("te$?st", 254);
// 	printf("%s", result);
// }

// Faire une fonction qui prend en entree une string et un int
// parcours la string
// quand elle trouve un $ :
// si il est suivi du nom d'une variable d'environnement, tu remplaces pas
// "valeur de la variable"
// si il est suivi du ?, tu remplaces par le int (faut faire atoi dessus)
