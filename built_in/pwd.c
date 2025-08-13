/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 20:25:19 by liulm             #+#    #+#             */
/*   Updated: 2025/08/13 15:11:25 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	pwd_putstr(char *str)
{
	int	i;

	i = 4;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	cmd_pwd(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp("PWD", envp[i], 3) == 0)
			pwd_putstr(envp[i]);
		i++;
	}
}

//int	main(int argc, char **argv, char **envp)
//{
//	(void)argc;
//	(void)argv;
//	cmd_pwd(envp);
//}
