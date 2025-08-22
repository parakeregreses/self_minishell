/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:01:19 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/22 18:03:36 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_builtin(t_exec info, char ***envp, int *status)
{
	// ft_printf("info.cmdarg = \n");
	// print_tab_char(info.cmdarg);
	if (strcmp(info.cmdpath, "cd") == 0)
		cmd_cd(info.cmdarg, envp, status);
	if (strcmp(info.cmdpath, "echo") == 0)
		cmd_echo(info.cmdarg, status);
	if (strcmp(info.cmdpath, "env") == 0)
		cmd_env(*envp, status);
	if (strcmp(info.cmdpath, "export") == 0)
		cmd_export(envp, info.cmdarg[1], status);
	if (strcmp(info.cmdpath, "pwd") == 0)
		cmd_pwd(*envp, status);
	if (strcmp(info.cmdpath, "unset") == 0)
		*envp = cmd_unset(envp, info.cmdarg[1], status);
	//if (strcmp(info.cmdpath, "exit") == 0)
	//	cmd_exit(info.cmdarg, envp, status);
}

//void	exec_builtin_exit(t_exec info, char ***envp, int *status)
//{
//	if (strcmp(info.cmdpath, "cd") == 0)
//		cmd_cd(info.cmdarg, envp, status);
//	if (strcmp(info.cmdpath, "echo") == 0)
//		cmd_echo(info.cmdarg, status);
//	if (strcmp(info.cmdpath, "env") == 0)
//		cmd_env(*envp, status);
//	if (strcmp(info.cmdpath, "export") == 0)
//		cmd_export(envp, info.cmdarg[1], status);
//	if (strcmp(info.cmdpath, "pwd") == 0)
//		cmd_pwd(*envp, status);
//	if (strcmp(info.cmdpath, "unset") == 0)
//		*envp = cmd_unset(envp, info.cmdarg[1], status);
//	exit(*status);
//}
