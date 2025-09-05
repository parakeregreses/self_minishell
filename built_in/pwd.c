/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 20:25:19 by liulm             #+#    #+#             */
/*   Updated: 2025/09/05 20:40:58 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_pwd(char *** envp, int *status)
{
	char	new_pwd[PATH_MAX];
	char	*pwd_secours;

	if (!getcwd(new_pwd, PATH_MAX))
	{
		pwd_secours = ft_getenv("PWD", *envp);
		if (pwd_secours)
		{
			ft_strlcpy(new_pwd, pwd_secours, PATH_MAX);
			printf("%s\n", new_pwd);
		}
		else
		{
			ft_putstr_fd("cd: error retrieving current directory: getcwd: ", 2);
			perror("");
			return ;
		}
	}
	else
		printf("%s\n", new_pwd);
	*status = 0;
}
