/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuhlcke <skuhlcke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:11:11 by skuhlcke          #+#    #+#             */
/*   Updated: 2025/06/03 18:27:59 by skuhlcke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	open_infile(const char *path);
static int	open_outfile_trunc(const char *path);

void	handle_here_doc_mode(int ac, char *av[], char **envp)
{
	int				here_pipe[2];
	int				outfile_fd;
	int				num_cmds;
	int				*pipes;
	t_child_args	args;

	if (pipe_generator(here_pipe))
		exit(1);
	read_ereadoc(here_pipe[1], av[2]);
	outfile_fd = open_append_outfile(av[ac - 1]);
	num_cmds = ac - 4;
	pipes = create_pipes(num_cmds);
	args.here_fd = here_pipe[0];
	args.pipes = pipes;
	args.num_cmds = num_cmds;
	args.outfile_fd = outfile_fd;
	args.envp = envp;
	fork_and_dispatch(&args, &av[3]);
	parent_cleanup(here_pipe[0], outfile_fd, pipes, num_cmds);
}

void	handle_multi_pipe_mode(int ac, char *av[], char **envp)
{
	int				infile_fd;
	int				outfile_fd;
	int				num_cmds;
	int				*pipes;
	t_child_args	args;

	infile_fd = open_infile(av[1]);
	outfile_fd = open_outfile_trunc(av[ac - 1]);
	num_cmds = ac - 3;
	pipes = create_pipes(num_cmds);
	args.here_fd = infile_fd;
	args.pipes = pipes;
	args.num_cmds = num_cmds;
	args.outfile_fd = outfile_fd;
	args.envp = envp;
	fork_and_dispatch(&args, &av[2]);
	parent_cleanup(infile_fd, outfile_fd, pipes, num_cmds);
}

static int	open_infile(const char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		perror("open infile");
		exit(1);
	}
	return (fd);
}

static int	open_outfile_trunc(const char *path)
{
	int	fd;

	fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror("open outfile");
		exit(1);
	}
	return (fd);
}
