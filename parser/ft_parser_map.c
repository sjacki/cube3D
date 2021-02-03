/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 14:29:29 by sjacki            #+#    #+#             */
/*   Updated: 2021/02/03 03:52:30 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cube3d.h"

static int	parser_end_map(char *line, char **map, int longer_line)
{
	int y;

	*map = ft_strjoin(*map, line);
	y = ft_strlen(line);
	while (longer_line + 2 > ++y)
		*map = ft_strjoin(*map, "+");
	*map = ft_strjoin(*map, "\n");
	y = 0;
	while (longer_line + 1 > y++)
		*map = ft_strjoin(*map, "+");
	*map = ft_strjoin(*map, "\n");
	free(line);
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
				*map = ft_strjoin(*map, "+");
			*map = ft_strjoin(*map, "\n");
		}
		*map = ft_strjoin(*map, line);
		y = ft_strlen(line);
		while (longer_line + 2 > ++y)
			*map = ft_strjoin(*map, "+");
		*map = ft_strjoin(*map, "\n");
	}
	free(line);
	return (1);
}

static int	valid_map(t_struct *config, char **map)
{
	int		horz;
	int		vertic;
	int		horz_b;
	int		vertic_b;


	horz = 0;
	vertic = 0;
	while (ft_arrlen(map) > horz)
	{
		ft_printf("%s\n", map[horz]);
		horz++;
	}
		
	horz_b = horz;
	vertic_b = vertic;
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
		if (err_gnl < 0 && ft_putstr_fd("не удалось считать файл", 1))
			return (0);
		if (!p_gnl_map(config, line, &map, longer_line))
		{
			ft_putstr_fd("не удалось выделить память под карту", 1);
			return (0);
		}
		config->x++;
	}
	parser_end_map(line, &map, longer_line);
	if (!valid_map(config, ft_split(map, '\n')))
	{
		ft_putstr_fd("не правильная карта", 1);
		return (0);
	}
	free(map);
	return (1);
}
