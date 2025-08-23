/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 17:52:56 by liulm             #+#    #+#             */
/*   Updated: 2025/08/23 15:52:05 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_exit(char **args, char ***envp, int *status)
{
	(void) args;

	if (everything ok)
	{
		free_tab((void **)*envp);
		free(status);
		printf("exit\n");
		exit(EXIT_SUCCESS);
	}
}

void cmd_exit2(char **args, char ***envp, int *status)
{
	int	res;
	int	count_args;

	res = 0;
	count_args = 0;
	(void)status;
	(void)envp;
	while (args[count_args])
		count_args++;
	//printf("%d", count_args);
	if (count_args > 2)
	{
		printf("exit\n");
		printf("minishell: exit: too many arguments\n");
		*status = 1;
		return ;
	}
	else
	{
		res = ft_atoi(args[1]);
		res %= 256;
		//printf("%d", res);
	}
	*status = res;
	//free_and_print_exit(envp, args, status);
}
