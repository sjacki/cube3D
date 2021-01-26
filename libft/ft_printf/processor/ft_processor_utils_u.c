/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor_utils_u.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 07:36:22 by sjacki            #+#    #+#             */
/*   Updated: 2021/01/17 15:53:58 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void		putminus_u(t_struct *flag, unsigned int *buf)
{
	if (*buf < 0)
	{
		write(1, "-", 1);
		*buf *= -1;
		flag->len++;
	}
}

int			finish_len_u(unsigned int dex, int nb)
{
	int				len;
	unsigned int	res;

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

int			ft_len_u(unsigned int n)
{
	unsigned int		res;
	unsigned int		nb;
	unsigned int		dex;
	int					len;

	dex = 1;
	nb = n;
	len = 0;
	if (n == 4294967295)
	{
		++len;
		nb = 147483648;
	}
	else if (n < 0)
	{
		++len;
		nb *= -1;
	}
	res = nb;
	while (res > 9)
	{
		dex *= 10;
		res = res / 10;
	}
	return (len + finish_len_u(dex, nb));
}

int			finish_put_nbr_u(unsigned int dex, unsigned int nb, int fd)
{
	int				len;
	unsigned int	res;

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

int			ft_putnbr_fd_u(unsigned int n, int fd)
{
	unsigned int		res;
	unsigned int		nb;
	unsigned int		dex;
	int					len;

	dex = 1;
	nb = n;
	len = 0;
	if (n < 0 && write(fd, "-", 1))
	{
		++len;
		nb *= -1;
	}
	res = nb;
	while (res > 9)
	{
		dex *= 10;
		res = res / 10;
	}
	return (len + finish_put_nbr_u(dex, nb, fd));
}
