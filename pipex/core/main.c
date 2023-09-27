/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgourlai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:37:37 by mgourlai          #+#    #+#             */
/*   Updated: 2023/09/26 15:37:38 by mgourlai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	check_argv(char **argv)
{
	int		i;
	int		j;
	size_t	status;

	i = 0;
	j = 0;
	status = 0;
	while (argv[i])
	{
		if (ft_strlen(argv[i]) == 0)
			return (1);
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] == ' ' || argv[i][j] == '	')
				status++;
			j++;
		}
		if (status == ft_strlen(argv[i]) && status >= 1)
			return (1);
		i++;
		status = 0;
		j = 0;
	}
	return (0);
}

void	check_errors(int argc, char **argv)
{
	if (argc != 5 || check_argv(argv) == 1)
	{
		error_mnger("Input error\n\
./pipex infile cmd1 cmd2 outfile\n", 0);
	}
}

int	main(int argc, char **argv, char **env)
{
	int	fd[2];
	int	pid;
	int	infd;
	int	outfd;
	int	pipe_status;

	check_errors(argc, argv);
	infd = open(argv[1], O_RDONLY, 0777);
	if (infd == -1)
		error_mnger("Error\n could not open infile", 1);
	outfd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfd == -1)
		error_mnger("Error\n could not open outfile", 1);
	pipe_status = pipe(fd);
	if (pipe_status == -1)
		error_mnger("Error with pipe", 1);
	pid = fork();
	if (pid < 0)
		error_mnger("Error with fork", 1);
	if (pid == 0)
		child_process(infd, fd, argv, env);
	main_process(outfd, fd, argv, env);
	return (0);
}
