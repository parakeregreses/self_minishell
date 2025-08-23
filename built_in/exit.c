/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 17:52:56 by liulm             #+#    #+#             */
/*   Updated: 2025/08/23 16:23:09 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_numeric(const char *str)
{
	int	i = 0;

	if (!str || !*str)
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int count_args(char **args)
{
	int	count = 0;

	while (args && args[count])
		count++;
	return count;
}

//int	check_if_exit(char **args)
//{
//	int	i;
//	int	count;

//	i = 0;
//	count = 0;
//	while (args[count])
//		count++;
//	while (args[i])
//	{
//		if (is_str_num(args[i]))
//			return (1);
//		else if (count > 2)
//			return (0);
//		i++;
//	}
//}

//void	cmd_exit(char **args, char ***envp, int *status, int ok)
//{
//	printf("exit\n");
//	if (check_if_exit)
//	{
//		free_tab((void **)*envp);
//		free(status);
//		//printf("exit\n");
//	}
//}

//void cmd_exit2(char **args, char ***envp, int *status)
//{
//	int	res;
//	int	count_args;

//	res = 0;
//	count_args = 0;
//	(void)status;
//	(void)envp;
//	while (args[count_args])
//		count_args++;
//	//printf("%d", count_args);
//	if (count_args > 2)
//	{
//		printf("exit\n");
//		printf("minishell: exit: too many arguments\n");
//		*status = 1;
//		return ;
//	}
//	else
//	{
//		res = ft_atoi(args[1]);
//		res %= 256;
//		//printf("%d", res);
//	}
//	*status = res;
//	//free_and_print_exit(envp, args, status);
//}

void	cmd_exit(char **args, char ***envp, int *status)
{
	int	argc = count_args(args);
	long	exit_val;

	printf("exit\n");
	if (argc == 1)
	{
		free_tab((void **)*envp);
		*status %= 256;
		return ;
	}
	if (!is_numeric(args[1]))
	{
		fprintf(stderr, "minishell: exit: %s: numeric argument required\n", args[1]);
		free_tab((void **)*envp);
		*status = 2;
	}
	if (argc > 2)
	{
		printf("minishell: exit: too many arguments\n");
		*status = 1;
		return ;
	}
	exit_val = atol(args[1]);
	*status = (unsigned char)exit_val;
	free_tab((void **)*envp);
	free(status);
	exit(*status);
}
