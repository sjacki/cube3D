/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 20:13:24 by sjacki            #+#    #+#             */
/*   Updated: 2021/01/26 19:54:05 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		walk;
	char		*a;
	const char	*b;

	a = dst;
	b = src;
	walk = 0;
	if (a == NULL && b == NULL)
		return (NULL);
	while (walk < n)
	{
		a[walk] = b[walk];
		walk++;
	}
	return (dst);
}
