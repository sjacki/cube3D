/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_other.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandr <alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 01:11:27 by alexandr          #+#    #+#             */
/*   Updated: 2021/05/12 22:15:42 by alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cube3d.h"

void			ft_pars_conf_2(t_struct *config, char *line, int x)
{
	if (ft_strlen(line) && ft_strrchr("102", *line) && ++config->map_trigger)
	{
		if (config->mp5 != 8)
			ft_err("Error\nNot valid conf.\n");
	}
	else if (*line == 'R')
		parser_resolution(line, config, 0);
	else if (*line == 'N' && *(line + 1) == 'O')
		parser_texture_no(line, config, 1);
	else if (*line == 'S' && *(line + 1) == 'O')
		parser_texture_so(line, config, 1);
	else if (*line == 'W' && *(line + 1) == 'E')
		parser_texture_we(line, config, 1);
	else if (*line == 'E' && *(line + 1) == 'A')
		parser_texture_ea(line, config, 1);
	else if (*line == 'S' && *(line + 1) != 'O')
		parser_texture_s(line, config, 1);
	else if (*line == 'F')
		parser_floor_color(line, config, 0);
	else if (*line == 'C')
		parser_ceilling_color(line, config, 0);
	else if (x > 0)
		ft_err("Error\nNot valid conf.\n");
}

void			ft_res_1(t_struct *config, char **line)
{
	if (config->r_height && config->r_width)
		ft_err("Error\nNot valid resolution\n");
	*line += 1;
	if (**line != ' ')
		ft_err("Error\nNot valid resolution\n");
	while (**line == ' ')
		*line += 1;
}

void			ft_res_2(t_struct *config, char **line, int i)
{
	if (ft_isdigit(**line))
	{
		while (ft_isdigit(**line + i))
			i++;
		while (ft_isdigit(**line))
		{
			if (config->r_width > 1073741823)
			{
				config->r_width = 1073741823;
				while (ft_isdigit(**line))
					*line += 1;
				break ;
			}
			config->r_width = config->r_width + ((**line - 48)\
								* powerdex(i - 1));
			i--;
			*line += 1;
		}
	}
	else
		ft_err("Error\nNot valid resolution\n");
	if (config->r_width <= 0)
		ft_err("Error\nNot valid resolution\n");
}

void			ft_res_3(t_struct *config, char **line, int i)
{
	while (ft_isdigit(**line))
	{
		if (config->r_height > 1073741823)
		{
			config->r_height = 1073741823;
			while (ft_isdigit(**line))
				*line += 1;
			break ;
		}
		config->r_height = config->r_height + ((**line - 48)\
							* powerdex(i - 1));
		i--;
		*line += 1;
	}
}
