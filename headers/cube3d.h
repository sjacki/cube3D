/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:25:50 by sjacki            #+#    #+#             */
/*   Updated: 2021/02/16 07:53:45 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H
# include "../libft/header/libft.h"
# include "mlx.h"
# include <fcntl.h>
 
typedef struct	s_struct
{
	int			r_width;
	int			r_height;
	size_t		x;
	char		player;
	int			player_count;
	char		*no_texture;
	char		*so_texture;
	char		*we_texture;
	char		*ea_texture;
	char		*s_texture;
	char		*argv1;
	char		**map;
	int			floor_color[3];
	int			ceilling_color[3];
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
	int			x_pl;
	int			y_pl;
    char		v_pl;
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
	int			speed;
	int			r_ray;
}				t_struct;
	
int				parser(int fd, t_struct *config);
int				ray_casting(t_struct *config);
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
#endif
