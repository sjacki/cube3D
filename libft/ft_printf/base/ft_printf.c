/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 20:27:23 by sjacki            #+#    #+#             */
/*   Updated: 2021/01/20 02:45:02 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

static int			write_other(t_struct *flag, const char **format)
{
	while (**format && **format != '%')
	{
		write(1, *format, 1);
		++*format;
		++flag->len;
	}
	if (**format == '%')
	{
		++*format;
		if (**format == ' ')
		{
			write(1, " ", 1);
			++*format;
			++flag->len;
		}
	}
	if (!**format)
		return (0);
	return (1);
}

static void			init_zero_struct(t_struct *flag)
{
	flag->type = 0;
	flag->minus = 0;
	flag->zero = 0;
	flag->width = 0;
	flag->pre = 0;
	flag->point = 0;
	flag->star = 0;
	flag->pmin = 0;
	flag->p = 0;
	flag->widmin = 0;
}

int					ft_printf(const char *format, ...)
{
	va_list			ap;
	t_struct		flag;

	if (!format)
		return (-1);
	va_start(ap, format);
	flag.len = 0;
	init_zero_struct(&flag);
	while (write_other(&flag, &format))
	{
		if (!ft_parcer(&format, &flag, ap))
		{
			va_end(ap);
			return (-1);
		}
		if (!ft_processor(&flag, ap))
		{
			va_end(ap);
			return (-1);
		}
		init_zero_struct(&flag);
	}
	va_end(ap);
	return (flag.len);
}
