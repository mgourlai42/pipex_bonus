/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgourlai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:41:02 by mgourlai          #+#    #+#             */
/*   Updated: 2023/08/07 15:41:06 by mgourlai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

void	child_process(int infd, int *fd, char **argv, char **env);
void	main_process(int outfd, int *fd, char **argv, char **env);
void	error_mnger(char *str, int n);
void	check_errors(int argc, char **argv);
int		check_argv(char **argv);
char	*pathfinder(char *argv, char **env);
void	ft_free_tab(char **str);
void	execute(char *argv, char **env);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);

char	**ft_split(char *str, char c);
int		get_wc(char *str, char c);
char	**get_tab(char **tab, char *str, char c, int *len);
char	*ft_strncpy(char *s1, const char *s2, size_t n);

#endif
