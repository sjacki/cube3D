/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 21:06:25 by sjacki            #+#    #+#             */
/*   Updated: 2021/01/26 19:54:18 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

void		ft_putendl_fd(char *s, int fd)
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
		write(fd, "\n", 1);
	}
}
