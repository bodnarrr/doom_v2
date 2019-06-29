//
// Created by Andrii Bodnar on 2019-06-23.
//

#include "doom-nukem.h"

static void	horizontal_rotate(bool is_right, t_wolf *params)
{
	double	speed;
	double	old_dir_x;
	double	old_plane_x;

	speed = is_right
			? -params->pos_info.rotate_speed
			: params->pos_info.rotate_speed;
	old_dir_x = params->pos_info.dir_x;
	params->pos_info.dir_x = params->pos_info.dir_x * cos(speed)
							 - params->pos_info.dir_y * sin(speed);
	params->pos_info.dir_y = old_dir_x * sin(speed)
							 + params->pos_info.dir_y * cos(speed);
	old_plane_x = params->pos_info.plane_x;
	params->pos_info.plane_x = params->pos_info.plane_x * cos(speed)
							   - params->pos_info.plane_y * sin(speed);
	params->pos_info.plane_y = old_plane_x * sin(speed)
							   + params->pos_info.plane_y * cos(speed);
}

static void	vertical_rotate(bool is_up, t_wolf *params)
{
	int delta;

	delta = is_up ? -5 : 5;
	params->pos_info.height += delta;
}

void		route_mouse_move(t_wolf *params)
{
	if (params->move_ev.code.motion.xrel != 0)
		horizontal_rotate(params->move_ev.code.motion.xrel > 0, params);
	if (params->move_ev.code.motion.yrel != 0)
		vertical_rotate(params->move_ev.code.motion.yrel > 0, params);
}
