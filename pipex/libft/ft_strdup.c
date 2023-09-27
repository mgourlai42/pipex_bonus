/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgourlai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:47:11 by mgourlai          #+#    #+#             */
/*   Updated: 2023/04/17 13:47:12 by mgourlai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		length;

	length = ft_strlen(s)+1;
	dup = malloc(length);
	if (dup == 0)
	{
		return (NULL);
	}
	ft_memcpy(dup, s, length);
	return (dup);
}
