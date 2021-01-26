/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 23:42:34 by sjacki            #+#    #+#             */
/*   Updated: 2021/01/26 19:54:43 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	walk;
	unsigned int	walk1;
	size_t			min_len;

	walk = ft_strlen(dst);
	min_len = dstsize;
	if (dstsize <= ft_strlen(dst))
		return (dstsize + ft_strlen(src));
	if (walk <= dstsize)
		min_len = walk;
	walk1 = 0;
	if (dstsize != 0)
	{
		while (src[walk1] != 0 && walk < dstsize - 1)
		{
			dst[walk] = src[walk1];
			walk++;
			walk1++;
		}
		dst[walk] = '\0';
	}
	return (min_len + ft_strlen(src));
}
