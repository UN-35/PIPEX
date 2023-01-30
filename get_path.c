/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelansa <yoelansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 03:17:34 by yoelansa          #+#    #+#             */
/*   Updated: 2023/01/30 03:19:48 by yoelansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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

char	*cmd_path(char **paths, char *cmd)
{
	int		i;
	char	*cmd_with_path;
	char	*tmp;

	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		cmd_with_path = ft_strjoin(tmp, cmd);
		if (!access(cmd_with_path, X_OK))
			return (cmd_with_path);
		free(tmp);
		free(cmd_with_path);
		i++;
	}
	return (NULL);
}
