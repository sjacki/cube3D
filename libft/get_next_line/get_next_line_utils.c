/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student-21.school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 14:04:39 by sjacki            #+#    #+#             */
/*   Updated: 2020/12/02 14:04:42 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	size_t		x;

	x = 0;
	if (!s)
		return (0);
	while (s[x])
		x++;
	return (x);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	walk;
	size_t	walk1;
	char	*ptr;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	walk1 = 0;
	walk = ft_strlen(s1) + ft_strlen(s2);
	if (!(ptr = (char *)malloc(walk * sizeof(char) + 1)))
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
	free((void*)s1);
	return (ptr);
}

char		*ft_strchr(char *s, int c)
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
