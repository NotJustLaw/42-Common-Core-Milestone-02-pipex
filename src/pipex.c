/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justlaw <justlaw@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:55:15 by justlaw           #+#    #+#             */
/*   Updated: 2025/05/26 18:18:41 by justlaw          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char *av[])
{
	t_fd_list	fds;
	
	if (error_handler(ac, av))
		return (1);
	fds.fd_in = fd_in_handler(av, fds.fd_in);
	if (fds.fd_in < 0)
		return (perror("open infile"), 1);
	fds.fd_out = fd_out_handler(av, fds.fd_out);
	if (fds.fd_out < 0)
		return (perror("open outfile"), 1);

	close(fds.fd_in);
	close(fds.fd_out);
	close(fds.pipefd[0]);
	close(fds.pipefd[1]);
	return (0);
}

