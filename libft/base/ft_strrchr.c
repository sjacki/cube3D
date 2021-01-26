/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 20:11:17 by sjacki            #+#    #+#             */
/*   Updated: 2021/01/26 19:55:22 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*x;
	int		walk;

	walk = 0;
	x = NULL;
	while (s[walk] != 0)
	{
		if (s[walk] == c)
			x = (char *)&s[walk];
		walk++;
	}
	if (s[walk] == c)
		x = (char *)&s[walk];
	return (x);
}
