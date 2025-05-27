/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justlaw <justlaw@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:55:17 by justlaw           #+#    #+#             */
/*   Updated: 2025/05/26 13:41:29 by justlaw          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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