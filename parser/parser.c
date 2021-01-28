/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 22:00:25 by sjacki            #+#    #+#             */
/*   Updated: 2021/01/28 18:56:44 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cube3d.h"

static int		parser_resolution(char *line, t_struct *config)
{
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
	if (*line == '\0')
	{
		config->mp5++;
		return (1);
	}
	return (0);
}

static int		parser_conf(char *line, t_struct *config)
{
	while (*line == ' ')
		line++;
	if (*line == 'R')
		if (!parser_resolution(line, config))
		{
			ft_putstr_fd("не правильноe разрешение\n", 1);
			return (0);
		}
	if (*line == 'N' && *(line + 1) == 'O')
		if (!parser_texture_no(line, config))
			return (0);
	if (*line == 'S' && *(line + 1) == 'O')
		if (!parser_texture_so(line, config))
			return (0);
	if (*line == 'W' && *(line + 1) == 'E')
		if (!parser_texture_we(line, config))
			return (0);
	if (*line == 'E' && *(line + 1) == 'A')
		if (!parser_texture_ea(line, config))
			return (0);
	if (*line == 'S' && *(line + 1) != 'O')
		if (!parser_texture_s(line, config))
			return (0);
	return (1);
}

int				parser(int fd)
{
	char		*line;
	t_struct	config;

	config.mp5 = 0;
	while (get_next_line(fd, &line))
	{
		if (!(parser_conf(line, &config)))
		{
			free(line);
			return (0);
		}
		free(line);
	}
	if (config.mp5 != 6)
	{
		ft_putstr_fd("не достаточно параметров в конфиг файле\n", 1);
		return (0);
	}
	ft_printf("resolution: %d x %d\n", config.r_width, config.r_height);
	ft_printf("texture NO: %s\n", config.no_texture);
	ft_printf("texture SO: %s\n", config.so_texture);
	ft_printf("texture WE: %s\n", config.we_texture);
	ft_printf("texture EA: %s\n", config.ea_texture);
	ft_printf("texture  S: %s\n", config.s_texture);
	ft_printf("mp5:  %u\n", config.mp5);
	return (1);
}
