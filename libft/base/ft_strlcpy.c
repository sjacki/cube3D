/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:02:14 by sjacki            #+#    #+#             */
/*   Updated: 2021/01/26 19:54:45 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t x;

	x = 0;
	if (dst == NULL && src == NULL)
		return (0);
	if (dstsize != 0)
	{
		while (dstsize - 1 > x && src[x] != 0)
		{
			dst[x] = src[x];
			x++;
		}
		dst[x] = '\0';
	}
	x = 0;
	while (src[x] != 0)
		x++;
	return (x);
}
