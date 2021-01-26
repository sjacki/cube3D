/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 19:39:41 by sjacki            #+#    #+#             */
/*   Updated: 2021/01/17 23:01:44 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

static void	ft_processor_p_widht(t_struct *flag, unsigned long long buf)
{
	int					x;

	x = 0;
	if (flag->minus)
	{
		write(1, "0x", 2);
		flag->len += 2;
		ft_putnbr_hex_p(flag, buf);
	}
	while (flag->width - ft_len_hex_p(buf, flag) > x)
	{
		write(1, " ", 1);
		x++;
		flag->len++;
	}
	if (!flag->minus)
	{
		write(1, "0x", 2);
		flag->len += 2;
		ft_putnbr_hex_p(flag, buf);
	}
}

void		ft_processor_p(t_struct *flag, va_list ap)
{
	unsigned long long	buf;

	if (!(buf = va_arg(ap, unsigned long long)) && flag->point && !flag->width)
	{
		write(1, "0x", 2);
		flag->len += 2;
		return ;
	}
	if (!flag->width)
	{
		write(1, "0x", 2);
		flag->len += 2;
		ft_putnbr_hex_p(flag, buf);
	}
	if (flag->width)
		ft_processor_p_widht(flag, buf);
}
