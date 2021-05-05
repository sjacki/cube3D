/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandr <alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:25:50 by sjacki            #+#    #+#             */
/*   Updated: 2021/05/04 18:32:37 by alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H
# include "../libft/header/libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
 
 typedef struct	s_raycast
{
	double 		vx;//dirx
	double		vy;//diry
	double 		px;//planex
	double 		py;//planey
	double 		frame;//time
	double 		dframe;        //oldTime
	double		speed;        //moveSpeed;
	double		camx;//cameraX
	double		camy;//cameraY
	double 		rayvx;//rayDirX
	double 		rayvy;//rayDirY
	double 		distx;//sideDistX;
    double 		disty;//sideDistY;
	double 		deldistx;//deltaDistX;
    double 		deldisty;//deltaDistY;
	double		walldist;//perwalldist
	int			mx;//mapx
	int			my;//mapy
    int			walkx;//stepX;
    int			walky;//stepY;
    int			flag;//hit = 0;
    int			walks;//side;
	int			lenline;//lineHeight
	int			draws;//drawStart
	int			drawe;//drawEnd
	double		ftime;//frame time
	double		movespeed;//moveSpeed;
	double		rotentionspeed;//rotSpeed;
}				t_raycast;

typedef struct	s_struct
{
	int			x_hud_2d_map;
	int			r_width;
	int			r_height;
	size_t		x;
	int			player_count;
	char		*no_texture;
	char		*so_texture;
	char		*we_texture;
	char		*ea_texture;
	char		*s_texture;
	char		v_pl;
	char		*argv1;
	char		**map;
	int			floor_color[3];
	int			ceilling_color[3];
	int			f_color;
	int			c_color;
	size_t		flag_floor;
	size_t		flag_ceilling;
	size_t		mp5;
	size_t		trig;
	size_t		conf_count;
	size_t		map_trigger;
	void		*mlx;
	void		*mlx_win_3d;
	void		*mlx_img;
	int			square_color;
	double		x_pl;
	double		y_pl;
    char		*addr;
    int			bits_per_pixel;
    int			line_length;
    int			endian;
	int			fl_w;
	int			fl_s;
	int			fl_a;
	int			fl_d;
	int			fl_q;
	int			fl_e;
	int			fl_find_pl;
	double		speed;
	int			r_ray;
	int			hud_scale;
	int			px_size;
	void		*tex_no;
	void		*tex_so;
	void		*tex_we;
	void		*tex_ea;
	void		*tex_s;
	t_raycast	*ray;
}				t_struct;
	
int				parser(int fd, t_struct *config);
int				ft_mlx(t_struct *config);
int				parser_texture_no(char *line, t_struct *config);
int				parser_texture_so(char *line, t_struct *config);
int				parser_texture_we(char *line, t_struct *config);
int				parser_texture_ea(char *line, t_struct *config);
int				parser_texture_s(char *line, t_struct *config);
int				parser_map(t_struct *config, int longer_line);
int				cor_env_base(char **map, int x, int y);
int				endmap(char *line, char **map, int longer_line);
void			main_draw_map(t_struct *config);
void			my_put_px(t_struct *config, int x, int y, int color);
int				my_get_px(t_struct *config, int x, int y);
void			contr_pl(t_struct *config);
void			draw_square(int x, int y, int size, t_struct *config);
int				anpress_key(int keycode, t_struct *config);
int				press_key(int keycode, t_struct *config);
int				close_win(t_struct *config);
void			base_ray_dir(t_struct *config);
void			alg(t_struct *config);
#endif
