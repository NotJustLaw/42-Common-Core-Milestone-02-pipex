/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justlaw <justlaw@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:55:15 by justlaw           #+#    #+#             */
/*   Updated: 2025/05/22 21:42:30 by justlaw          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char *av[])
{
	if (error_handler(ac, av))
		return (1);
	
}

int error_handler(int ac, char *av[])
{
	if (ac != 5)
	{
		print_error();
		return (1);
	}

	
		
}

void	print_error()
{
	write(2, "Usage: ./pipex file1 cmd1 cmd2 file2\n", 37);
}