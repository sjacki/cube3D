/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 17:55:49 by sjacki            #+#    #+#             */
/*   Updated: 2021/01/26 19:53:29 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

void		*ft_calloc(size_t count, size_t size)
{
	char	*pnt;
	size_t	walk;

	walk = 0;
	pnt = malloc(count * size);
	if (pnt == NULL)
		return (NULL);
	while (walk < count * size)
	{
		pnt[walk] = '\0';
		walk++;
	}
	return (pnt);
}
