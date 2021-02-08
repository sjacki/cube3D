/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_map_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 23:03:41 by sjacki            #+#    #+#             */
/*   Updated: 2021/02/08 18:05:54 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cube3d.h"

int			cor_env_base(char **map, int x, int y)
{
	int		a;
	int		b;
	char	*notcorrect;

	notcorrect = " ";
	a = -1;
	b = -1;
	while (a + b != 4)
	{
		b = -1;
		while (b != 2)
		{
			if (ft_strrchr(notcorrect, map[x + a][y + b]))
			{
				ft_putstr_fd("карта не валидна\n", 1);
				return (0);
			}
			b++;
		}
		a++;
	}
	return (1);
}

int			endmap(char *line, char **map, int longer_line)
{
	int y;

	*map = ft_strjoin(*map, line);
	if (!(y = ft_strlen(line)) && ft_putstr_fd("в конце карты \\n\n", 1))
		return (0);
	while (longer_line + 2 > ++y)
		*map = ft_strjoin(*map, " ");
	*map = ft_strjoin(*map, "\n");
	y = 0;
	while (longer_line + 1 > y++)
		*map = ft_strjoin(*map, " ");
	free(line);
	return (1);
}
