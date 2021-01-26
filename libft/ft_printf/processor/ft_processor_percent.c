/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor_percent.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 13:59:10 by sjacki            #+#    #+#             */
/*   Updated: 2021/01/17 21:37:25 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	ft_processer_percent(t_struct *flag)
{
	char	buf;
	int		x;

	buf = '%';
	x = 0;
	if (!flag->width && ft_putchar_fd(buf, 1))
		flag->len++;
	if (flag->width)
	{
		if (flag->minus && ft_putchar_fd(buf, 1))
			flag->len++;
		while (flag->width - 1 > x)
		{
			if (flag->zero && ft_putchar_fd('0', 1))
				flag->len++;
			else
			{
				write(1, " ", 1);
				flag->len++;
			}
			x++;
		}
		if (!flag->minus && ft_putchar_fd(buf, 1))
			flag->len++;
	}
}
