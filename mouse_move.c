//
// Created by Andrii Bodnar on 2019-06-23.
//

#include "doom-nukem.h"

static void	horizontal_rotate(t_wolf *params)
{
	double	speed;
	double	old_dir_x;
	double	old_plane_x;

	speed = 0.0;
	if (params->move_ev.mws == -1)
		speed = -params->pos_info.rotate_speed;
	else if (params->move_ev.mws == 1)
		speed = params->pos_info.rotate_speed;
	if (speed != 0)
	{
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
}

static void	vertical_rotate(t_wolf *params)
{
	if (params->move_ev.mad == 1)
		params->pos_info.height -= DELTA_MOUSE;
	else if (params->move_ev.mad == -1)
		params->pos_info.height += DELTA_MOUSE;
}

void		route_mouse_move(t_wolf *params)
{
	if (params->move_ev.mws != 0)
		horizontal_rotate(params);
	if (params->move_ev.mad != 0)
		vertical_rotate(params);
}
