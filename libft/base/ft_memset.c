/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 18:59:39 by sjacki            #+#    #+#             */
/*   Updated: 2021/01/26 19:54:11 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

void		*ft_memset(void *b, int c, size_t len)
{
	size_t	walk;
	char	*pnt;

	pnt = b;
	walk = 0;
	while (walk < len)
	{
		pnt[walk] = c;
		walk++;
	}
	return (b);
}
