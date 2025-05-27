/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuhlcke <skuhlcke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:55:17 by justlaw           #+#    #+#             */
/*   Updated: 2025/05/27 18:41:01 by skuhlcke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"x

int error_handler(int ac, char *av[])
{
	if (ac != 5)
	{
		print_error();
		return (1);
	}
	return (0);
}

void	print_error()
{
	write(2, "Usage: ./pipex file1 cmd1 cmd2 file2\n", 37);
}

void	child1(t_fd_list *fds, char *av[], char **envp)
{
	char	**args;
	char	*cmd_path;

	dup2(fds->fd_in, 0);
	dup2(fds->pipefd[1], 1);
	close(fds->fd_in);
	close(fds->fd_out);
	close(fds->pipefd[0]);
	close(fds->pipefd[1]);
	args = parser(av[2]);
	if (!args || !args[0])
	{
		perror("No command found");
		free_split(args);
		exit(127);
	}
	cmd_path = find_cmd_path(args[0], envp);
	if (!cmd_path)
		exit(127);
	execve(cmd_path, args, envp);
	perror("execve failed");
	free_split(args);
	exit(1);
}

void	child2(t_fd_list *fds, char *av[], char **envp)
{
	char	**args;
	char	*cmd_path;

	dup2(fds->pipefd[0], 0);
	dup2(fds->fd_out, 1);
	close(fds->fd_in);
	close(fds->fd_out);
	close(fds->pipefd[0]);
	close(fds->pipefd[1]);
	args = parser(av[3]);
	if (!args || !args[0])
	{
		perror("No command found");
		free_split(args);
		exit(127);
	}
	cmd_path = find_cmd_path(args[0], envp);
	if (!cmd_path)
		exit(127);
	execve(cmd_path, args, envp);
	perror("execve failed");
	free_split(args);
	exit(1);
}

char	**parser(char av[])
{
	char	**arr;

	arr = ft_split(av, ' ');
	return (arr);
}