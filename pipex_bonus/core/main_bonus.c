/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgourlai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:41:55 by mgourlai          #+#    #+#             */
/*   Updated: 2023/09/26 16:41:56 by mgourlai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	check_argv(char **argv)
{
	int	i;
	int	j;
	int	status;

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
		if (status == j)
			return (1);
		i++;
		status = 0;
		j = 0;
	}
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	t_smg	mg;

	if (argc >= 5 && check_argv(argv) == 0)
	{
		initstruct(&mg, argv, argc);
		if (ft_strncmp(argv[1], "here_doc", 8) == 0)
			ft_heredoc(&mg, env);
		else
			cmd_start(&mg, env);
	}
	else
		error_mnger
			("Input error\n./pipex infile cmd1 cmd2 outfile\n", 0);
	ft_free_tab(mg.argvcpy);
	return (0);
}
