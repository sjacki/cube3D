/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandr <alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 19:17:12 by alexandr          #+#    #+#             */
/*   Updated: 2021/05/10 19:31:10 by alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cube3d.h"

void				ft_to_ea_tex(t_struct *config)
{
	config->ray->adr = config->tex_ea->adr;
	config->ray->width = config->tex_ea->width;
	config->ray->height = config->tex_ea->height;
	config->ray->bpp = config->tex_ea->bpp;
	config->ray->line_len = config->tex_ea->line_len;
}

void				ft_to_so_tex(t_struct *config)
{
	config->ray->adr = config->tex_so->adr;
	config->ray->width = config->tex_so->width;
	config->ray->height = config->tex_so->height;
	config->ray->bpp = config->tex_so->bpp;
	config->ray->line_len = config->tex_so->line_len;
}

void				ft_to_no_tex(t_struct *config)
{
	config->ray->adr = config->tex_no->adr;
	config->ray->width = config->tex_no->width;
	config->ray->height = config->tex_no->height;
	config->ray->bpp = config->tex_no->bpp;
	config->ray->line_len = config->tex_no->line_len;
}

void				ft_to_we_tex(t_struct *config)
{
	config->ray->adr = config->tex_we->adr;
	config->ray->width = config->tex_we->width;
	config->ray->height = config->tex_we->height;
	config->ray->bpp = config->tex_we->bpp;
	config->ray->line_len = config->tex_we->line_len;
}

void				ft_select_tex(t_struct *config)
{
	if (config->ray->walks == 0 && config->ray->walkx == 1)
		ft_to_ea_tex(config);
	else if (config->ray->walks == 0 && config->ray->walkx == -1)
		ft_to_we_tex(config);
	else if (config->ray->walks == 1 && config->ray->walky == -1)
		ft_to_no_tex(config);
	else if (config->ray->walks == 1 && config->ray->walky == 1)
		ft_to_so_tex(config);
}
