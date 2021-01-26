/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 17:03:58 by sjacki            #+#    #+#             */
/*   Updated: 2021/01/17 23:36:57 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void		ft_putnbr_hex_p(t_struct *flag, unsigned long long buf)
{
	char *hex;
	char c;

	if (!buf && flag->point)
		return ;
	hex = "          abcdef";
	if (flag->type == 'X')
		hex = "          ABCDEF";
	if (buf > 15)
	{
		ft_putnbr_hex_p(flag, buf / 16);
		ft_putnbr_hex_p(flag, buf % 16);
	}
	else
	{
		if (buf >= 10 && (c = hex[buf]))
			ft_putchar_fd(c, 1);
		else
			ft_putnbr_fd_u(buf, 1);
		flag->len++;
	}
}

int			ft_len_hex_p(unsigned long long buf, t_struct *flag)
{
	int x;

	x = 2;
	if (!buf && flag->point)
		return (2);
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
