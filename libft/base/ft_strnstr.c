/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 21:37:44 by sjacki            #+#    #+#             */
/*   Updated: 2021/01/26 19:55:07 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	walk;
	size_t	lenhay;
	size_t	lenneed;
	char	*hay;

	if (needle == NULL && haystack == NULL)
		return (NULL);
	lenhay = ft_strlen(haystack);
	lenneed = ft_strlen(needle);
	hay = (char *)haystack;
	walk = 0;
	if (lenneed == 0)
		return (hay);
	if (lenhay < lenneed || lenneed > len)
		return (NULL);
	while (walk <= len - lenneed)
	{
		if (ft_strncmp(hay + walk, needle, lenneed) == 0)
			return (hay + walk);
		walk++;
	}
	return (NULL);
}
