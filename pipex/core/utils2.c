/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                            :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: mgourlai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:31:40 by mgourlai          #+#    #+#             */
/*   Updated: 2023/08/28 15:31:41 by mgourlai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*ft_strcpy2(char *s1, const char *s2, int start, int end)
{
	size_t	i;

	i = 0;
	while (start != end && s2[start] != '\0')
	{
		s1[i] = s2[start];
		i++;
		start++;
	}
	s1[i] = '\0';
	return (s1);
}

char	**get_tab(char **tab, char *str, char c, int *len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && str[i] == c)
			i++;
		if (str[i] != '\0')
		{
			tab[j] = malloc(sizeof(char) * (len[j] + 1));
			ft_strcpy2(tab[j], str, i, i + len[j]);
			i = i + len[j];
			j++;
		}
	}
	tab[j] = NULL;
	return (tab);
}

int	get_wc(char *str, char c)
{
	int	i;
	int	wc;

	i = 0;
	wc = 0;
	while (str[i] != '\0')
	{
		if ((str[i] != c && str[i - 1] == c) || i == 0)
			wc++;
		i++;
	}
	return (wc);
}

int	*get_wl(char *str, char c, int wc)
{
	int	i;
	int	j;
	int	k;
	int	*len;

	i = 0;
	j = 0;
	len = malloc(sizeof(int) * wc);
	if (len == 0)
		return (NULL);
	while (str[i] != '\0')
	{
		k = 0;
		while (str[i] != '\0' && str[i] == c)
			i++;
		while (str[i] != '\0' && str[i] != c)
		{
			i++;
			k++;
		}
		if (k != 0)
			len[j++] = k;
	}
	return (len);
}

char	**ft_split(char *str, char c)
{
	char	**tab;
	int		wc;
	int		*len;

	wc = get_wc(str, c);
	len = get_wl(str, c, wc);
	tab = malloc(sizeof(char *) * (wc + 1));
	if (tab == 0)
		return (NULL);
	get_tab(tab, str, c, len);
	free (len);
	return (tab);
}
