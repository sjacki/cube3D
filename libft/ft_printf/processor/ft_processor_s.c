/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 10:20:04 by sjacki            #+#    #+#             */
/*   Updated: 2021/01/20 05:28:40 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

static void	ft_processor_pre_weidth_min_s(t_struct *flag, char *buf)
{
	int x;

	x = 0;
	while (x < flag->pre && buf[x])
	{
		write(1, &buf[x], 1);
		flag->len++;
		x++;
	}
	x = 0;
	if (flag->pre >= (int)ft_strlen(buf))
		while (x < flag->width - (int)ft_strlen(buf))
		{
			write(1, " ", 1);
			flag->len++;
			x++;
		}
	else
		while (x < flag->width - flag->pre)
		{
			write(1, " ", 1);
			flag->len++;
			x++;
		}
}

static void	ft_processor_pre_weidth_s(t_struct *flag, char *buf)
{
	int x;

	x = 0;
	if (flag->pre >= (int)ft_strlen(buf))
		while (x < flag->width - (int)ft_strlen(buf))
		{
			write(1, " ", 1);
			flag->len++;
			x++;
		}
	else
		while (x < flag->width - flag->pre)
		{
			write(1, " ", 1);
			flag->len++;
			x++;
		}
	x = 0;
	while (x < flag->pre && buf[x])
	{
		write(1, &buf[x], 1);
		flag->len++;
		x++;
	}
}

static void	ft_processor_pre_s(t_struct *flag, char *buf)
{
	int x;

	x = 0;
	if ((size_t)flag->pre >= ft_strlen(buf))
		ft_putstr_fd(buf, 1, flag);
	if ((size_t)flag->pre < ft_strlen(buf))
	{
		while (x < flag->pre)
		{
			write(1, &buf[x], 1);
			flag->len++;
			x++;
		}
	}
}

static void	ft_processor_width_s(t_struct *flag, char *buf)
{
	int x;

	x = 0;
	if (flag->minus || flag->width < (int)ft_strlen(buf))
		ft_putstr_fd(buf, 1, flag);
	if ((size_t)flag->width >= ft_strlen(buf))
	{
		while (flag->width - (int)ft_strlen(buf) > x)
		{
			flag->len++;
			if (flag->zero)
				write(1, "0", 1);
			else
				write(1, " ", 1);
			x++;
		}
		if (!flag->minus)
			ft_putstr_fd(buf, 1, flag);
	}
}

void		ft_processor_s(t_struct *flag, va_list ap)
{
	char	*buf;
	char	*buf_va;
	int		x;

	x = 0;
	buf = "(null)";
	if ((buf_va = va_arg(ap, char*)))
		buf = buf_va;
	if (!flag->pre && flag->point && !flag->width && !flag->pmin)
		return ;
	if (!flag->pre && flag->point && flag->width && !flag->pmin)
		buf = "";
	if (!flag->width && !flag->pre)
		ft_putstr_fd(buf, 1, flag);
	if (flag->width && !flag->pre)
		ft_processor_width_s(flag, buf);
	if (!flag->width && flag->pre)
		ft_processor_pre_s(flag, buf);
	if (flag->width && flag->pre > 0 && flag->minus)
		ft_processor_pre_weidth_min_s(flag, buf);
	if (flag->width && flag->pre && !flag->minus)
		ft_processor_pre_weidth_s(flag, buf);
	if (flag->width && flag->pre < 0 && flag->minus)
		chastch(flag, buf);
}
