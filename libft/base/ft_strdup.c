/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 18:52:21 by sjacki            #+#    #+#             */
/*   Updated: 2021/01/26 19:54:36 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

char		*ft_strdup(const char *s1)
{
	size_t	len;
	char	*pnt;
	size_t	walk;

	walk = 0;
	len = ft_strlen(s1) + 1;
	pnt = (char *)malloc(len * sizeof(char));
	if (pnt == NULL)
		return (NULL);
	while (walk < len * sizeof(char))
	{
		pnt[walk] = s1[walk];
		walk++;
	}
	return (pnt);
}
