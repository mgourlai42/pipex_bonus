/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgourlai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:41:02 by mgourlai          #+#    #+#             */
/*   Updated: 2023/08/07 15:41:06 by mgourlai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_smg
{
	int		pipe_number;
	int		cmd_num;
	int		index;
	char	**argvcpy;
	int		argccpy;
	char	**envcpy;
}	t_smg;

// main functions
void	child_process(t_smg *mg, char **env, int *prev_fd, int *pipe_fd);
void	child_process_open(t_smg *mg, char **env, int prev_fd, int *pipe_fd);
void	main_process(int outfd, int *fd, char **argv, char **env);
void	error_mnger(char *str, int n);
char	*pathfinder(char *argv, char **env);
void	ft_free_tab(char **str);
void	execute(char *argv, char **env);

// bonus functions
void	cmd_start(t_smg *mg, char **env);
void	cmd_mid(t_smg *mg, int *fd, char **env);
void	cmd_end(t_smg *mg, int *fd, char **env);
void	initstruct(t_smg *mg, char **argv, int argc);
void	ft_heredoc(t_smg *mg, char **env);
void	ft_heredoc_2(t_smg *mg, char **env, int *pipe_fd, int *nextpipe_fd);

// util functions
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	**ft_split(char *str, char c);
int		get_wc(char *str, char c);
char	**get_tab(char **tab, char *str, char c, int *len);
char	*ft_strncpy(char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
