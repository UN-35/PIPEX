/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelansa <yoelansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 02:15:28 by yoelansa          #+#    #+#             */
/*   Updated: 2023/01/30 03:18:45 by yoelansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	child_p(char *args[5], int fds[2], char **x)
{
	char	**cmd_with_args;
	char	*path;
	int		fd;

	cmd_with_args = ft_split(args[2], ' ');
	path = cmd_path(_paths(x), cmd_with_args[0]);
	fd = open(args[1], O_RDONLY);
	dup2(fd, 0);
	dup2(fds[1], 1);
	close(fd);
	close(fds[0]);
	close(fds[1]);
	execve(path, cmd_with_args, x);
}

void	forking(char *args[5], int fds[2], char **x)
{
	char	**cmd_with_args;
	char	*path;
	int		fd;

	wait(NULL);
	cmd_with_args = ft_split(args[3], ' ');
	path = cmd_path(_paths(x), cmd_with_args[0]);
	fd = open (args[4], O_WRONLY | O_CREAT | O_TRUNC, 0755);
	dup2(fd, 1);
	dup2(fds[0], 0);
	close(fd);
	close(fds[0]);
	close(fds[1]);
	execve(path, cmd_with_args, x);
}

int	main(int ac, char *av[], char *x[])
{
	int		fds[2];
	int		frk;

	if (ac != 5)
	{
		write (2, "ERROR: Unvalid number of arguments\n", 36);
		return (1);
	}
	if (pipe(fds) == -1)
	{
		write(2, "ERROR: Unable to create pipe\n", 30);
		return (1);
	}
	frk = fork();
	if (frk == -1)
	{
		write(2, "ERROR: Unable to create child process\n", 39);
		return (1);
	}
	if (frk == 0)
		child_p(av, fds, x);
	forking(av, fds, x);
	return (0);
}
