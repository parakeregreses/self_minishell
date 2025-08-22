/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blocisation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 10:16:59 by jlaineb           #+#    #+#             */
/*   Updated: 2025/08/22 17:37:58 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**blocisation2(char *str, int *status);

// separates the string in different blocs delimitated by the pipes
// such as bloc1 | bloc2 | bloc3
char	**blocisation(char *str, int *status)
{
	if (check_closed_quotes(str) == FALSE)
	{
		ft_printf("minishell: syntax problem: unclosed quotes\n");
		*status = 127;
		return (NULL);
	}
	str = revamp_str(str);
	if (first_verifications(str) == FALSE)
	{
		*status = 2;
		free(str);
		return (NULL);
	}
	return (blocisation2(str, status));
}

t_arg	*remove_whitespace_tab(t_arg *arg)
{
	int	i;

	i = 0;
	while ((arg[i]).str != NULL)
	{
		if ((arg[i]).quote == FALSE)
			(arg[i]).str = remove_whitespaces((arg[i]).str);
		i++;
	}
	return (arg);
}

char	*arg_to_str(t_arg *arg)
{
	int		i;
	char	*str;
	char	*new_str;

	i = 0;
	str = ft_strdup("");
	while ((arg[i]).str != NULL)
	{
		new_str = ft_strjoin(str, (arg[i++]).str);
		free(str);
		str = new_str;
	}
	return (str);
}

char	**separate_pipe2(t_arg *arg)
{
	char	*str;
	char	**tab;
	char	*set;

	str = arg_to_str(arg);
	set = ft_strdup("|");
	tab = token_bloc(str, set);
	free(str);
	free(set);
	return (tab);
}

char	**blocisation2(char *str, int *status)
{
	t_arg	*arg;
	char	**tab;

	arg = select_quoted_str(str);
	arg = remove_whitespace_tab(arg);
	if (arg == NULL)
	{
		*status = EXIT_FAILURE;
		return (NULL);
	}
	if (second_verifications(arg) == FALSE || third_verifications(str) == FALSE)
	{
		*status = 2;
		free(str);
		free_tab_arg(arg);
		return (NULL);
	}
	tab = separate_pipe2(arg);
	tab = trim_tab_free(tab, "|");
	free(str);
	free_tab_arg(arg);
	return (tab);
}
