/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 14:29:29 by sjacki            #+#    #+#             */
/*   Updated: 2021/02/17 09:09:05 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cube3d.h"

static int	cor_env(char **map, int x, int y)
{
	char	*valid;

	valid = "02NSEW";
	if (ft_strrchr(valid, map[x][y]))
	{
		if (y == 0 && ft_putstr_fd("Error\nMap is not valid\n", 1))
			return (0);
		if (!cor_env_base(map, x, y))
			return (0);
	}
	return (1);
}

static int	p_gnl_map(t_struct *config, char *line, char **map, int longer_line)
{
	int			y;

	y = 0;
	if (config->conf_count - 1 <= config->x)
	{
		if (ft_strlen(line) > 0 && !config->trig && ++config->trig)
		{
			while (longer_line + 1 > y++)
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
		}
		if (!ft_strlen(line) && config->trig)
		{
			ft_putstr_fd("Error\nMap have empty line\n", 1);
			exit(1);
		}
		if (!(*map = ft_strjoin(*map, line)))
		{
			ft_putstr_fd("Error\nMalloc error\n", 1);
			exit(1);
		}
		y = ft_strlen(line);
		while (longer_line + 2 > ++y && ft_strlen(line))
			if (!(*map = ft_strjoin(*map, " ")))
			{
				ft_putstr_fd("Error\nMalloc error\n", 1);
				exit(1);
			}
		if (config->trig)
			if (!(*map = ft_strjoin(*map, "\n")))
			{
				ft_putstr_fd("Error\nMalloc error\n", 1);
				exit(1);
			}
		free(line);
	}
	return (1);
}

static int	valid_map_base(t_struct *config, char **map, int x, int y)
{
	char	*correct;
	char	*player;

	if (config->flag_floor != 1 && ft_putstr_fd("Error\n\
Floor color is not valid\n", 1))
		return (0);
	if (config->flag_ceilling != 1 && ft_putstr_fd("Error\n\
Ceiling color is not valid\n", 1))
		return (0);
	player = "NSEW";
	correct = " +102NSEW";
	if (ft_strrchr(player, map[x][y]) && config->player_count++)
		config->player = map[x][y];
	if (ft_strrchr(correct, map[x][y]))
	{
		if (!cor_env(map, x, y))
			return (0);
	}
	else
	{
		ft_putstr_fd("Error\nMap have not valid character\n", 1);
		return (0);
	}
	return (1);
}

static int	vmap(t_struct *config, char **map)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	config->player_count = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (!valid_map_base(config, map, x, y))
				return (0);
			y++;
		}
		x++;
	}
	if (config->player_count != 1)
	{
		ft_putstr_fd("Error\nMap have not correct count players\n", 1);
		return (0);
	}
	config->map = map;
	return (1);
}

int			parser_map(t_struct *config, int longer_line)
{
	char		*line;
	char		*map;
	int			err_gnl;
	int			fd;

	config->x = 0;
	if (!(map = ft_strdup("")) && ft_putstr_fd("Error\nMalloc error\n", 1))
		exit(1);
	fd = open(config->argv1, O_RDONLY);
	while ((err_gnl = get_next_line(fd, &line)))
	{
		if (err_gnl < 0 && ft_putstr_fd("Error\nСould not read the file\n", 1))
			exit(1);
		p_gnl_map(config, line, &map, longer_line);
		config->x++;
	}
	endmap(line, &map, longer_line);
	vmap(config, ft_split(map, '\n'));
	free(map);
	return (1);
}
