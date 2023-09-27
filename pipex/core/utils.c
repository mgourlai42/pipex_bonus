/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgourlai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:48:05 by mgourlai          #+#    #+#             */
/*   Updated: 2023/08/29 18:48:06 by mgourlai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// manages errors with program and input
void	error_mnger(char *str, int n)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		while (str[i])
		{
			write (1, &str[i], 1);
			i++;
		}
	}
	else
		perror(str);
	exit(1);
}

void	ft_free_tab(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	if (little[i] == 0)
		return ((char *)big);
	while (big[i] != '\0' && k < len)
	{
		while (big[i] != 0 && little[j] != '\0'
			&& big[i] == little[j] && (k + j) < len)
		{
			i++;
			j++;
			if (little[j] == 0)
				return ((char *)&big[i - j]);
		}
		k++;
		i = k;
		j = 0;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (len + 1));
	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}
