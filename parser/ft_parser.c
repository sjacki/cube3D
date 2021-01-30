/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 22:00:25 by sjacki            #+#    #+#             */
/*   Updated: 2021/01/30 14:46:56 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cube3d.h"

static int		parser_ceilling_color(char *line, t_struct *config)
{
	size_t x;

	x = 0;
	line++;
	while (*line == ' ' || *line == '	')
		line++;
	while (x < 3 && ft_isdigit(*line))
	{
		config->ceilling_color[x] = ft_atoi(line);
		while (ft_isdigit(*line))
			line++;
		if (x == 2 && *line == '\0' && config->mp5++)
			return (1);
		if (*line == ',')
			line++;
		else
		{
			ft_putstr_fd("не правильно задан цвет потолка\n", 1);
			return (0);
		}
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
	while (*line == ' ' || *line == '	')
		line++;
	while (x < 3 && ft_isdigit(*line))
	{
		config->floor_color[x] = ft_atoi(line);
		while (ft_isdigit(*line))
			line++;
		if (x == 2 && *line == '\0' && config->mp5++)
			return (1);
		if (*line == ',')
			line++;
		else
		{
			ft_putstr_fd("не правильно задан цвет пола\n", 1);
			return (0);
		}
		x++;
	}
	ft_putstr_fd("не правильно задан цвет пола\n", 1);
	return (0);
}

static int		parser_resolution(char *line, t_struct *config)
{
	line++;
	while (*line == ' ' || *line == '	')
		line++;
	if (ft_isdigit(*line))
		config->r_width = ft_atoi(line);
	else
		return (0);
	while (ft_isdigit(*line))
		line++;
	while (*line == ' ' || *line == '	')
		line++;
	if (ft_isdigit(*line))
		config->r_height = ft_atoi(line);
	else
		return (0);
	while (ft_isdigit(*line))
		line++;
	while (*line == ' ' || *line == '	')
		line++;
	if (*line == '\0')
	{
		config->mp5++;
		return (1);
	}
	return (0);
}

static int		parser_conf(char *line, t_struct *config)
{
	while (*line == ' ' || *line == '	')
		line++;
	if (*line == '1')
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

	config->conf_count = 0;
	config->mp5 = 0;
	while ((err_gnl = get_next_line(fd, &line)))
	{
		if (err_gnl == -1 && ft_putstr_fd("не удалось считать файл", 1))
			return (-1);
		if (!(parser_conf(line, config)))
		{
			free(line);
			return (0);
		}
		if (config->mp5 == 8)
			break ;
		free(line);
		config->conf_count++;
	}
	free(line);
	close(fd);
	if (!parser_map(config) && ft_putstr_fd("не валидна карта", 1))
		return (0);
	ft_printf("resolution: %d x %d\n", config->r_width, config->r_height);
	ft_printf("texture NO: %s\n", config->no_texture);
	ft_printf("texture SO: %s\n", config->so_texture);
	ft_printf("texture WE: %s\n", config->we_texture);
	ft_printf("texture EA: %s\n", config->ea_texture);
	ft_printf("texture  S: %s\n", config->s_texture);
	ft_printf("floor colr: %d.%d.%d\n", config->floor_color[0], config->floor_color[1], config->floor_color[2]);
	ft_printf("ceill colr: %d.%d.%d\n", config->ceilling_color[0], config->ceilling_color[1], config->ceilling_color[2]);
	ft_printf("mp5:  %u\n", config->mp5);
	return (1);
}
