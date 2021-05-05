/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_map_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandr <alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 23:03:41 by sjacki            #+#    #+#             */
/*   Updated: 2021/03/10 00:07:11 by alexandr         ###   ########.fr       */
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
				ft_putstr_fd("Error\nMap is not valid\n", 1);
				exit(1);
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

	if (!(*map = ft_strjoin(*map, line)))
	{
		ft_putstr_fd("Error\nMalloc error\n", 1);
		exit(1);
	}
	if (!(y = ft_strlen(line)) && ft_putstr_fd("в конце карты \\n\n", 1))
		exit(1);
	while (longer_line + 2 > ++y)
		if (!(*map = ft_strjoin(*map, " ")))
		{
			ft_putstr_fd("Error\nMalloc error\n", 1);
			exit(1);
		}
	if (!(*map = ft_strjoin(*map, "\n")))
	{
		ft_putstr_fd("Error\nMalloc error\n", 1);
		exit(1);
	}
	y = 0;
	while (longer_line + 1 > y++)
		if (!(*map = ft_strjoin(*map, " ")))
		{
			ft_putstr_fd("Error\nMalloc error\n", 1);
			exit(1);
		}
	free(line);
	return (1);
}
