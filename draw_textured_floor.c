/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textured_floor.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 20:53:08 by abodnar           #+#    #+#             */
/*   Updated: 2019/06/29 20:53:08 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

static void		check_floor_dir(t_wolf *params, t_draw_floor *dr)
{
	if (params->side == 0 && params->sdl.ray_dir_x > 0)
	{
		dr->floor_x = params->sdl.map_x;
		dr->floor_y = params->sdl.map_y + params->wall_x;
	}
	else if (params->side == 0 && params->sdl.ray_dir_x < 0)
	{
		dr->floor_x = params->sdl.map_x + 1.0;
		dr->floor_y = params->sdl.map_y + params->wall_x;
	}
	else if (params->side == 1 && params->sdl.ray_dir_y > 0)
	{
		dr->floor_x = params->sdl.map_x + params->wall_x;
		dr->floor_y = params->sdl.map_y;
	}
	else
	{
		dr->floor_x = params->sdl.map_x + params->wall_x;
		dr->floor_y = params->sdl.map_y + 1.0;
	}
}

void			draw_textured_floor(int x, int height, t_wolf *params)
{
	t_draw_floor	dr;

	ft_bzero(&dr, sizeof(t_draw_floor));
	dr.wall_start = (SCREEN_HEIGHT - height) / 2 + params->pos_info.height
					+ (int)params->pos_info.jump;
	dr.wall_end = (SCREEN_HEIGHT + height) / 2 + params->pos_info.height
					+ (int)params->pos_info.jump;
	dr.pixels = params->sdl.surface->pixels;
	check_floor_dir(params, &dr);
	dr.dist_wall = params->pos_info.perp_wall_dist;
	dr.dist_pl = 0.0;
	dr.wall_start = dr.wall_start < 0 ? 0 : dr.wall_start;
	dr.wall_start = dr.wall_start >= SCREEN_HEIGHT
					? SCREEN_HEIGHT - 1 : dr.wall_start;
	dr.wall_end = dr.wall_end < 0 ? 0 : dr.wall_end;
	dr.wall_end = dr.wall_end >= SCREEN_HEIGHT
					? SCREEN_HEIGHT - 1 : dr.wall_end;
	while (dr.wall_end < SCREEN_HEIGHT || dr.wall_start >= 0)
	{
		dr.pos = x + (dr.wall_end * SCREEN_WIDTH);
		dr.cur_dist = SCREEN_HEIGHT / (2.0 * dr.wall_end - SCREEN_HEIGHT - 2
							* params->pos_info.height);
		dr.weight = (dr.cur_dist - dr.dist_pl) / (dr.dist_wall - dr.dist_pl);
		dr.cur_floor_x = dr.weight * dr.floor_x + (1.0 - dr.weight)
							* params->pos_info.pos_x;
		dr.cur_floor_y = dr.weight * dr.floor_y + (1.0 - dr.weight)
							* params->pos_info.pos_y;
		dr.floor_tex_x = (int)(dr.cur_floor_x * params->texture->w)
							% params->texture->w;
		dr.floor_tex_y = (int)(dr.cur_floor_y * params->texture->h)
							% params->texture->h;
		if (dr.wall_end < SCREEN_HEIGHT)
		{
			dr.pixels[dr.pos] = ((Uint32*)params->texture->pixels)
					[params->texture->w * dr.floor_tex_y + dr.floor_tex_x];
			dr.pixels[dr.pos] = ((Uint32*)params->floor_tex->pixels)
					[params->floor_tex->w * dr.floor_tex_y + dr.floor_tex_x];
		}
		if (dr.wall_start >= 0)
		{
			dr.ceil_pos = x + (dr.wall_start * SCREEN_WIDTH);
			dr.pixels[dr.ceil_pos] = ((Uint32*)params->ceil_tex->pixels)
				[params->ceil_tex->w * dr.floor_tex_y + dr.floor_tex_x];
		}
		dr.wall_start--;
		dr.wall_end++;
	}
}
