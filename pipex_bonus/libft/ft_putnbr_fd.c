/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgourlai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 00:37:08 by mgourlai          #+#    #+#             */
/*   Updated: 2023/04/26 00:37:44 by mgourlai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		npos;
	char	c;

	npos = n;
	if (fd <= 0)
		return ;
	if (n == -2147483648)
	{
		write (fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		npos = -n;
		write(fd, "-", 1);
	}
	if (npos >= 10)
	{
		c = (npos % 10) + '0';
		ft_putnbr_fd(npos /= 10, fd);
		ft_putchar_fd(c, fd);
	}
	else
		ft_putchar_fd(npos + '0', fd);
}
