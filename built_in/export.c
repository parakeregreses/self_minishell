/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   export.c										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: liulm <liulm@student.42.fr>				+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/05/21 16:37:42 by liulm			 #+#	#+#			 */
/*   Updated: 2025/05/26 17:33:22 by liulm			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "minishell.h"

void	ft_print_export(char *env)
{
	int	i;

	i = 0;
	while (env[i] && env[i] != '=')
		i++;
	if (env[i] == '=')
	{
		printf("declare -x %.*s=\"%s\"\n", i, env, env + i + 1);
	}
	else
	{
		printf("declare -x %s\n", env);
	}
}

int	ft_replace_export_if_found(char **envp, char *env_variable)
{
	int	i;

	i = 0;
	while (envp && envp[i])
	{
		if (ft_strcmp(envp[i], env_variable) == 0)
			return (1);
		i++;
	}
	return (0);
}

char	**export_alphabetical_order(char **envp)
{
	int		count;
	int		i;
	char	**result;

	count = 0;
	while (envp && envp[count])
		count++;
	result = (char **)malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < count)
	{
		result[i] = ft_strdup(envp[i]);
		i++;
	}
	result[i] = NULL;
	swap_variables(result, count);
	return (result);
}

char	**ft_add_in_export(char **envp, char *new_env_variable)
{
	int		i;
	int		j;
	char	**new_export;
	//char	**sorted;

	i = 0;
	if (!new_env_variable || !new_env_variable[0])
		return (envp);
	if (ft_replace_export_if_found(envp, new_env_variable))
		return (envp);
	while (envp && envp[i])
		i++;
	new_export = malloc(sizeof(char *) * (i + 2));
	if (!new_export)
		return (envp);
	j = 0;
	while (j < i)
	{
		new_export[j] = ft_strdup(envp[j]);
		j++;
	}
	new_export[j] = ft_strdup(new_env_variable);
	new_export[j + 1] = NULL;
	//sorted = export_alphabetical_order(new_export);
	//free_envp(new_export);
	return (new_export);
}

//char	**ft_export2(char ***envp, char *new_env_variable)
//{
//	char	**new_env;
//	//char	**new_export;

//	new_env = NULL;
//	if (env_var_checker(*envp, new_env_variable) == 1)
//		return (NULL);
//	//new_export = *envp;
//	if (ft_strchr(new_env_variable, '='))
//	{
//		new_env = ft_add_in_env(*envp, new_env_variable);
//		//free_envp(new_export);
//		//free(*envp);
//		*envp = new_env;
//		return (new_env);
//	}
//	else
//	{
//		*envp = ft_add_in_export(*envp, new_env_variable);
//		//free(*envp);
//		//*envp = new_export;
//		return (*envp);
//	}
//	return (*envp);
//}

char	**ft_export(char ***envp, char *new_env_variable)
{
	char	**new_env;

	if (env_var_checker(*envp, new_env_variable) == 1)
		return (NULL);
	new_env = ft_add_in_export(*envp, new_env_variable);
	free_tab((void **)*envp);
	*envp = new_env;
	return (new_env);
}

//int main(int argc, char **argv, char **envp)
//{
//	(void)argc;
//	(void)argv;
//	char **new_envp = NULL;

	//ft_display_env(envp);
	//printf("\n\n");
	//new_envp = ft_export(envp, "TEST=0");
	//printf("\n\n");
	//new_envp = ft_export(envp, "TEST");
	//printf("\n\n");
	//ft_export(envp, "TE?ST=0");
	//printf("\n\n");
	//ft_export(envp, "1TEST=0");
	//printf("\n\n");
	//ft_export(envp, NULL);
	//printf("\n\n");
	//ft_export(envp, NULL);
//	if (new_envp && new_envp != envp)
//		free_envp(new_envp);
//	return (0);
//}

/* ranger les arguments dans l'ordre alphabetique */
/*gerer majuscules et minuscules, chiffres au debut marchent pas*/

// celles-ci sont valides:

// TEST
// _TEST (les '_' marchent)
// Test123
// TEST_VAR (les '_' marchent)

// celles-ci sont invalides:

// 1TEST (commencer par un chiffre)
// TE?ST (contient un caractère spécial)
// -TEST (commence par un caractère spécial)
// TEST-VAR (contient un caractère spécial)

// la variable "_" ne s'unset jamais, elle reste

//char	**ft_export(char **envp, char *new_env_variable)
//{
//	int		i;
//	char	**new_env;
//	char	**new_export;

//	i = 0;
//	new_env = NULL;
//	new_export = ft_copy_env(envp);
//	//g_finished = 0;
//	if (env_var_checker(envp, new_env_variable) == 1)
//		return (NULL);
//	if (ft_strchr(new_env_variable, '='))
//	{
//		new_env = ft_add_in_env(envp, new_env_variable);
//		new_export = ft_add_in_export(envp, new_env_variable);
//		/*TEST A ENLEVER*/
//		ft_display_env(new_env);
//		printf("\n\n\n");
//		int j = 0;
//		while (new_export[j])
//		{
//			ft_print_export(new_export[j]);
//			j++;
//		}
//		/*TEST A ENLEVER*/
//		return (new_env);
//	}
//	else
//	{
//		new_export = ft_add_in_export(envp, new_env_variable);
//		/*TESTS POUR VOIR SI CA L'A BIEN ADD*/
//		new_export = ft_add_in_export(envp, new_env_variable);
//		new_export = export_alphabetical_order(new_export);
//		i = 0;
//		while (new_export[i])
//		{
//			ft_print_export(new_export[i]);
//			i++;
//		}
//		printf("\n\n\n");
//		ft_display_env(envp);
//		/*TESTS POUR VOIR SI CA L'A BIEN ADD*/
//		return (new_export);
//	}
//	return (envp);
//}
