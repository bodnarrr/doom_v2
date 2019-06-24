/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 18:03:57 by abodnar           #+#    #+#             */
/*   Updated: 2019/05/01 18:03:58 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	increase_rotate_speed(bool is_increasing, t_wolf *params)
{
	double	rotate_speed_change;

	rotate_speed_change = is_increasing ? 0.004 : -0.004;
	params->pos_info.rotate_speed += rotate_speed_change;
	if (params->pos_info.rotate_speed < MIN_ROTATE_SPEED)
		params->pos_info.rotate_speed = MIN_ROTATE_SPEED;
	else if (params->pos_info.rotate_speed > MAX_ROTATE_SPEED)
		params->pos_info.rotate_speed = MAX_ROTATE_SPEED;
}

static void	increase_speed(bool is_increasing, t_wolf *params)
{
	double	speed_change;

	speed_change = is_increasing ? 0.009 : -0.009;
	params->pos_info.move_speed += speed_change;
	if (params->pos_info.move_speed < MIN_SPEED)
		params->pos_info.move_speed = MIN_SPEED;
	else if (params->pos_info.move_speed > MAX_SPEED)
		params->pos_info.move_speed = MAX_SPEED;
}

static void	move_right(t_wolf *params)
{
	(void)params;
}

static void	move_left(t_wolf *params)
{
	(void)params;
//	double	new_y;
//	double	new_x;
//	double 	calc_x;
//	double 	calc_y;
//
//	calc_x = params->pos_info.dir_x + 0.5 > 1
//			? params->pos_info.dir_x - 1.5 : params->pos_info.dir_x + 0.5;
//	calc_y = params->pos_info.dir_y - 0.5 < -1
//			 ? params->pos_info.dir_y + 1.5 : params->pos_info.dir_y - 0.5;
//
//	new_y = params->pos_info.pos_y + calc_y * params->pos_info.move_speed;
//	new_x = params->pos_info.pos_x + calc_x * params->pos_info.move_speed;
//	if (params->map[(int)new_y][(int)params->pos_info.pos_x] == 0)
//		params->pos_info.pos_y = new_y;
//	if (params->map[(int)params->pos_info.pos_y][(int)new_x] == 0)
//		params->pos_info.pos_x = new_x;
}

static void	move_forward_back(bool is_move_forward, t_wolf *params)
{
	double	new_y;
	double	new_x;

	new_y = is_move_forward
			? params->pos_info.pos_y
				+ params->pos_info.dir_y * params->pos_info.move_speed
			: params->pos_info.pos_y
				- params->pos_info.dir_y * params->pos_info.move_speed;
	new_x = is_move_forward
			? params->pos_info.pos_x
				+ params->pos_info.dir_x * params->pos_info.move_speed
			: params->pos_info.pos_x
				- params->pos_info.dir_x * params->pos_info.move_speed;
	if (params->map[(int)new_y][(int)params->pos_info.pos_x] == 0)
		params->pos_info.pos_y = new_y;
	if (params->map[(int)params->pos_info.pos_y][(int)new_x] == 0)
		params->pos_info.pos_x = new_x;
}

void		route_events(SDL_Scancode code, t_wolf *params)
{
	if (code == SDL_SCANCODE_W)
		move_forward_back(TRUE, params);
	else if (code == SDL_SCANCODE_S)
		move_forward_back(FALSE, params);
	else if (code == SDL_SCANCODE_A)
		move_left(params);
	else if (code == SDL_SCANCODE_D)
		move_right(params);
	else if (code == SDL_SCANCODE_UP)
		increase_speed(TRUE, params);
	else if (code == SDL_SCANCODE_DOWN)
		increase_speed(FALSE, params);
	else if (code == SDL_SCANCODE_RIGHT)
		increase_rotate_speed(TRUE, params);
	else if (code == SDL_SCANCODE_LEFT)
		increase_rotate_speed(FALSE, params);
}
