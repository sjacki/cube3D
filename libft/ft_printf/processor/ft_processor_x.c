/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 15:47:52 by sjacki            #+#    #+#             */
/*   Updated: 2021/01/20 05:31:31 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

static void		ft_processor_x_precision(t_struct *flag, unsigned int *buf)
{
	int pre;

	pre = flag->pre;
	while (pre-- > ft_len_hex(*buf))
	{
		write(1, "0", 1);
		flag->len++;
	}
}

static void		ft_processor_x_width(t_struct *flag, unsigned int *buf)
{
	int		width;

	width = flag->width;
	if (*buf < 0)
		flag->width--;
	width = flag->width;
	while (width-- > flag->pre)
	{
		if (flag->zero && (!flag->point || (flag->star && flag->pmin)))
			write(1, "0", 1);
		else
			write(1, " ", 1);
		flag->len++;
	}
}

static void		ft_processor_x_putzero(t_struct *flag, unsigned int buf)
{
	if (flag->point && !flag->width && !flag->pre && !flag->pmin)
		return ;
	if (flag->zero && flag->point && !flag->width && !flag->pmin && !flag->pre)
		return ;
	if (flag->width && !flag->pre && flag->point && !flag->pmin)
	{
		flag->width--;
		ft_processor_x_width(flag, &buf);
		flag->len += ft_putchar_fd(' ', 1);
		return ;
	}
	if (flag->pre < ft_len_hex(buf))
		flag->pre = ft_len_hex(buf);
	if (flag->minus)
	{
		ft_processor_x_precision(flag, &buf);
		ft_putnbr_hex(flag, buf);
		ft_processor_x_width(flag, &buf);
	}
	else
	{
		ft_processor_x_width(flag, &buf);
		ft_processor_x_precision(flag, &buf);
		ft_putnbr_hex(flag, buf);
	}
}

void			ft_processor_x(t_struct *flag, va_list ap)
{
	unsigned int		buf;

	buf = va_arg(ap, unsigned int);
	if (buf)
	{
		flag->p = flag->pre;
		if (flag->pre < ft_len_hex(buf))
			flag->pre = ft_len_hex(buf);
		if (flag->minus)
		{
			ft_processor_x_precision(flag, &buf);
			ft_putnbr_hex(flag, buf);
			ft_processor_x_width(flag, &buf);
		}
		else
		{
			ft_processor_x_width(flag, &buf);
			ft_processor_x_precision(flag, &buf);
			ft_putnbr_hex(flag, buf);
		}
	}
	else
		ft_processor_x_putzero(flag, buf);
}
