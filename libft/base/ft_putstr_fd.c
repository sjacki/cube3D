/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 20:53:28 by sjacki            #+#    #+#             */
/*   Updated: 2021/01/26 19:54:26 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

void		ft_putstr_fd(char *s, int fd)
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
}
