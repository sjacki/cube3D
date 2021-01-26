/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 20:53:28 by sjacki            #+#    #+#             */
/*   Updated: 2021/01/17 14:07:32 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int		ft_putstr_fd(char *s, int fd, t_struct *flag)
{
	int	x;

	x = 0;
	if (!s)
		return (0);
	while (s[x])
	{
		flag->len++;
		write(fd, &s[x], 1);
		x++;
	}
	return (1);
}
