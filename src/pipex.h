/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justlaw <justlaw@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 21:00:26 by justlaw           #+#    #+#             */
/*   Updated: 2025/05/30 18:59:05 by justlaw          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>


typedef struct	s_fd_list
{
	int		fd_in;
	int		fd_out;
	int		pipefd[2];
	char	*cmd;
	char	**envp;
}		t_fd_list;

//FD-s handlers
int		fd_in_handler(char *av[]);
int		fd_out_handler(char *av[]);
int		pipe_generator(int pipefd[2]);

//Forkers
void	forking_process(t_fd_list *fds, char *av[], char **envp);
void	child1(t_fd_list *fds, char *av[], char **envp);
void	child2(t_fd_list *fds, char *av[], char **envp);

//Error handlers
int 	error_handler(int ac, char *av[]);
void	print_error();

//Helpers
void	free_split(char **arr);
char 	*join_path(const char *dir, const char *cmd);
char	**parser(char av[]);
char	*find_cmd_path(char *cmd, char **envp);

#endif