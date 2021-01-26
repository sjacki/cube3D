/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 20:26:29 by sjacki            #+#    #+#             */
/*   Updated: 2021/01/26 19:54:40 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	walk;
	size_t	walk1;
	char	*ptr;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	walk1 = 0;
	walk = ft_strlen(s1) + ft_strlen(s2);
	ptr = (char *)malloc(walk * sizeof(char) + 1);
	if (ptr == NULL)
		return (NULL);
	walk = 0;
	while (s1[walk])
	{
		ptr[walk] = s1[walk];
		walk++;
	}
	while (s2[walk1])
	{
		ptr[walk] = s2[walk1];
		walk++;
		walk1++;
	}
	ptr[walk] = '\0';
	return (ptr);
}
