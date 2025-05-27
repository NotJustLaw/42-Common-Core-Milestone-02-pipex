/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justlaw <justlaw@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 21:00:26 by justlaw           #+#    #+#             */
/*   Updated: 2025/05/26 18:16:58 by justlaw          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PIPEX_H
# ifndef PIPE_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct	s_fd_list
{
	int		fd_in;
	int		fd_out;
	int		pipefd[2];
	char	*cmd;
	char	**envp;
}		t_fd_list;

//FD-s handlers
int		fd_in_handler(char *av[], int fd_in);
int		fd_out_handler(char *av[], int fd_out);

//Erro handlers
int 	error_handler(int ac, char *av[]);
void	print_error();

#endif