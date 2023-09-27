/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgourlai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:38:04 by mgourlai          #+#    #+#             */
/*   Updated: 2023/08/07 15:38:05 by mgourlai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

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
	ft_free_tab(argtab);
	free(path);
}

void	main_process(int outfd, int *fd, char **argv, char **env)
{
	int	status;

	wait(&status);
	close(fd[1]);
	if ((dup2(fd[0], 0) == -1) || (dup2(outfd, 1) == -1))
		error_mnger("Error\n could not duplicate fd in parent process", 1);
	close(outfd);
	execute(argv[3], env);
}

void	child_process(int infd, int *fd, char **argv, char **env)
{
	close(fd[0]);
	if ((dup2(infd, 0) == -1) || (dup2(fd[1], 1) == -1))
		error_mnger("error\n could not duplicate fd in child process", 1);
	close(infd);
	execute(argv[2], env);
}
