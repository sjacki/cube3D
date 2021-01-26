/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:52:04 by sjacki            #+#    #+#             */
/*   Updated: 2021/01/26 19:53:27 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	walk;
	char	*pnt;

	pnt = s;
	walk = 0;
	while (walk < n)
	{
		pnt[walk] = '\0';
		walk++;
	}
}
