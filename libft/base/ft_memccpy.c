/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 20:23:00 by sjacki            #+#    #+#             */
/*   Updated: 2021/01/26 19:53:54 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				walk;
	unsigned char		*a;
	unsigned char		*b;
	unsigned char		ch;

	ch = (unsigned char)c;
	a = (unsigned char*)dst;
	b = (unsigned char*)src;
	walk = 0;
	if (a == NULL && b == NULL)
		return (NULL);
	while (walk < n)
	{
		a[walk] = b[walk];
		if (b[walk] == ch)
			return (&a[walk + 1]);
		walk++;
	}
	return (NULL);
}
