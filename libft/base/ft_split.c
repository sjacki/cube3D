/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 12:57:00 by sjacki            #+#    #+#             */
/*   Updated: 2021/01/26 19:54:29 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

char		**freesplit(char **pnt, size_t walk_pnt)
{
	size_t		walk;

	walk = 0;
	while (walk <= walk_pnt)
	{
		free(pnt[walk]);
		walk++;
	}
	free(pnt);
	return (NULL);
}

size_t		seach_word(char const *s, int c)
{
	size_t			walk;
	size_t			count;

	walk = 0;
	count = 0;
	while (s[walk])
	{
		if (s[walk] != c && (s[walk + 1] == c || s[walk + 1] == 0))
			count++;
		walk++;
	}
	return (count);
}

size_t		bword(const char *s, int c)
{
	size_t		walk;

	walk = 0;
	while (s[walk] == c)
		walk++;
	return (walk);
}

size_t		lenword(const char *s, int c)
{
	size_t		walk;

	walk = 0;
	while (s[walk] != c && s[walk])
		walk++;
	return (walk);
}

char		**ft_split(char const *s, char c)
{
	char		**pnt;
	size_t		len;
	size_t		walk;
	size_t		bch;

	walk = 0;
	if (s == NULL)
		return (NULL);
	len = seach_word(s, c);
	if (!(pnt = (char **)malloc((len + 1) * sizeof(char *))))
		return (NULL);
	pnt[len] = 0;
	while (len > walk)
	{
		bch = bword(s, c);
		if (!(pnt[walk] = ft_substr(s, bch, lenword(s + bch, c))))
			return (freesplit(pnt, len));
		s = s + lenword(s + bch, c) + bch;
		walk++;
	}
	return (pnt);
}
