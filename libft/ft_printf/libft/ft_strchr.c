/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 20:58:47 by sjacki            #+#    #+#             */
/*   Updated: 2021/01/14 23:55:44 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

char	*ft_strchr(char *s, int c)
{
	char	*x;
	int		walk;

	walk = 0;
	x = NULL;
	while (s[walk] != 0)
	{
		if (s[walk] == c)
		{
			x = &s[walk];
			return (x);
		}
		walk++;
	}
	if (s[walk] == c)
		x = &s[walk];
	return (x);
}
