/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 21:12:00 by sjacki            #+#    #+#             */
/*   Updated: 2021/01/26 19:54:22 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

void		finishputnbr(int dex, int nb, int res, int fd)
{
	while (dex >= 10)
	{
		res = nb;
		res = res / dex + 48;
		write(fd, &res, 1);
		nb = nb % dex;
		dex /= 10;
	}
	nb += 48;
	write(fd, &nb, 1);
}

void		ft_putnbr_fd(int n, int fd)
{
	int		res;
	int		nb;
	int		dex;

	dex = 1;
	nb = n;
	if (n == -2147483648)
	{
		write(fd, "-2", 2);
		nb = 147483648;
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		nb *= -1;
	}
	res = nb;
	while (res > 9)
	{
		dex *= 10;
		res = res / 10;
	}
	finishputnbr(dex, nb, res, fd);
}
