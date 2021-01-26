/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 17:03:58 by sjacki            #+#    #+#             */
/*   Updated: 2021/01/20 05:14:40 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void		ft_putnbr_hex(t_struct *flag, unsigned int buf)
{
	char *hex;
	char c;

	hex = "          abcdef";
	if (flag->type == 'X')
		hex = "          ABCDEF";
	if (buf > 15)
	{
		ft_putnbr_hex(flag, buf / 16);
		ft_putnbr_hex(flag, buf % 16);
	}
	else
	{
		if (buf >= 10)
		{
			c = hex[buf];
			ft_putchar_fd(c, 1);
		}
		else
			ft_putnbr_fd_u(buf, 1);
		flag->len++;
	}
}

int			ft_len_hex(unsigned int buf)
{
	int x;

	x = 0;
	if (buf > 15)
	{
		x++;
		x += ft_len_hex(buf / 16);
		ft_len_hex(buf % 16);
	}
	else
		x++;
	return (x);
}
