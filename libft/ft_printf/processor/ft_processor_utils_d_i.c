/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor_utils_d_i.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 07:13:41 by sjacki            #+#    #+#             */
/*   Updated: 2021/01/20 02:47:22 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void		ft_width_point(t_struct *flag)
{
	int	x;

	x = 0;
	while (flag->width > x && write(1, " ", 1))
	{
		x++;
		flag->len++;
	}
}

void		putminus(t_struct *flag, int *buf)
{
	if (*buf < 0 && *buf != -2147483648)
	{
		write(1, "-", 1);
		*buf *= -1;
		flag->len++;
		flag->width--;
	}
}

void		chastch(t_struct *flag, char *buf)
{
	int	x;

	x = 0;
	ft_putstr_fd(buf, 1, flag);
	while (flag->width - (int)ft_strlen(buf) > x)
	{
		write(1, " ", 1);
		x++;
	}
}
