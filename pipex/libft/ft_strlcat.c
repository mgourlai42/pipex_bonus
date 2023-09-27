/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgourlai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 22:39:36 by mgourlai          #+#    #+#             */
/*   Updated: 2023/04/12 22:39:37 by mgourlai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dest[j] && j < size)
		j++;
	while (src[i])
		i++;
	i = 0;
	while (src[i] != '\0' && size && (i + j) < size -1)
	{
		dest[i + j] = src[i];
		i++;
	}
	if (j < size)
		dest[i + j] = '\0';
	i = 0;
	while (src[i])
		i++;
	return (i + j);
}
