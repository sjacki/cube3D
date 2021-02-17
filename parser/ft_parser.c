/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 22:00:25 by sjacki            #+#    #+#             */
/*   Updated: 2021/02/17 08:15:59 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cube3d.h"

static int		parser_ceilling_color(char *line, t_struct *config)
{
	size_t x;

	x = 0;
	line++;
	while (*line == ' ')
		line++;
	while (x < 3 && ft_isdigit(*line))
	{
		config->ceilling_color[x] = ft_atoi(line);
		while (ft_isdigit(*line))
			line++;
		while (*line == ' ')
			line++;
		if (x == 2 && *line == '\0' && ++config->mp5 && ++config->flag_ceilling)
			return (1);
		if (*line == ',')
			line++;
		else if (*line != ',' && ft_putstr_fd("не прав. цвет потолка\n", 1))
			return (0);
		while (*line == ' ')
			line++;
		x++;
	}
	ft_putstr_fd("не правильно задан цвет потолка\n", 1);
	return (0);
}

static int		parser_floor_color(char *line, t_struct *config)
{
	size_t x;

	x = 0;
	line++;
	while (*line == ' ')
		line++;
	while (x < 3 && ft_isdigit(*line))
	{
		config->floor_color[x] = ft_atoi(line);
		while (ft_isdigit(*line))
			line++;
		while (*line == ' ')
			line++;
		if (x == 2 && *line == '\0' && ++config->mp5 && ++config->flag_floor)
			return (1);
		if (*line == ',')
			line++;
		else if (*line != ',' && ft_putstr_fd("не правильный цвет пола\n", 1))
			return (0);
		while (*line == ' ')
			line++;
		x++;
	}
	ft_putstr_fd("не правильно задан цвет пола\n", 1);
	return (0);
}

static int		parser_resolution(char *line, t_struct *config)
{
	if (config->r_height && config->r_width)
		return (0);
	line++;
	while (*line == ' ')
		line++;
	if (ft_isdigit(*line))
		config->r_width = ft_atoi(line);
	else
		return (0);
	while (ft_isdigit(*line))
		line++;
	while (*line == ' ')
		line++;
	if (ft_isdigit(*line))
		config->r_height = ft_atoi(line);
	else
		return (0);
	while (ft_isdigit(*line))
		line++;
	while (*line == ' ')
		line++;
	if (*line == '\0' && ++config->mp5)
		return (1);
	return (0);
}

static int		parser_conf(char *line, t_struct *config)
{
	while (*line == ' ')
		line++;
	if (ft_strlen(line) && ft_strrchr("102", *line) && ++config->map_trigger)
		if (config->mp5 != 8 && ft_putstr_fd("не все парам. были найдены\n", 1))
			return (0);
	if (*line == 'R' && !parser_resolution(line, config))
	{
		ft_putstr_fd("не правильноe разрешение\n", 1);
		return (0);
	}
	if (*line == 'N' && *(line + 1) == 'O' && !parser_texture_no(line, config))
		return (0);
	if (*line == 'S' && *(line + 1) == 'O' && !parser_texture_so(line, config))
		return (0);
	if (*line == 'W' && *(line + 1) == 'E' && !parser_texture_we(line, config))
		return (0);
	if (*line == 'E' && *(line + 1) == 'A' && !parser_texture_ea(line, config))
		return (0);
	if (*line == 'S' && *(line + 1) != 'O' && !parser_texture_s(line, config))
		return (0);
	if (*line == 'F' && !parser_floor_color(line, config))
		return (0);
	if (*line == 'C' && !parser_ceilling_color(line, config))
		return (0);
	return (1);
}

int				parser(int fd, t_struct *config)
{
	char		*line;
	int			err_gnl;
	int			longer_line;

	longer_line = 0;
	while ((err_gnl = get_next_line(fd, &line)))
	{
		if (err_gnl == -1 && ft_putstr_fd("не удалось считать файл", 1))
			return (-1);
		if ((config->mp5 != 8 || !config->map_trigger) && ++config->conf_count)
			if (!(parser_conf(line, config)))
			{
				free(line);
				return (0);
			}
		if (longer_line < (int)ft_strlen(line) && config->map_trigger)
			longer_line = ft_strlen(line);
		free(line);
	}
	free(line);
	close(fd);
	if (!parser_map(config, longer_line))
		return (0);
	return (1);
}
