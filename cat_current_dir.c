/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat_current_dir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:14:43 by liulm             #+#    #+#             */
/*   Updated: 2025/08/12 14:18:23 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
	{
		perror("cd: getcwd");
		return (NULL);
	}
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

// compter le nombre de caracteres dans la string SANS quotes. | quotes
// a enlever

// pour check les quotes :
//int    main(void)
//{
//	printf("1, %d\n", check_quotes("hello"));
//	printf("0, %d\n", check_quotes("hel'lo"));
//	printf("1, %d\n", check_quotes("hel'l'o"));
//	printf("0, %d\n", check_quotes("hel'l''o"));
//	printf("1, %d\n", check_quotes("hel'l''o'"));
//	printf("1, %d\n", check_quotes("h\"el'l\"o"));
//	printf("1, %d\n", check_quotes("\'mot\"1\'\'mot2\'\"mot3\'\""));
//	printf("0, %d\n", check_quotes("\"te\"s\"t\""));
//}

// pour check les strings sans quotes :

// int	main(void)
// {
// 	printf("%s\n", str_without_quotes("\"te\"s\"t\""));
// 	printf("%s\n", str_without_quotes("\"te'st\""));
// 	printf("%s\n", str_without_quotes("\"te\'s\'t\""));
// 	printf("%s\n", str_without_quotes("\"te\"s\"t\""));
// 	printf("%s\n", str_without_quotes("\'\"\'\"t\"\'\"\'"));
// }
