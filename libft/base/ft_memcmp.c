/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 23:12:58 by sjacki            #+#    #+#             */
/*   Updated: 2021/01/26 19:54:01 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

int			ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			walk;
	unsigned char	*str1;
	unsigned char	*str2;

	walk = 0;
	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	if (n == 0)
		return (0);
	while (walk < n)
	{
		if (str1[walk] != str2[walk])
			return (str1[walk] - str2[walk]);
		walk++;
	}
	return (0);
}
