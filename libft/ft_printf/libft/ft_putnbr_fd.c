/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 21:12:00 by sjacki            #+#    #+#             */
/*   Updated: 2021/01/19 20:49:25 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int			finishlenint(int dex, int nb, int res)
{
	int len;

	len = 0;
	while (dex >= 10)
	{
		res = nb;
		res = res / dex + 48;
		++len;
		nb = nb % dex;
		dex /= 10;
	}
	nb += 48;
	++len;
	return (len);
}

int			finishputnbr(int dex, int nb, int res, int fd)
{
	int len;

	len = 0;
	while (dex >= 10)
	{
		res = nb;
		res = res / dex + 48;
		write(fd, &res, 1);
		++len;
		nb = nb % dex;
		dex /= 10;
	}
	nb += 48;
	write(fd, &nb, 1);
	++len;
	return (len);
}

int			ft_putnbr_fd(int n, int fd)
{
	int		res;
	int		nb;
	int		dex;
	int		len;

	dex = 1;
	nb = n;
	len = 0;
	if (n == -2147483648 && write(fd, "-2", 2))
	{
		len += 2;
		nb = 147483648;
	}
	else if (n < 0 && write(fd, "-", 1))
	{
		len++;
		nb *= -1;
	}
	res = nb;
	while (res > 9)
	{
		dex *= 10;
		res = res / 10;
	}
	return (len + finishputnbr(dex, nb, res, fd));
}

int			ft_len_int(int n)
{
	int		res;
	int		nb;
	int		dex;
	int		len;

	dex = 1;
	nb = n;
	len = 0;
	if (n == -2147483648)
	{
		++len;
		nb = 147483648;
	}
	else if (n < 0)
		nb *= -1;
	res = nb;
	while (res > 9)
	{
		dex *= 10;
		res = res / 10;
	}
	return (len + finishlenint(dex, nb, res));
}
