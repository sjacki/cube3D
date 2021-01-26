/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 20:40:30 by sjacki            #+#    #+#             */
/*   Updated: 2021/01/26 19:55:25 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

size_t		trimbegin(char const *s1, char const *set)
{
	size_t			walk;
	size_t			wal;
	size_t			bwalk;

	walk = 0;
	wal = 0;
	while (s1[walk])
	{
		bwalk = walk;
		while (set[wal])
		{
			if ((size_t)(ft_strchr((char*)s1 + walk, set[wal]) - s1) == walk)
			{
				walk++;
				break ;
			}
			wal++;
		}
		wal = 0;
		if (walk == bwalk)
			break ;
	}
	return (walk);
}

size_t		trimlast(char const *s1, char const *set)
{
	size_t			walk;
	size_t			wal;
	size_t			lwalk;

	walk = ft_strlen(s1) - 1;
	wal = 0;
	while (walk)
	{
		lwalk = walk;
		while (set[wal])
		{
			if ((size_t)(ft_strchr((char*)s1 + walk, set[wal]) - s1) == walk)
			{
				walk--;
				break ;
			}
			wal++;
		}
		wal = 0;
		if (walk == lwalk)
			break ;
	}
	return (walk);
}

char		*fielres(char const *s1, size_t bcut, size_t lcut, char *res)
{
	size_t			walk;
	size_t			walk1;

	walk = 0;
	walk1 = 0;
	while (s1[walk])
	{
		if (walk >= bcut && walk <= lcut)
		{
			res[walk1] = s1[walk];
			walk1++;
		}
		walk++;
	}
	res[walk1] = '\0';
	return (res);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t			bcut;
	size_t			lcut;
	char			*res;

	if (s1 == NULL || set == NULL)
		return (NULL);
	bcut = trimbegin(s1, set);
	lcut = trimlast(s1, set);
	if (bcut == ft_strlen(s1))
		return (ft_strdup(""));
	res = (char *)malloc(ft_strlen(s1) - bcut - (ft_strlen(s1) - lcut) + 2);
	if (res == NULL)
		return (NULL);
	return (fielres(s1, bcut, lcut, res));
}
