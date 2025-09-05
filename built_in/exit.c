/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 17:52:56 by liulm             #+#    #+#             */
/*   Updated: 2025/09/05 20:17:25 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_exit(t_utils u, int pipe1[2], int pipe2[2], t_2d std)
{
	char	**args;
	int		count;

	args = u.infos[u.i].cmdarg;
	count = count_args(args);
	write(2, "exit\n", 5);
	if (count > 2)
	{
		write(2, "minishell: exit: too many arguments\n", 36);
		*(u.status) = 1;
		return ;
	}
	retrieve_std(std.in, std.out);
	close_pipes(pipe1, pipe2);
	free_tab((void **)*(u.envp));
	return (cmd_exit2(count, u.status, args, u));
}

void	cmd_exit2(int count, int *status, char **args, t_utils u)
{
	long	exit_val;

	if (count == 1)
	{
		full_delete_minishell(u.infos, u.n);
		*status = 0;
		exit(*status);
	}
	if (!is_numeric(args[1]))
	{
		numeric_argument_required(args);
		full_delete_minishell(u.infos, u.n);
		*status = 2;
		exit(*status);
	}
	exit_val = ft_atol(args[1]);
	full_delete_minishell(u.infos, u.n);
	*status = exit_val % 256;
	exit(*status);
}
