static void	computation_tex_pos(t_all *xlm)
{
	xlm->neo.tex_x = (int)(xlm->neo.wall_x * (double)(xlm->neo.tex_wid));
	if ((xlm->neo.side == 0 && xlm->neo.rdir_x > 0) ||\
		(xlm->neo.side == 1 && xlm->neo.rdir_y < 0))
		xlm->neo.tex_x = xlm->neo.tex_wid - xlm->neo.tex_x - 1;
	if (xlm->neo.tex_x >= xlm->neo.tex_wid)
		xlm->neo.tex_x = xlm->neo.tex_wid - 1;
	else if (xlm->neo.tex_x < 0)
		xlm->neo.tex_x = 0;
	xlm->neo.step = 1.0 * xlm->neo.tex_hei / xlm->neo.line_len;
	xlm->neo.tex_pos = (xlm->neo.draw_up - xlm->param.height /\
	xlm->move.mouse_cam + xlm->neo.line_len / 2) * xlm->neo.step;
}

static void	computation_draws_wall(t_all *xlm)
{
	xlm->neo.line_len = (int)(xlm->param.height / fabs(xlm->neo.dist));
	xlm->neo.draw_up = -xlm->neo.line_len / 2 + xlm->param.height /\
	xlm->move.mouse_cam;
	if (xlm->neo.draw_up < 0)
		xlm->neo.draw_up = 0;
	xlm->neo.draw_down = xlm->neo.line_len / 2 + xlm->param.height /\
	xlm->move.mouse_cam;
	if (xlm->neo.draw_down >= xlm->param.height)
		xlm->neo.draw_down = xlm->param.height - 1;
	if (xlm->neo.side == 0)
		xlm->neo.wall_x = Y + xlm->neo.dist * xlm->neo.rdir_y;
	else
		xlm->neo.wall_x = X + xlm->neo.dist * xlm->neo.rdir_x;
	xlm->neo.wall_x -= floor(xlm->neo.wall_x);
}

static void	computation_distance(t_all *xlm, int collision, int x)
{
	while (collision == 0)
	{
		if (xlm->neo.side_x < xlm->neo.side_y)
		{
			xlm->neo.side_x += xlm->neo.del_x;
			xlm->neo.x += xlm->neo.step_x;
			xlm->neo.side = 0;
		}
		else
		{
			xlm->neo.side_y += xlm->neo.del_y;
			xlm->neo.y += xlm->neo.step_y;
			xlm->neo.side = 1;
		}
		if (xlm->param.g_map[xlm->neo.y][xlm->neo.x] == '1')
			collision = 1;
	}
	if (xlm->neo.side == 0)
		xlm->neo.dist =\
		(xlm->neo.x - X + (1 - xlm->neo.step_x) / 2) / xlm->neo.rdir_x;
	else
		xlm->neo.dist =\
		(xlm->neo.y - Y + (1 - xlm->neo.step_y) / 2) / xlm->neo.rdir_y;
	if (xlm->sprite.spr_len)
		xlm->sprite.wid_buf[x] = xlm->neo.dist;
}

static void	computation_side_step(t_all *xlm, int x)
{
	xlm->neo.cam = 2 * x / (double)xlm->param.width - 1;
	xlm->neo.rdir_x = xlm->player.dir_x + xlm->player.plan_x * xlm->neo.cam;
	xlm->neo.rdir_y = xlm->player.dir_y + xlm->player.plan_y * xlm->neo.cam;
	xlm->neo.x = (int)X;
	xlm->neo.y = (int)Y;
	xlm->neo.del_x = fabs(1 / xlm->neo.rdir_x);
	xlm->neo.del_y = fabs(1 / xlm->neo.rdir_y);
	if (xlm->neo.rdir_x < 0 && (xlm->neo.step_x = -1))
		xlm->neo.side_x = (X - xlm->neo.x) * xlm->neo.del_x;
	else if ((xlm->neo.step_x = 1))
		xlm->neo.side_x = (xlm->neo.x + 1.0 - X) * xlm->neo.del_x;
	if (xlm->neo.rdir_y < 0 && (xlm->neo.step_y = -1))
		xlm->neo.side_y = (Y - xlm->neo.y) * xlm->neo.del_y;
	else if ((xlm->neo.step_y = 1))
		xlm->neo.side_y = (xlm->neo.y + 1.0 - Y) * xlm->neo.del_y;
}

void		ft_draw_tex_2(t_all *xlm, int x, int y)
{
	unsigned int	*color;

	xlm->neo.tex_y = (int)xlm->neo.tex_pos;
	if (xlm->neo.tex_y >= xlm->neo.tex_hei)
		xlm->neo.tex_y = xlm->neo.tex_hei - 1;
	else if (xlm->neo.tex_y < 0)
		xlm->neo.tex_y = 0;
	xlm->neo.tex_pos += xlm->neo.step;
		color = (unsigned int*)(xlm->neo.adr + xlm->neo.tex_line *\
		xlm->neo.tex_y + xlm->neo.tex_x * (xlm->neo.bpp / 8));
		my_pixel_put(xlm, x, y, (int)*color);
}

void		ft_draw_tex(t_all *xlm)
{
	int				x;
	int				y;

	x = -1;
	while (++x < (xlm->param.width - 1))
	{
		computation_side_step(xlm, x);
		computation_distance(xlm, 0, x);
		computation_draws_wall(xlm);
		ft_select_texture(xlm);
		computation_tex_pos(xlm);
		y = xlm->neo.draw_up - 1;
		while (++y < xlm->neo.draw_down)
			ft_draw_tex_2(xlm, x, y);
	}
}

