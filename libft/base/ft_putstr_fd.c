/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 20:53:28 by sjacki            #+#    #+#             */
/*   Updated: 2021/01/28 20:01:58 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

int		ft_putstr_fd(char *s, int fd)
{
	size_t	walk;

	walk = 0;
	if (s != NULL)
	{
		while (s[walk])
		{
			write(fd, &s[walk], 1);
			walk++;
		}
	}
	return (walk);
}
