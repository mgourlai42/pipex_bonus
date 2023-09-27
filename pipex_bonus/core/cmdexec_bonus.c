/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdexec_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgourlai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 18:41:07 by mgourlai          #+#    #+#             */
/*   Updated: 2023/09/16 18:41:09 by mgourlai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	cmd_start(t_smg *mg, char **env)
{
	int		pipe_fd[2];
	pid_t	pid;
	int		infd;
	int		status;

	infd = open(mg->argvcpy[1], O_RDONLY, 0777);
	if (infd == -1)
		error_mnger("Error\ncould not open infile", 1);
	pipe(pipe_fd);
	pid = fork();
	if (pid == 0)
		child_process_open(mg, env, infd, pipe_fd);
	close (pipe_fd[1]);
	wait(&status);
	mg->index++;
	mg->cmd_num++;
	if (mg->index < mg->argccpy - 2)
		cmd_mid(mg, pipe_fd, env);
	else
		cmd_end(mg, pipe_fd, env);
}

void	cmd_mid(t_smg *mg, int *prev_fd, char **env)
{
	int		pipe_fd[2];
	pid_t	pid;

	pipe(pipe_fd);
	pid = fork();
	if (pid == 0)
		child_process(mg, env, prev_fd, pipe_fd);
	close(prev_fd[0]);
	close (pipe_fd[1]);
	waitpid(pid, NULL, 0);
	mg->index++;
	mg->cmd_num++;
	if (mg->index < mg->argccpy - 2)
		cmd_mid(mg, pipe_fd, env);
	else
		cmd_end(mg, pipe_fd, env);
}

void	cmd_end(t_smg *mg, int *prev_fd, char **env)
{
	int		pipe_fd[2];
	pid_t	pid;
	int		outfd;

	if (strncmp("here_doc", mg->argvcpy[1], 8) == 0)
		outfd = open
			(mg->argvcpy[mg->argccpy - 1], O_RDWR | O_CREAT | O_APPEND, 0644);
	else
		outfd = open
			(mg->argvcpy[mg->argccpy - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfd == -1)
		error_mnger("Error\n could not open outfile", 1);
	pipe(pipe_fd);
	pid = fork();
	if (pid == 0)
	{
		if ((dup2(outfd, 1) == -1) || (dup2(prev_fd[0], 0) == -1))
			error_mnger("Error\n could not duplicate fd for end cmd", 1);
		execute(mg->argvcpy[mg->index], env);
	}
	waitpid(pid, NULL, 0);
	close(prev_fd[0]);
}
