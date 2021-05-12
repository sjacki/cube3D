/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandr <alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 18:06:10 by sjacki            #+#    #+#             */
/*   Updated: 2021/05/12 22:14:42 by alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cube3d.h"

int		parser_texture_no(char *line, t_struct *config, int i)
{
	if (config->no_texture)
		ft_err("Error\nNot valid NO tex\n");
	line += 2;
	if (*line != ' ')
		ft_err("Error\nNot valid NO tex\n");
	while (*line == ' ' || *line == '	')
		line++;
	if (*line != '.')
		ft_err("Error\nNot valid NO tex\n");
	while (line[i] != '.')
		i++;
	if (line[i + 1] == 'x' && line[i + 2] == 'p' && line[i + 3] == 'm')
		i += 4;
	config->no_texture = ft_substr(line, 0, (size_t)i);
	if (open(config->no_texture, O_RDONLY) < 0)
		ft_err("Error\nNot valid NO tex\n");
	while (line[i])
	{
		if (line[i] != ' ')
			ft_err("Error\nNot valid NO tex\n");
		i++;
	}
	config->mp5++;
	return (1);
}

int		parser_texture_so(char *line, t_struct *config, int i)
{
	if (config->so_texture)
		ft_err("Error\nNot valid SO tex\n");
	line += 2;
	if (*line != ' ')
		ft_err("Error\nNot valid SO tex\n");
	while (*line == ' ' || *line == '	')
		line++;
	if (*line != '.')
		ft_err("Error\nNot valid SO tex\n");
	while (line[i] != '.')
		i++;
	if (line[i + 1] == 'x' && line[i + 2] == 'p' && line[i + 3] == 'm')
		i += 4;
	config->so_texture = ft_substr(line, 0, (size_t)i);
	if (open(config->so_texture, O_RDONLY) < 0)
		ft_err("Error\nNot valid SO tex\n");
	while (line[i])
	{
		if (line[i] != ' ')
			ft_err("Error\nNot valid SO tex\n");
		i++;
	}
	config->mp5++;
	return (1);
}

int		parser_texture_we(char *line, t_struct *config, int i)
{
	if (config->we_texture)
		ft_err("Error\nNot valid WE tex\n");
	line += 2;
	if (*line != ' ')
		ft_err("Error\nNot valid WE tex\n");
	while (*line == ' ' || *line == '	')
		line++;
	if (*line != '.')
		ft_err("Error\nNot valid WE tex\n");
	while (line[i] != '.')
		i++;
	if (line[i + 1] == 'x' && line[i + 2] == 'p' && line[i + 3] == 'm')
		i += 4;
	config->we_texture = ft_substr(line, 0, (size_t)i);
	if (open(config->we_texture, O_RDONLY) < 0)
		ft_err("Error\nNot valid WE tex\n");
	while (line[i])
	{
		if (line[i] != ' ')
			ft_err("Error\nNot valid WE tex\n");
		i++;
	}
	config->mp5++;
	return (1);
}

int		parser_texture_ea(char *line, t_struct *config, int i)
{
	if (config->ea_texture)
		ft_err("Error\nNot valid EA tex\n");
	line += 2;
	if (*line != ' ')
		ft_err("Error\nNot valid EA tex\n");
	while (*line == ' ' || *line == '	')
		line++;
	if (*line != '.')
		ft_err("Error\nNot valid EA tex\n");
	while (line[i] != '.')
		i++;
	if (line[i + 1] == 'x' && line[i + 2] == 'p' && line[i + 3] == 'm')
		i += 4;
	config->ea_texture = ft_substr(line, 0, (size_t)i);
	if (open(config->ea_texture, O_RDONLY) < 0)
		ft_err("Error\nNot valid EA tex\n");
	while (line[i])
	{
		if (line[i] != ' ')
			ft_err("Error\nNot valid EA tex\n");
		i++;
	}
	config->mp5++;
	return (1);
}

int		parser_texture_s(char *line, t_struct *config, int i)
{
	if (config->s_texture)
		ft_err("Error\nNot valid S tex\n");
	line += 1;
	if (*line != ' ')
		ft_err("Error\nNot valid S tex\n");
	while (*line == ' ' || *line == '	')
		line++;
	if (*line != '.')
		ft_err("Error\nNot valid S tex\n");
	while (line[i] != '.')
		i++;
	if (line[i + 1] == 'x' && line[i + 2] == 'p' && line[i + 3] == 'm')
		i += 4;
	config->s_texture = ft_substr(line, 0, (size_t)i);
	if (open(config->s_texture, O_RDONLY) < 0)
		ft_err("Error\nNot valid S tex\n");
	while (line[i])
	{
		if (line[i] != ' ')
			ft_err("Error\nNot valid S tex\n");
		i++;
	}
	config->mp5++;
	return (1);
}
