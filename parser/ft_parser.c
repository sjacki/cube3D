/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandr <alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 22:00:25 by sjacki            #+#    #+#             */
/*   Updated: 2021/05/12 11:25:47 by alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cube3d.h"

void			parser_ceilling_color(char *line, t_struct *config, size_t x)
{
	line++;
	if (*line != ' ')
		ft_err("Error\nNot valid ceiling\n");
	while (*line == ' ')
		line++;
	while (x < 3 && ft_isdigit(*line))
	{
		config->ceilling_color[x] = ft_atoi(line);
		if (config->ceilling_color[x] > 255 || config->ceilling_color[x] < 0)
			ft_err("Error\nNot valid ceiling\n");
		while (ft_isdigit(*line))
			line++;
		while (*line == ' ')
			line++;
		if (x == 2 && *line == '\0' && ++config->mp5 && ++config->flag_ceilling)
			return ;
		if (*line == ',')
			line++;
		else if (*line != ',')
			ft_err("Error\nNot valid ceiling\n");
		while (*line == ' ')
			line++;
		x++;
	}
	ft_err("Error\nNot valid ceiling\n");
}

void			parser_floor_color(char *line, t_struct *config, size_t x)
{
	line++;
	if (*line != ' ')
		ft_err("Error\nNot valid floor\n");
	while (*line == ' ')
		line++;
	while (x < 3 && ft_isdigit(*line))
	{
		config->floor_color[x] = ft_atoi(line);
		if (config->floor_color[x] > 255 || config->floor_color[x] < 0)
			ft_err("Error\nNot valid floor\n");
		while (ft_isdigit(*line))
			line++;
		while (*line == ' ')
			line++;
		if (x == 2 && *line == '\0' && ++config->mp5 && ++config->flag_floor)
			return ;
		if (*line == ',')
			line++;
		else if (*line != ',')
			ft_err("Error\nNot valid floor\n");
		while (*line == ' ')
			line++;
		x++;
	}
	ft_err("Error\nNot valid floor\n");
}

void			parser_resolution(char *line, t_struct *config, int i)
{
	ft_res_1(config, &line);
	ft_res_2(config, &line, 0);
	while (ft_isdigit(*line))
		line++;
	while (*line == ' ')
		line++;
	if (ft_isdigit(*line))
	{
		while (ft_isdigit(line[i]))
			i++;
		ft_res_3(config, &line, i);
	}
	else
		ft_err("Error\nNot valid resolution\n");
	if (config->r_height <= 0)
		ft_err("Error\nNot valid resolution\n");
	while (ft_isdigit(*line))
		line++;
	while (*line == ' ')
		line++;
	if (*line == '\0' && ++config->mp5)
		return ;
	ft_err("Error\nNot valid resolution\n");
}

static void		parser_conf(char *line, t_struct *config)
{
	size_t x;

	x = ft_strlen(line);
	while (*line == ' ')
		line++;
	ft_pars_conf_2(config, line, x);
}

int				parser(int fd, t_struct *config)
{
	char		*line;
	int			err_gnl;
	int			longer_line;

	longer_line = 0;
	while ((err_gnl = get_next_line(fd, &line)))
	{
		if (err_gnl == -1 && ft_putstr_fd("Error\nNot valid file\n", 1))
			exit(1);
		if ((config->mp5 != 8 || !config->map_trigger) && ++config->conf_count)
			parser_conf(line, config);
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
