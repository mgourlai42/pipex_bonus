/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgourlai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 19:11:57 by mgourlai          #+#    #+#             */
/*   Updated: 2023/09/26 19:11:58 by mgourlai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	ft_heredoc_2(t_smg *mg, char **env, int *pipe_fd, int *nextpipe_fd)
{
	int		status;
	pid_t	pid;

	close(pipe_fd[1]);
	mg->index++;
	pid = fork();
	if (pid == 0)
		child_process(mg, env, pipe_fd, nextpipe_fd);
	close(pipe_fd[0]);
	close (nextpipe_fd[1]);
	wait(&status);
	mg->index++;
	mg->cmd_num++;
	if (mg->index < mg->argccpy - 2)
		cmd_mid(mg, nextpipe_fd, env);
	else
		cmd_end(mg, nextpipe_fd, env);
}

void	ft_heredoc_input(char *input, int *pipe_fd)
{
	write(pipe_fd[1], input, ft_strlen(input));
	write(pipe_fd[1], "\n", 1);
	free(input);
}

void	ft_heredoc(t_smg *mg, char **env)
{
	char	*input;
	int		pipe_fd[2];
	int		nextpipe_fd[2];

	pipe(pipe_fd);
	pipe(nextpipe_fd);
	while (42)
	{
		input = readline ("> ");
		if (strncmp(input, mg->argvcpy[2], ft_strlen(mg->argvcpy[2])) \
			== 0 && ft_strlen(input) == ft_strlen(mg->argvcpy[2]))
		{
			free(input);
			break ;
		}
		else
			ft_heredoc_input(input, pipe_fd);
	}
	ft_heredoc_2(mg, env, pipe_fd, nextpipe_fd);
}
