/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgourlai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 19:32:12 by mgourlai          #+#    #+#             */
/*   Updated: 2023/04/14 19:32:13 by mgourlai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1bis;
	unsigned char	*s2bis;	

	i = 0;
	s1bis = (unsigned char *) s1;
	s2bis = (unsigned char *) s2;
	while (i < n)
	{
		if (s1bis[i] != s2bis[i])
		{
			return (s1bis[i] - s2bis[i]);
		}
		i++;
	}
	return (0);
}
