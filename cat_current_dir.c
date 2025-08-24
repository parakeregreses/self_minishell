/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat_current_dir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:14:43 by liulm             #+#    #+#             */
/*   Updated: 2025/08/24 18:15:42 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*return_perror(void)
{
	perror("cd: getcwd");
	return (NULL);
}

char	*cat_current_dir(void)
{
	char	old_pwd[PATH_MAX];
	char	prompt[PATH_MAX + 20];
	char	*home;
	char	temp[PATH_MAX];
	size_t	home_len;

	temp[0] = 0;
	prompt[0] = 0;
	if (!getcwd(old_pwd, PATH_MAX))
		return_perror();
	home = getenv("HOME");
	home_len = ft_strlen(home);
	if (home && ft_strncmp(old_pwd, home, home_len) == 0)
	{
		ft_strlcpy(temp, "~", ft_strlen(temp) + 2);
		ft_strlcat(temp, old_pwd + home_len,
			ft_strlen(temp) + ft_strlen(old_pwd) + home_len + 1);
		ft_strlcpy(old_pwd, temp, ft_strlen(temp) + ft_strlen(temp));
	}
	ft_strlcpy(prompt, "minishell:", ft_strlen(prompt) + 11);
	ft_strlcat(prompt, old_pwd, ft_strlen(prompt) + ft_strlen(old_pwd) + 1);
	ft_strlcat(prompt, "$ ", ft_strlen(prompt) + 3);
	return (ft_strdup(prompt));
}
