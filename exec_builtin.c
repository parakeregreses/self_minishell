/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:01:19 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/13 15:36:18 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_builtin(t_exec info)
{
	if (strcmp(info.cmdpath, "cd") == 0)
		cmd_cd(info.cmdarg, info.envp);
	if (strcmp(info.cmdpath, "echo") == 0)
		cmd_echo(info.cmdarg);
	if (strcmp(info.cmdpath, "env") == 0)
		ft_display_env(info.envp);
	if (strcmp(info.cmdpath, "export") == 0)
		ft_export(info.envp, info.cmdarg[1]);
	if (strcmp(info.cmdpath, "pwd") == 0)
		cmd_pwd(info.envp);
	if (strcmp(info.cmdpath, "unset") == 0)
		cmd_unset(info.envp, info.cmdarg[1]);
	exit(EXIT_SUCCESS);
}