/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other_fun_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandr <alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 23:30:47 by alexandr          #+#    #+#             */
/*   Updated: 2021/05/12 20:34:05 by alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cube3d.h"

void			ft_resolution_screen(t_struct *config)
{
	int wid;
	int hi;

	mlx_get_screen_size(config->mlx, &wid, &hi);
	if (!config->fl_screen && (config->r_width > wid || config->r_height > hi))
	{
		config->r_width = wid;
		config->r_height = hi;
	}
	if (config->fl_screen && (config->r_width > wid || config->r_height > hi))
	{
		config->r_width = 10000;
		config->r_height = 10000;
	}
}

void			ft_init_mlx(t_struct *config)
{
	if (!config->fl_screen)
	{
		config->mlx_win_3d = mlx_new_window(config->mlx, config->r_width,
											config->r_height, "Cub3D");
		mlx_hook(config->mlx_win_3d, 2, 0, &press_key, config);
		mlx_hook(config->mlx_win_3d, 3, 0, &anpress_key, config);
		mlx_hook(config->mlx_win_3d, 17, 0, &close_win, config);
	}
}

void			ft_err(char *line)
{
	ft_putstr_fd(line, 1);
	exit(1);
}

void			ft_not_valid_tex_2(t_struct *config)
{
	if (config->tex_no->tex == NULL)
		ft_err("Error\nNot valid NO tex\n");
	else
		config->tex_no->adr = mlx_get_data_addr(config->tex_no->tex,
											&config->tex_no->bpp,
											&config->tex_no->line_len,
											&config->tex_no->iend);
	if (config->tex_so->tex == NULL)
		ft_err("Error\nNot valid SO tex\n");
	else
		config->tex_so->adr = mlx_get_data_addr(config->tex_so->tex,
											&config->tex_so->bpp,
											&config->tex_so->line_len,
											&config->tex_so->iend);
	if (config->tex_we->tex == NULL)
		ft_err("Error\nNot valid WE tex\n");
	else
		config->tex_we->adr = mlx_get_data_addr(config->tex_we->tex,
											&config->tex_we->bpp,
											&config->tex_we->line_len,
											&config->tex_we->iend);
}

void			ft_not_valid_tex(t_struct *config)
{
	if (config->tex_ea->tex == NULL)
		ft_err("Error\nNot valid EA tex\n");
	else
		config->tex_ea->adr = mlx_get_data_addr(config->tex_ea->tex,
											&config->tex_ea->bpp,
											&config->tex_ea->line_len,
											&config->tex_ea->iend);
	if (config->sprite->tex == NULL)
		ft_err("Error\nNot valid NO tex\n");
	else
		config->sprite->adr = mlx_get_data_addr(config->sprite->tex,
											&config->sprite->bpp,
											&config->sprite->line_len,
											&config->sprite->iend);
	ft_not_valid_tex_2(config);
}
