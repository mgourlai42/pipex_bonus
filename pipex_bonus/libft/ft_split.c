/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftsplit2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgourlai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:44:19 by mgourlai          #+#    #+#             */
/*   Updated: 2023/04/24 17:44:21 by mgourlai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countword(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i - 1] == c || i == 0))
			j++;
		i++;
	}
	return (j);
}

int	*ft_wordlen(char const *s, char c)
{
	int	i;
	int	j;
	int	k;
	int	*result;

	i = 0;
	k = 0;
	result = (int *)malloc(sizeof(int) * (ft_countword(s, c)));
	if (!result)
		return (NULL);
	while (s[i])
	{
		j = 0;
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			i++;
			j++;
		}
		if (j > 0)
			result[k++] = j;
	}
	return (result);
}

char	*ft_strcpy(char *str, const char *s, int start, int end)
{
	int	i;

	i = 0;
	while (s[start] != '\0' && start != end)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split_part_2(char **str, int *wordlength, const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			str[j] = (char *)malloc(sizeof(char) * (wordlength[j] + 1));
			ft_strcpy(str[j], s, i, (i + wordlength[j]));
			i = i + wordlength[j];
			j++;
		}
	}
	str[j] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		word;
	int		*wordlength;

	word = ft_countword(s, c);
	wordlength = ft_wordlen(s, c);
	str = (char **)malloc(sizeof(char *) * (word + 1));
	if (!str)
		return (NULL);
	ft_split_part_2(str, wordlength, s, c);
	free(wordlength);
	return (str);
}
