/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   height_for_column.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:46:45 by abodnar           #+#    #+#             */
/*   Updated: 2019/05/01 17:46:46 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	calc_cam_ray(int x, t_wolf *params, t_iterations *iter)
{
	iter->camera_x = (double)2.0 * (double)x / (double)(SCREEN_WIDTH)
			- (double)1.0;
	iter->ray_dir_x = params->pos_info.dir_x
			+ params->pos_info.plane_x * iter->camera_x;
	iter->ray_dir_y = params->pos_info.dir_y
			+ params->pos_info.plane_y * iter->camera_x;
	iter->map_x = (int)params->pos_info.pos_x;
	iter->map_y = (int)params->pos_info.pos_y;
	iter->delta_dist_x = fabs((double)1.0 / iter->ray_dir_x);
	iter->delta_dist_y = fabs((double)1.0 / iter->ray_dir_y);
}

static void	calc_axes(t_wolf *params, t_iterations *iter)
{
	if (iter->ray_dir_x < 0)
	{
		iter->step_x = -1;
		iter->side_dist_x = (params->pos_info.pos_x - (double)iter->map_x)
							* iter->delta_dist_x;
	}
	else
	{
		iter->step_x = 1;
		iter->side_dist_x = ((double)iter->map_x + (double)1.0
				- params->pos_info.pos_x) * iter->delta_dist_x;
	}
	if (iter->ray_dir_y < 0)
	{
		iter->step_y = -1;
		iter->side_dist_y = (params->pos_info.pos_y - (double)iter->map_y)
							* iter->delta_dist_y;
	}
	else
	{
		iter->step_y = 1;
		iter->side_dist_y = ((double)iter->map_y + (double)1.0
				- params->pos_info.pos_y) * iter->delta_dist_y;
	}
}

void		check_wall_hit(t_wolf *params, t_iterations *iter)
{
	while (iter->hit == 0)
	{
		if (iter->side_dist_x < iter->side_dist_y)
		{
			iter->side_dist_x += iter->delta_dist_x;
			iter->map_x += iter->step_x;
			params->side = 0;
		}
		else
		{
			iter->side_dist_y += iter->delta_dist_y;
			iter->map_y += iter->step_y;
			params->side = 1;
		}
		if (params->map[iter->map_y]
			&& params->map[iter->map_y][iter->map_x] > 0)
		{
			set_wall_color(params, params->map[iter->map_y][iter->map_x]);
			iter->hit = 1;
		}
	}
}

void		calc_wall_x(t_wolf *params, t_iterations *iter, int x)
{
	if (params->side == 0)
		params->wall_x = params->pos_info.pos_y + iter->perp_wall_dist * iter->ray_dir_y;
	else
		params->wall_x = params->pos_info.pos_x + iter->perp_wall_dist * iter->ray_dir_x;
	params->wall_x -= floor(params->wall_x);
	params->ray_x = iter->ray_dir_x;
	params->ray_y = iter->ray_dir_y;
	params->z_buffer[x] = iter->perp_wall_dist;
}

void		calc_wall_distance(t_wolf *params, t_iterations *iter, int x)
{
	if (params->side == 0)
		iter->perp_wall_dist = ((double)iter->map_x - params->pos_info.pos_x
				+ ((double)1.0 - (double)iter->step_x) / (double)2.0)
				/ iter->ray_dir_x;
	else
		iter->perp_wall_dist = ((double)iter->map_y - params->pos_info.pos_y
				+ ((double)1.0 - (double)iter->step_y) / (double)2.0)
				/ iter->ray_dir_y;
	calc_wall_x(params, iter, x);
}

int			height_for_column(int x, t_wolf *params)
{
	t_iterations iter;

	ft_bzero(&iter, sizeof(t_iterations));
	calc_cam_ray(x, params, &iter);
	calc_axes(params, &iter);
	check_wall_hit(params, &iter);
	calc_wall_distance(params, &iter, x);
	return (int)((double)SCREEN_HEIGHT / iter.perp_wall_dist);
}
