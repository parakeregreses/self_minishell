/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   env_variables.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: liulm <liulm@student.42.fr>				+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/05/09 15:05:42 by liulm			 #+#	#+#			 */
/*   Updated: 2025/05/22 16:41:29 by liulm			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "minishell.h"

int	ft_find_env(char **envp, char *env_variable)
{
	int		i;
	size_t	j;
	size_t	length;

	i = 0;
	length = 0;
	while (env_variable[length] && env_variable[length] != '=')
		length++;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j] && envp[i][j] != '=')
			j++;
		if (ft_strncmp(envp[i], env_variable, length) == 0 && j == length)
			return (i);
		i++;
	}
	return (-1);
}

/* rajoute une variable d'environnement*/
char	**ft_create_env(char **envp, char *new_env_variable)
{
	int		i;
	int		count;
	char	**new_envp;

	i = 0;
	count = 0;
	while (envp[count])
		count++;
	new_envp = (char **)malloc((count + 2) * sizeof(char *));
	if (new_envp == NULL)
		return (NULL);
	while (i < count)
	{
		new_envp[i] = ft_strdup(envp[i]);
		if (new_envp[i] == NULL)
			return (ft_free_envp(i, new_envp));
		i++;
	}
	new_envp[i] = ft_strdup(new_env_variable);
	if (new_envp[i] == NULL)
		return (ft_free_envp(i, new_envp));
	new_envp[++i] = NULL;
	return (new_envp);
}

char	**ft_replace_env_if_found(char **envp, char *env_variable)
{
	int	check;

	check = ft_find_env(envp, env_variable);
	if (check != -1)
	{
		free(envp[check]);
		envp[check] = ft_strdup(env_variable);
		return (envp);
	}
	else
		return (ft_create_env(envp, env_variable));
}

/* copie les variables d'environnement deja presentes dans env grace a envp */
char	**ft_copy_env(char **envp)
{
	int		i;
	int		count;
	char	**env_cpy;

	i = 0;
	count = 0;
	while (envp[count])
		count++;
	env_cpy = (char **)malloc((count + 1) * sizeof(char *));
	if (env_cpy == NULL)
		return (NULL);
	while (i < count)
	{
		env_cpy[i] = ft_strdup(envp[i]);
		if (env_cpy[i] == NULL)
		{
			while (--i >= 0)
				free(env_cpy[i]);
			free(env_cpy);
			return (NULL);
		}
		i++;
	}
	env_cpy[i] = NULL;
	return (env_cpy);
}

/* rajoute la variable dans envp directement */
/* new env variable est argv de la var envi */
char	**ft_add_in_env(char **envp, char *new_env_variable)
{
	char	**new_envp;
	char	**final;

	if (new_env_variable == NULL || new_env_variable[0] == '\0')
		return (envp);
	new_envp = ft_copy_env(envp);
	if (new_envp == NULL)
		return (NULL);
	final = ft_replace_env_if_found(new_envp, new_env_variable);
	if (final == NULL)
	{
		free_envp(new_envp);
		return (NULL);
	}
	return (final);
}

/*------------------------------------------------------------------*/

/* MEMO:

check si c'est mieux de free l'ancien envp ou
si on peut juste ajouter a la fin sans tout vider */

// int main(int argc, char **argv, char **envp)
// {
// 	int i = 0;
// 	char *new_var;
// 	char *new_var2;
// 	char *new_var3;
// 	char **new_envp;
// 	(void)argc;
// 	(void)argv;

// 	new_envp = ft_copy_env(envp);
//	// new_envp = NULL;
//	 new_var = "bonjour=0";
//	 new_var2 = "bon";
//	 new_var3 = "bonjour=bon";

//	 if (new_envp == NULL)
//	 	printf("boo boo\n");

//	 while (new_envp[i])
//	 {
//	 	printf("%s\n", new_envp[i]);
//	 	i++;
//	 }
//	 printf("\n --------------- \n\n");

//	 i = 0;
//	 while (envp[i])
//	 {
//	 	printf("%d\n", ft_strcmp(new_envp[i], envp[i]));
//	 	i++;
//	 }
// 	new_envp = ft_add_in_env(new_envp, new_var);
// 	printf("\n --------------- \n\n");
// 	i = 0;
// 	while (new_envp[i])
// 	{
// 		printf("%s\n", new_envp[i]);
// 		i++;
// 	}
// 	new_envp = ft_add_in_env(new_envp, new_var2);
// 	printf("\n --------------- \n\n");
// 	i = 0;
// 	while (new_envp[i])
// 	{
// 		printf("%s\n", new_envp[i]);
// 		i++;
// 	}
// 	new_envp = ft_add_in_env(new_envp, new_var3);
// 	printf("\n --------------- \n\n");
// 	i = 0;
// 	while (new_envp[i])
// 	{
// 		printf("%s\n", new_envp[i]);
// 		i++;
// 	}
// }

/* copie fonctionne */
/* add fonctionne */
/* check si la variable existe deja et
 la remplacer si oui, dans add in */

/* A FAIRE : supprimer une variable ()*/

/* unset NEW_VAR marche */
/* unset NEW_VAR=0 ou NEW_VAR="0" marche pas */

/* ft_strchr "=" pour rajouter que les variables
ayant un = dans le env, dans export ya tout */
