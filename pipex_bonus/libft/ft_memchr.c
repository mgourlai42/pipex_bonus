/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgourlai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 19:31:45 by mgourlai          #+#    #+#             */
/*   Updated: 2023/04/14 19:31:47 by mgourlai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;
	size_t	i;
	char	ch;

	ch = (char)c;
	str = (char *) s;
	i = 0;
	while (i < n)
	{
		if (*str == ch)
		{
			return ((void *) str);
		}
		str++;
		i++;
	}
	return (NULL);
}
