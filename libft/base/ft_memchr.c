/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 22:55:01 by sjacki            #+#    #+#             */
/*   Updated: 2021/01/26 19:53:57 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	size_t			walk;
	unsigned char	ch;
	unsigned char	*str;

	walk = 0;
	if (s == NULL && n == 0)
		return (NULL);
	ch = (unsigned char)c;
	str = (unsigned char*)s;
	while (walk < n)
	{
		if (str[walk] == ch)
			return (&str[walk]);
		walk++;
	}
	return (NULL);
}
