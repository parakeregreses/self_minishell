/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:01:19 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/15 17:43:17 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_builtin(t_exec info, char ***envp)
{
	if (strcmp(info.cmdpath, "cd") == 0)
		cmd_cd(info.cmdarg, *envp);
	if (strcmp(info.cmdpath, "echo") == 0)
		cmd_echo(info.cmdarg);
	if (strcmp(info.cmdpath, "env") == 0)
		ft_display_env(*envp);
	if (strcmp(info.cmdpath, "export") == 0)
		ft_export(envp, info.cmdarg[1]);
	if (strcmp(info.cmdpath, "pwd") == 0)
		cmd_pwd(*envp);
	if (strcmp(info.cmdpath, "unset") == 0)
		*envp = cmd_unset(envp, info.cmdarg[1]);
	// exit(EXIT_SUCCESS);
}

void	exec_builtin_exit(t_exec info, char ***envp)
{
	if (strcmp(info.cmdpath, "cd") == 0)
		cmd_cd(info.cmdarg, *envp);
	if (strcmp(info.cmdpath, "echo") == 0)
		cmd_echo(info.cmdarg);
	if (strcmp(info.cmdpath, "env") == 0)
		ft_display_env(*envp);
	if (strcmp(info.cmdpath, "export") == 0)
		ft_export(envp, info.cmdarg[1]);
	if (strcmp(info.cmdpath, "pwd") == 0)
		cmd_pwd(*envp);
	if (strcmp(info.cmdpath, "unset") == 0)
		*envp = cmd_unset(envp, info.cmdarg[1]);
	exit(EXIT_SUCCESS);
}
