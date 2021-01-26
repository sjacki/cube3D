/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 23:40:31 by sjacki            #+#    #+#             */
/*   Updated: 2021/01/17 23:56:14 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int		ft_processor(t_struct *flag, va_list ap)
{
	if (flag->type == 'd' || flag->type == 'i')
		ft_processor_d_i(flag, ap);
	if (flag->type == 'u')
		ft_processor_u(flag, ap);
	if (flag->type == 'c')
		ft_processor_c(flag, ap);
	if (flag->type == 's')
		ft_processor_s(flag, ap);
	if (flag->type == '%')
		ft_processer_percent(flag);
	if (flag->type == 'x' || flag->type == 'X')
		ft_processor_x(flag, ap);
	if (flag->type == 'p')
		ft_processor_p(flag, ap);
	return (1);
}
