/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 20:54:56 by sjacki            #+#    #+#             */
/*   Updated: 2021/01/26 19:54:08 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*a;
	unsigned char		*b;
	unsigned char		*bl;
	unsigned char		*al;

	if (dst == NULL && src == NULL)
		return (NULL);
	a = (unsigned char*)dst;
	b = (unsigned char*)src;
	bl = b + len - 1;
	al = a + len - 1;
	if (a < b)
	{
		while (len--)
			*a++ = *b++;
	}
	else
	{
		while (len--)
			*al-- = *bl--;
	}
	return (dst);
}
