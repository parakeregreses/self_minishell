/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:42:31 by lionelulm         #+#    #+#             */
/*   Updated: 2025/08/25 16:50:58 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	copy_old_pwd(char *old_pwd)
{
	if (!getcwd(old_pwd, PATH_MAX))
	{
		perror("cd: getcwd");
		return (1);
	}
	return (0);
}

static char	*find_target(char **arg, char **envp)
{
	char	*home;
	char	*old_pwd;

	home = ft_getenv("HOME", envp);
	old_pwd = ft_getenv("OLDPWD", envp);
	if (!arg[1] || ft_strcmp((char *)arg[1], "~") == 0)
	{
		if (!home)
			ft_putstr_fd("cd: HOME not set\n", 2);
		return (home);
	}
	else if (ft_strcmp((char *)arg[1], "-") == 0)
	{
		if (!old_pwd)
			ft_putstr_fd("cd: OLDPWD not set\n", 2);
		else
			ft_putendl_fd(old_pwd, 1);
		return (old_pwd);
	}
	return (arg[1]);
}

static int	change_directory(const char *dir)
{
	if (chdir(dir) != 0)
	{
		ft_putstr_fd("cd: ", 2);
		perror(dir);
		return (1);
	}
	return (0);
}

static int	update_env(char ***envp, char *old_pwd)
{
	char	new_pwd[PATH_MAX];
	char	*old_pwd_var;
	char	*new_pwd_var;

	if (!getcwd(new_pwd, PATH_MAX))
	{
		ft_putstr_fd("cd: error retrieving current directory: getcwd: ", 2);
		perror("");
		return (1);
	}
	old_pwd_var = ft_strjoin("OLDPWD=", old_pwd);
	new_pwd_var = ft_strjoin("PWD=", new_pwd);
	if (old_pwd_var && new_pwd_var)
	{
		*envp = ft_add_in_env(*envp, old_pwd_var);
		*envp = ft_add_in_env(*envp, new_pwd_var);
	}
	free(old_pwd_var);
	free(new_pwd_var);
	return (0);
}

int	cmd_cd(char **arg, char ***envp, int *status)
{
	char	old_pwd[PATH_MAX];
	char	*dir;
	int		i;

	i = 0;
	while (arg[i])
		i++;
	if (i > 2)
	{
		ft_putstr_fd("cd: too many arguments\n", 2);
		return (*status = 1);
	}
	dir = find_target(arg, *envp);
	if (!dir)
		return (*status = 1);
	if (copy_old_pwd(old_pwd))
		return (*status = 1);
	if (change_directory(dir))
		return (*status = 1);
	if (update_env(envp, old_pwd))
		return (*status = 1);
	return (*status = 0);
}
