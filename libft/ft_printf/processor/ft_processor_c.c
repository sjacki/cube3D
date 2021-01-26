/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 09:47:34 by sjacki            #+#    #+#             */
/*   Updated: 2021/01/20 04:40:09 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	ft_processor_c(t_struct *flag, va_list ap)
{
	char	buf;
	int		x;

	x = 1;
	buf = va_arg(ap, int);
	if (!flag->width && !flag->minus && write(1, &buf, 1))
		flag->len++;
	if (!flag->width && flag->minus && write(1, &buf, 1))
		flag->len++;
	if (flag->width && flag->minus)
	{
		ft_putchar_fd(buf, 1);
		flag->len++;
		while (flag->width > x && write(1, " ", 1) && x++)
			flag->len++;
	}
	else if (flag->width)
	{
		while (flag->width > x && (flag->len += write(1, " ", 1)))
			x++;
		ft_putchar_fd(buf, 1);
		flag->len++;
	}
}
