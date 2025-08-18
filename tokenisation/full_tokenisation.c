/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_tokenisation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:41:51 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/18 19:26:58 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// in each bloc, tokens the bloc (turns into a tab of the different elements)
char	***full_tokenisation(char **blocs, int n, int *status, char ***envp)
{
	int		i;
	char	*set;
	char	***processes;

	(void) status;
	(void) envp;

	set = ft_strdup("<> ");
	i = 0;
	processes = malloc(sizeof(char **) * (n + 1));
	while (blocs[i] != NULL)
	{
		processes[i] = token_bloc(blocs[i], set);
		// ft_printf("processesi\n");
		// print_tab_char(processes[i]);
		processes[i] = expand_dollar(processes[i], status, *envp);
		// ft_printf("processesi\n");
		// print_tab_char(processes[i]);
		processes[i] = tab_without_quotes(processes[i]);
		// ft_printf("processesi\n");
		// print_tab_char(processes[i]);
		i++;
	}
	free(set);
	processes[i] = NULL;
	return (processes);
}
