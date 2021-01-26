/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 20:16:35 by sjacki            #+#    #+#             */
/*   Updated: 2021/01/26 19:55:04 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

int		ft_strncmp(const char *str1, const char *str2, size_t n)
{
	const unsigned char *s1;
	const unsigned char *s2;
	unsigned int		walk;

	walk = 0;
	s1 = (const unsigned char*)str1;
	s2 = (const unsigned char*)str2;
	while ((s1[walk] != 0 || s2[walk] != 0) && walk < n)
	{
		if (s1[walk] != s2[walk])
			return (s1[walk] - s2[walk]);
		walk++;
	}
	return (0);
}
