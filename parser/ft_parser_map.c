/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 14:29:29 by sjacki            #+#    #+#             */
/*   Updated: 2021/02/07 00:14:53 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cube3d.h"

static int	cor_env(char **map, int x, int y)
{
	char	*valid;

	valid = "02NSEW";
	if (ft_strrchr(valid, map[x][y]))
	{
		if (y == 0 && ft_putstr_fd("карта не валидна\n", 1))
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
	if (config->conf_count <= config->x)
	{
		if (config->conf_count == config->x)
		{
			while (longer_line + 1 > y++)
				*map = ft_strjoin(*map, " ");
			*map = ft_strjoin(*map, "\n");
		}
		if (!ft_strlen(line))
		{
			while (longer_line + 1 > y++)
				line = ft_strjoin(line, " ");
		}
		*map = ft_strjoin(*map, line);
		y = ft_strlen(line);
		while (longer_line + 2 > ++y && ft_strlen(line))
			*map = ft_strjoin(*map, " ");
		*map = ft_strjoin(*map, "\n");
	}
	free(line);
	return (1);
}

static int	valid_map_base(t_struct *config, char **map, int x, int y)
{
	char	*correct;
	char	*player;

	if (config->flag_floor != 1 && ft_putstr_fd("ошибка цвета пола\n", 1))
		return (0);
	if (config->flag_ceilling != 1 && ft_putstr_fd("ошибка цвета потолка\n", 1))
		return (0);
	player = "NSEW";
	correct = " 	+102NSEW";
	if (ft_strrchr(player, map[x][y]) && config->player_count++)
		config->player = map[x][y];
	if (ft_strrchr(correct, map[x][y]))
	{
		if (!cor_env(map, x, y))
			return (0);
	}
	else
	{
		ft_putstr_fd("не опознаный символ в карте\n", 1);
		return (0);
	}
	return (1);
}

static int	valid_map(t_struct *config, char **map)
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
		ft_putstr_fd("неверное количество игроков\n", 1);
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
	map = ft_strdup("");
	fd = open(config->argv1, O_RDONLY);
	while ((err_gnl = get_next_line(fd, &line)))
	{
		if (err_gnl < 0 && ft_putstr_fd("не удалось считать файл\n", 1))
			return (0);
		if (!p_gnl_map(config, line, &map, longer_line))
		{
			ft_putstr_fd("не удалось выделить память под карту\n", 1);
			return (0);
		}
		config->x++;
	}
	parser_end_map(line, &map, longer_line);
	if (!valid_map(config, ft_split(map, '\n')))
		return (0);
	free(map);
	return (1);
}
