/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:01:19 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/26 16:28:58 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_builtin(t_utils u, int pipe1[2], int pipe2[2], t_2d std)
{
	char	*cmd;
	char	**args;

	cmd = u.infos[u.i].cmdpath;
	args = u.infos[u.i].cmdarg;
	if (strcmp(cmd, "cd") == 0 && u.i == 0 && u.n == 1)
		cmd_cd(args, u.envp, u.status);
	if (strcmp(cmd, "echo") == 0)
		cmd_echo(args, u.status);
	if (strcmp(cmd, "env") == 0)
		cmd_env(*(u.envp), u.status);
	if (strcmp(cmd, "export") == 0)
		cmd_export(u.envp, args, u.status, u.i - u.n - 1);
	if (strcmp(cmd, "pwd") == 0)
		cmd_pwd(*(u.envp), u.status);
	if (strcmp(cmd, "unset") == 0 && u.i == 0 && u.n == 1)
		cmd_unset(u.envp, args[1], u.status);
	if (strcmp(cmd, "exit") == 0 && u.i == 0 && u.n == 1)
		cmd_exit(u, pipe1, pipe2, std);
}
