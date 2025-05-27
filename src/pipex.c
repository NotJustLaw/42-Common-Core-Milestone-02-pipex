/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuhlcke <skuhlcke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:55:15 by justlaw           #+#    #+#             */
/*   Updated: 2025/05/27 18:05:42 by skuhlcke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char *av[], char **envp)
{
	t_fd_list	fds;
	
	if (error_handler(ac, av))
		return (1);
	fds.fd_in = fd_in_handler(av);
	if (fds.fd_in < 0)
		return (perror("open infile error"), 1);
	fds.fd_out = fd_out_handler(av);
	if (fds.fd_out < 0)
		return (perror("open outfile error"), 1);
	if (pipe_generator(fds.pipefd))
		return (1);
	fds.envp = envp;
	forking_process(&fds, av, envp);
	close(fds.fd_in);
	close(fds.fd_out);
	close(fds.pipefd[0]);
	close(fds.pipefd[1]);
	return (0);
}

void	forking_process(t_fd_list *fds, char *av[], char **envp)
{
	pid_t pid1;
	pid_t pid2;
	
	pid1 = fork();
	if (pid1 == 0)
		child1(fds, av, envp);
	pid2 = fork();
	if (pid2 == 0)
		child2(fds, av, envp);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}
