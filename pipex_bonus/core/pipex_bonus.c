/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgourlai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:34:53 by mgourlai          #+#    #+#             */
/*   Updated: 2023/09/16 16:34:54 by mgourlai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	initstruct(t_smg *mg, char **argv, int argc)
{
	int	i;

	i = 0;
	mg->argccpy = argc;
	mg->index = 2;
	mg->pipe_number = argc - 3;
	mg->argvcpy = malloc(sizeof(char *) * (argc + 1));
	if (!mg->argvcpy)
		return ;
	while (i < argc)
	{
		mg->argvcpy[i] = ft_strdup(argv[i]);
		i++;
	}
	mg->argvcpy[i] = NULL;
}

void	child_process_open(t_smg *mg, char **env, int prev_fd, int *pipe_fd)
{
	close(pipe_fd[0]);
	if (dup2(prev_fd, 0) == -1 || dup2(pipe_fd[1], 1) == -1)
	{
		error_mnger("Error\ncouldn't dup2 fd in process\n", 1);
	}
	execute(mg->argvcpy[mg->index], env);
}

void	child_process(t_smg *mg, char **env, int *prev_fd, int *pipe_fd)
{
	close(pipe_fd[0]);
	if (dup2(prev_fd[0], 0) == -1 || dup2(pipe_fd[1], 1) == -1)
	{
		error_mnger("Error\ncouldn't dup2 fd in process\n", 1);
	}
	execute(mg->argvcpy[mg->index], env);
}

char	*pathfinder(char *argv, char **env)
{
	char	*realpath;
	char	**tabpath;
	char	*temppath;
	int		i;

	i = 0;
	while (ft_strnstr(env[i], "PATH=", 5) == NULL)
		i++;
	tabpath = ft_split(env[i] + 5, ':');
	i = 0;
	while (tabpath[i++])
	{
		temppath = ft_strjoin(tabpath[i], "/");
		realpath = ft_strjoin(temppath, argv);
		free(temppath);
		if (access(realpath, F_OK) == 0)
		{
			free(tabpath);
			return (realpath);
		}
		free(realpath);
	}
	ft_free_tab(tabpath);
	error_mnger("error\ncould not find binary", 1);
	return (NULL);
}

void	execute(char *argv, char **env)
{
	char	**argtab;
	char	*path;

	argtab = ft_split(argv, ' ');
	path = pathfinder(argtab[0], env);
	if (execve(path, argtab, env) == -1)
	{
		ft_free_tab(argtab);
		free(path);
		error_mnger("error\ncould not execute binary", 1);
	}
}
