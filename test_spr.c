//
// Created by neo on 06.05.2021.
//

#include "../includes/cub3d.h"

static int	draw_sprite(t_all *xlm, int x, int y)
{
	unsigned int	*color;
	int				y_t;
	int				temp;

	temp = (y - xlm->sprite.move_scr) * 256 -\
	xlm->param.height / 2 * 256 + xlm->sprite.spr_hi * 128;
	y_t = ((temp * xlm->sprite.height) / xlm->sprite.spr_hi) / 256;
	y_t = y_t < 0 ? 0 : y_t;
	color = (unsigned int*)(xlm->sprite.adr + xlm->sprite.line_len * y_t +\
	xlm->sprite.x_t * (xlm->sprite.bpp / 8));
	my_pixel_put(xlm, x, y, (int)*color);
	return (1);
}

static void	computation_param_spr(t_all *xlm, int i)
{
	xlm->sprite.spr_x = xlm->sprite.pos[xlm->sprite.spr[i]].x - X;
	xlm->sprite.spr_y = xlm->sprite.pos[xlm->sprite.spr[i]].y - Y;
	xlm->sprite.inde = 1.0 / (xlm->player.plan_x * xlm->player.dir_y -\
	xlm->player.dir_x * xlm->player.plan_y);
	xlm->sprite.trans_x = xlm->sprite.inde * (xlm->player.dir_y *\
	xlm->sprite.spr_x - xlm->player.dir_x * xlm->sprite.spr_y);
	xlm->sprite.trans_y = xlm->sprite.inde * (-xlm->player.plan_y *\
	xlm->sprite.spr_x + xlm->player.plan_x * xlm->sprite.spr_y);
	xlm->sprite.spr_scr = (int)((xlm->param.width / 2) *\
	(1 + xlm->sprite.trans_x / xlm->sprite.trans_y));
	xlm->sprite.move_scr = (int)(0.0 / xlm->sprite.trans_y);
	xlm->sprite.spr_hi = abs((int)(xlm->param.height / xlm->sprite.trans_y))\
	/ 1;
	xlm->sprite.draw_up_y = -xlm->sprite.spr_hi / 2 +\
	xlm->param.height / xlm->move.mouse_cam + xlm->sprite.move_scr;
}

static void	computation_draw_up_down(t_all *xlm)
{
	if (xlm->sprite.draw_up_y < 0)
		xlm->sprite.draw_up_y = 0;
	xlm->sprite.draw_down_y = xlm->sprite.spr_hi / 2 +\
	xlm->param.height / xlm->move.mouse_cam + xlm->sprite.move_scr;
	if (xlm->sprite.draw_down_y >= xlm->param.height)
		xlm->sprite.draw_down_y = xlm->param.height - 1;
	xlm->sprite.spr_wi = abs((int)(xlm->param.height / xlm->sprite.trans_y))\
	/ 1;
	xlm->sprite.draw_up_x = -xlm->sprite.spr_wi / 2 + xlm->sprite.spr_scr;
	if (xlm->sprite.draw_up_x < 0)
		xlm->sprite.draw_up_x = 0;
	xlm->sprite.draw_down_x = xlm->sprite.spr_wi / 2 + xlm->sprite.spr_scr;
	if (xlm->sprite.draw_down_x >= xlm->param.width)
		xlm->sprite.draw_down_x = xlm->param.width - 1;
}

void		ft_draw_sprite(t_all *xlm, int x, int y, int i)
{
	while (++i < xlm->sprite.spr_len)
	{
		computation_param_spr(xlm, i);
		computation_draw_up_down(xlm);
		x = xlm->sprite.draw_up_x - 1;
		while (++x < (xlm->sprite.draw_down_x - 1))
		{
			xlm->sprite.x_t = (int)(x - (-xlm->sprite.spr_wi / 2 +\
			xlm->sprite.spr_scr)) * xlm->sprite.width / xlm->sprite.spr_wi;
			xlm->sprite.x_t = xlm->sprite.x_t < 0 ? 0 : xlm->sprite.x_t;
			if (xlm->sprite.trans_y > 0 && x > 0 && x < xlm->param.width &&\
			xlm->sprite.trans_y < xlm->sprite.wid_buf[x])
			{
				y = xlm->sprite.draw_up_y - 1;
				while (++y < (xlm->sprite.draw_down_y - 1))
					draw_sprite(xlm, x, y)
			}
		}
	}
}
