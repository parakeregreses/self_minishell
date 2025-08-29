/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:01:19 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/29 18:58:09 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin(t_utils u, int piperead[2], int pipewrite[2], t_2d std)
{
	t_exec	info;

	info = u.infos[u.i];
	info.infile.fdin = find_fdin(info.infile, piperead, u.i);
	dup2(info.infile.fdin, 0);
	dup2(info.outfile.fdout, 1);
	if (!(info.infile.fdin == -1 || info.outfile.fdout == -1))
		exec_builtin(u, piperead, pipewrite, std);
	retrieve_std(std.in, std.out);
	std.in = dup(0);
	std.out = dup(1);
}

void	exec_builtin(t_utils u, int pipe1[2], int pipe2[2], t_2d std)
{
	char	*cmd;
	char	**args;

	cmd = u.infos[u.i].cmdpath;
	args = u.infos[u.i].cmdarg;
	if (ft_strcmp(cmd, "cd") == 0 && u.n == 1)
		cmd_cd(args, u.envp, u.status);
	if (ft_strcmp(cmd, "echo") == 0)
		cmd_echo(args, u.status);
	if (ft_strcmp(cmd, "env") == 0)
		cmd_env(*(u.envp), u.status);
	if (ft_strcmp(cmd, "export") == 0)
		cmd_export(u.envp, args, u.status, u.n);
	if (ft_strcmp(cmd, "pwd") == 0)
		cmd_pwd(*(u.envp), u.status);
	if (ft_strcmp(cmd, "unset") == 0 && u.n == 1)
		cmd_unset(u.envp, args, u.status);
	if (ft_strcmp(cmd, "exit") == 0 && u.n == 1)
		cmd_exit(u, pipe1, pipe2, std);
}
