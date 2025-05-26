/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justlaw <justlaw@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 21:31:48 by justlaw           #+#    #+#             */
/*   Updated: 2025/05/22 21:39:10 by justlaw          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	files_handler(char *av[])
{
	int	fd_in;
	int	fd_out;

	fd_in = open(av[1], O_RDONLY);
	fd_out = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);

	
	
}

void	pipe_generator(int fd)
{
	pipe(fd);
}