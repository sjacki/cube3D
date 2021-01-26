/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 14:00:19 by sjacki            #+#    #+#             */
/*   Updated: 2021/01/20 02:46:56 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

static int	parser_type(const char **format, t_struct *flag)
{
	char	*pnt;
	char	*type;

	type = "cspdiuxX%";
	if ((pnt = ft_strchr(type, **format)) && **format)
	{
		flag->type = *pnt;
		++*format;
		return (1);
	}
	return (0);
}

static void	parser_flag(const char **format, t_struct *flag)
{
	while (**format == '-' || **format == '0')
	{
		if (**format == '-')
			flag->minus = 1;
		if (**format == '0')
			flag->zero = 1;
		++*format;
	}
	if (flag->minus && flag->zero)
		flag->zero = 0;
}

static void	parser_precision(const char **format, t_struct *flag, va_list ap)
{
	if (**format == '.')
	{
		flag->point++;
		++*format;
		if (**format == '*')
		{
			flag->star++;
			flag->pre = va_arg(ap, int);
			++*format;
		}
		if (ft_isdigit(**format))
		{
			flag->pre = ft_atoi(*format);
			while (ft_isdigit(**format))
				++*format;
		}
		if (flag->pre < 0)
		{
			flag->pre = 0;
			flag->pmin++;
		}
	}
}

static void	parser_width(const char **format, t_struct *flag, va_list ap)
{
	if (**format == '*')
	{
		flag->width = va_arg(ap, int);
		++*format;
	}
	else if (ft_isdigit(**format))
	{
		flag->width = ft_atoi(*format);
		while (ft_isdigit(**format))
			++*format;
	}
	if (flag->width < 0 && (flag->width *= -1) && (flag->minus = 1))
		flag->zero = 0;
}

int			ft_parcer(const char **format, t_struct *flag, va_list ap)
{
	parser_flag(format, flag);
	parser_width(format, flag, ap);
	parser_precision(format, flag, ap);
	if (!parser_type(format, flag))
		return (0);
	return (1);
}
