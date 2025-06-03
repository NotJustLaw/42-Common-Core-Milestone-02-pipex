/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuhlcke <skuhlcke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:36:45 by skuhlcke          #+#    #+#             */
/*   Updated: 2025/06/03 18:46:10 by skuhlcke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_child(int idx, t_child_args *args)
{
	int		x;
	char	**argv;
	char	*path;
	
	(void)idx;
	dup2(args->here_fd, STDIN_FILENO);
	dup2(args->pipes[1], STDOUT_FILENO);
	close(args->here_fd);
	x = 0;
	while (x < (args->num_cmds - 1) * 2)
	{
		close(args->pipes[x]);
		x++;
	}
	argv = parser(args->cmd_str);
	path = find_cmd_path(argv[0], args->envp);
	if (!path)
		exit(127);
	execve(path, argv, args->envp);
	perror("execve");
	exit(127);
}

void	i_child(int idx, t_child_args *args)
{
	int		x;
	char	**argv;
	char	*path;
	
	dup2(args->pipes[(idx - 1) * 2], STDIN_FILENO);
	dup2(args->pipes[idx * 2 + 1], STDOUT_FILENO);
	x = 0;
	while (x < (args->num_cmds - 1) * 2)
	{
		close(args->pipes[x]);
		x++;
	}
	argv = parser(args->cmd_str);
	path = find_cmd_path(argv[0], args->envp);
	if (!path)
		exit(127);
	execve(path, argv, args->envp);
	perror("execve");
	exit(127);
}

void	last_child(int idx, t_child_args *args)
{
	int		x;
	char	**argv;
	char	*path;

	dup2(args->pipes[(idx - 1) * 2], STDIN_FILENO);
	dup2(args->outfile_fd, STDOUT_FILENO);
	close(args->outfile_fd);
	x = 0;
	while (x < (args->num_cmds - 1) * 2)
	{
		close(args->pipes[x]);
		x++;
	}
	argv = parser(args->cmd_str);
	path = find_cmd_path(argv[0], args->envp);
	if (!path)
		exit(127);
	execve(path, argv, args->envp);
	perror("execve");
	exit(127);
}

// int	error_handler_bonus(int ac, char *av[], int mode)
// {
// 	if (mode == 1)
// 	{
// 		if (ac <= 6)
// 			return(ft_putstr_fd("Usage: ./pipex_bonus here_doc LIMITER cmd1 [cmd2 … cmdN] outfile\n", 2), 1);
// 	}
// 	else if(mode == 2)
// 	{
// 		if (ac <= 5)
// 			return(ft_putstr_fd("Usage: ./pipex_bonus infile cmd1 [cmd2 … cmdN] outfile\n", 2), 1);
// 	}
// 	return (0);
// }