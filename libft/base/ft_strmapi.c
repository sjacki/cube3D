/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 20:08:04 by sjacki            #+#    #+#             */
/*   Updated: 2021/01/26 19:54:52 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

char		*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	unsigned int	walk;
	char			*pnt;

	if (s == NULL)
		return (NULL);
	walk = 0;
	pnt = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (pnt == NULL)
		return (NULL);
	while (s[walk])
	{
		pnt[walk] = f(walk, s[walk]);
		walk++;
	}
	pnt[walk] = '\0';
	return (pnt);
}
