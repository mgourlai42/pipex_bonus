/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgourlai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:25:09 by mgourlai          #+#    #+#             */
/*   Updated: 2023/04/14 14:25:11 by mgourlai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
