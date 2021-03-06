/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandr <alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 14:29:29 by sjacki            #+#    #+#             */
/*   Updated: 2021/05/12 00:24:06 by alexandr         ###   ########.fr       */
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
			exit(1);
		cor_env_base(map, x, y);
	}
	return (1);
}

static int	p_gnl_map(t_struct *config, char *line, char **map, int longer_line)
{
	int			y;

	y = 0;
	if (config->conf_count - 1 <= config->x)
	{
		map_pars(config, line, map, longer_line);
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
	else
		free(line);
	return (1);
}

static void	valid_map_base(t_struct *config, char **map, int x, int y)
{
	char	*correct;
	char	*player;

	if (config->flag_floor != 1 && ft_putstr_fd("Error\n\
Floor color is not valid\n", 1))
		exit(1);
	if (config->flag_ceilling != 1 && ft_putstr_fd("Error\n\
Ceiling color is not valid\n", 1))
		exit(1);
	player = "NSEW";
	correct = " +102NSEW";
	if (ft_strrchr(player, map[x][y]))
	{
		config->player_count++;
		config->x_pl = x + 0.33f;
		config->y_pl = y + 0.33f;
		config->v_pl = map[x][y];
	}
	if (ft_strrchr(correct, map[x][y]))
		cor_env(map, x, y);
	else
	{
		ft_putstr_fd("Error\nMap have not valid character\n", 1);
		exit(1);
	}
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
			valid_map_base(config, map, x, y);
			y++;
		}
		x++;
	}
	if (config->player_count != 1)
	{
		ft_putstr_fd("Error\nMap have not correct count players\n", 1);
		exit(1);
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
	close(fd);
	endmap(line, &map, longer_line);
	vmap(config, ft_split(map, '\n'));
	free(map);
	return (1);
}
