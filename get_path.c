/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelansa <yoelansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 03:17:34 by yoelansa          #+#    #+#             */
/*   Updated: 2023/02/17 23:49:47 by yoelansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*error_check(int a, char *str)
{
	if (a == 1)
	{
		write(2, str, ft_strlen(str));
		write(2, "! No such a file.\n", 19);
	}
	if (a == 2)
		write (2, "ERROR: You put an empty command.\n", 34);
	if (a == 3)
	{
		write(2, str, ft_strlen(str));
		write(2, "! Command not found.\n", 22);
	}
	if (a == 4)
		write (2, "ERROR: Unvalid number of arguments.\n", 37);
	if (a == 5)
		write (2, "ERROR: Unable to create pipe.\n", 31);
	if (a == 6)
		write(2, "ERROR: Unable to create child process.\n", 40);
	if (a == 7)
		write (2, "ERROR: Unvalid command.\n", 25);
	if (a == 8)
		write (2, "ERROR: Permission denied\n", 26);
	exit(1);
}

char	*_path(char **p)
{
	int	i;

	i = 0;
	while (p[i])
	{
		if (ft_strncmp(p[i], "PATH=", 5) == 0)
		{
			return (p[i] + 5);
		}
		i++;
	}
	return (NULL);
}

char	**_paths(char **p)
{
	char	**paths;

	paths = ft_split(_path(p), ':');
	return (paths);
}

void	free_paths(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

char	*cmd_path(char **paths, char *cmd, int i)
{
	char	*cmd_with_path;
	char	*tmp;

	if (!cmd)
		error_check(2, NULL);
	if (!access(cmd, X_OK))
		return (cmd);
	else if (ft_strrchr(cmd, '/') == 1)
		error_check(7, NULL);
	while (paths[++i])
	{
		tmp = ft_strjoin(paths[i], "/");
		cmd_with_path = ft_strjoin(tmp, cmd);
		if (!access(cmd_with_path, X_OK))
		{
			free_paths(paths);
			free(tmp);
			return (cmd_with_path);
		}
		free(tmp);
		free(cmd_with_path);
	}
	error_check (3, cmd);
	return (NULL);
}
