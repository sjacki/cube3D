/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_casting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 00:17:35 by sjacki            #+#    #+#             */
/*   Updated: 2021/02/08 19:57:19 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cube3d.h"

int			ray_casting(t_struct *config)
{
	t_mlx mlx_strtuct;
	
	mlx_struct.mlx = mlx_init();
	mlx_struct.mlx_win = mlx_new_window(mlx_struct.mlx, config->r_width, config->r_height, "Cub3D");
	mlx_loop(mlx_struct.mlx);
	return (1);
}
