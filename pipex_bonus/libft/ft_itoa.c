/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgourlai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 19:52:40 by mgourlai          #+#    #+#             */
/*   Updated: 2023/04/18 19:52:41 by mgourlai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_writing(int n, int len, int poscheck, char *result)
{
	int	i;

	i = len - 1;
	while (n >= 0 && i >= 0)
	{
		result[i] = ((n % 10) + '0');
		n /= 10;
		i--;
	}
	if (poscheck == 1)
		result[0] = '-';
	result[len] = '\0';
	return (result);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		poscheck;
	int		len;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		poscheck = 1;
		n = n * -1;
	}
	else
		poscheck = 0;
	len = ft_intlen(n);
	if (poscheck == 1)
		len = len + 1;
	result = malloc(sizeof(char) * len + 1);
	if (!result)
		return (NULL);
	ft_writing(n, len, poscheck, result);
	return (result);
}
