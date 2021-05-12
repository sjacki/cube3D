/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandr <alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 18:06:10 by sjacki            #+#    #+#             */
/*   Updated: 2021/05/11 23:08:04 by alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cube3d.h"

int		parser_texture_no(char *line, t_struct *config)
{
	if (config->no_texture)
		ft_err("Error\nNot valid SO tex\n");
	line += 2;
	if (*line != ' ')
		ft_err("Error\nNot valid SO tex\n");
	while (*line == ' ' || *line == '	')
		line++;
	if (*line == '.')
		config->no_texture = ft_strdup(line);
	else
		ft_err("Error\nNot valid SO tex\n");
	if (open(line, O_RDONLY) < 0)
		ft_err("Error\nNot valid NO tex\n");
	config->mp5++;
	return (1);
}

int		parser_texture_so(char *line, t_struct *config)
{
	if (config->so_texture)
		ft_err("Error\nNot valid SO tex\n");
	line += 2;
	if (*line != ' ')
		ft_err("Error\nNot valid SO tex\n");
	while (*line == ' ' || *line == '	')
		line++;
	if (*line == '.')
		config->so_texture = ft_strdup(line);
	else
		ft_err("Error\nNot valid SO tex\n");
	if (open(line, O_RDONLY) < 0)
		ft_err("Error\nNot valid SO tex\n");
	config->mp5++;
	return (1);
}

int		parser_texture_we(char *line, t_struct *config)
{
	if (config->we_texture)
		ft_err("Error\nNot valid WE tex\n");
	line += 2;
	if (*line != ' ')
		ft_err("Error\nNot valid WE tex\n");
	while (*line == ' ' || *line == '	')
		line++;
	if (*line == '.')
		config->we_texture = ft_strdup(line);
	else
		ft_err("Error\nNot valid WE tex\n");
	if (open(line, O_RDONLY) < 0)
		ft_err("Error\nNot valid WE tex\n");
	config->mp5++;
	return (1);
}

int		parser_texture_ea(char *line, t_struct *config)
{
	if (config->ea_texture)
		ft_err("Error\nNot valid EA tex\n");
	line += 2;
	if (*line != ' ')
		ft_err("Error\nNot valid EA tex\n");
	while (*line == ' ' || *line == '	')
		line++;
	if (*line == '.')
		config->ea_texture = ft_strdup(line);
	else
		ft_err("Error\nNot valid EA tex\n");
	if (open(line, O_RDONLY) < 0)
		ft_err("Error\nNot valid EA tex\n");
	config->mp5++;
	return (1);
}

int		parser_texture_s(char *line, t_struct *config)
{
	if (config->s_texture)
		ft_err("Error\nNot valid S tex\n");
	line++;
	if (*line != ' ')
		ft_err("Error\nNot valid S tex\n");
	while (*line == ' ' || *line == '	')
		line++;
	if (*line == '.')
		config->s_texture = ft_strdup(line);
	else
		ft_err("Error\nNot valid S tex\n");
	if (open(line, O_RDONLY) < 0)
		ft_err("Error\nNot valid S tex\n");
	config->mp5++;
	return (1);
}
