/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 07:13:09 by sjacki            #+#    #+#             */
/*   Updated: 2021/01/20 05:31:20 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

static void		ft_processor_u_precision(t_struct *flag, unsigned int *buf)
{
	int pre;

	if (*buf < 0)
		if (!(!flag->zero && (!flag->point || (flag->star && flag->pmin))))
			putminus_u(flag, buf);
	pre = flag->pre;
	while (pre-- > ft_len_u(*buf))
	{
		write(1, "0", 1);
		flag->len++;
	}
}

static void		ft_processor_u_width(t_struct *flag, unsigned int *buf)
{
	int		width;

	width = flag->width;
	if (*buf < 0 && flag->zero && (!flag->point || (flag->star && flag->pmin)))
		putminus_u(flag, buf);
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

static void		ft_processor_u_putzero(t_struct *flag, unsigned int buf)
{
	if (flag->point && !flag->width && !flag->pre && !flag->pmin)
		return ;
	if (flag->zero && flag->point && !flag->width && !flag->pmin && !flag->pre)
		return ;
	if (flag->width && !flag->pre && flag->point && !flag->pmin)
	{
		flag->width--;
		ft_processor_u_width(flag, &buf);
		flag->len += ft_putchar_fd(' ', 1);
		return ;
	}
	if (flag->pre < ft_len_u(buf))
		flag->pre = ft_len_u(buf);
	if (flag->minus)
	{
		ft_processor_u_precision(flag, &buf);
		flag->len += ft_putnbr_fd_u(buf, 1);
		ft_processor_u_width(flag, &buf);
	}
	else
	{
		ft_processor_u_width(flag, &buf);
		ft_processor_u_precision(flag, &buf);
		flag->len += ft_putnbr_fd_u(buf, 1);
	}
}

void			ft_processor_u(t_struct *flag, va_list ap)
{
	unsigned int	buf;

	buf = va_arg(ap, unsigned int);
	if (buf)
	{
		flag->p = flag->pre;
		if (flag->pre < ft_len_u(buf))
			flag->pre = ft_len_u(buf);
		if (flag->minus)
		{
			ft_processor_u_precision(flag, &buf);
			flag->len += ft_putnbr_fd_u(buf, 1);
			ft_processor_u_width(flag, &buf);
		}
		else
		{
			ft_processor_u_width(flag, &buf);
			ft_processor_u_precision(flag, &buf);
			flag->len += ft_putnbr_fd_u(buf, 1);
		}
	}
	else
		ft_processor_u_putzero(flag, buf);
}
