//
// Created by Olenka on 2019-06-27.
//

#include "doom-nukem.h"

int		set_rgb(unsigned int r, unsigned int g, unsigned int b)
{
	return ((r << 16) | (g << 8) | b);
}

Uint32	set_color(int color, double dist)
{
	Uint32 color_new;
	if (dist > 1)
		color_new = (Uint32)set_rgb((unsigned int)(((color & 0x00ff0000) >> 16) / dist),
					(unsigned int)(((color & 0x0000ff00) >> 8) / dist),
					(unsigned int)(((color & 0x000000ff)) / dist));
	else
		color_new = (Uint32) color;
	return (color_new);
}

void	draw_textured_wall(int x, int height, t_wolf *params)
{
	t_draw_wall	dr;

	ft_bzero(&dr, sizeof(t_draw_wall));
	dr.wall_start = (SCREEN_HEIGHT - height) / 2 + params->pos_info.height + (int) params->pos_info.jump;
	dr.wall_end = (SCREEN_HEIGHT + height) / 2 + params->pos_info.height + (int) params->pos_info.jump;
	dr.pixels = (Uint32*)params->sdl.surface->pixels;
	params->wall_color = 0;
	dr.wall_start = dr.wall_start < 0 ? 0 : dr.wall_start;
	dr.wall_start = dr.wall_start >= SCREEN_HEIGHT ? SCREEN_HEIGHT - 1 : dr.wall_start;
	dr.wall_end = dr.wall_end < 0 ? 0 : dr.wall_end;
	dr.wall_end = dr.wall_end >= SCREEN_HEIGHT ? SCREEN_HEIGHT - 1 : dr.wall_end;
	while (dr.wall_start < dr.wall_end)
	{
		dr.pos = x + (dr.wall_start * SCREEN_WIDTH);
		dr.tex_x = (int) (params->wall_x * (double) params->textures[params->tex_ind]->w);
		if ((params->side == 0 && params->ray_x > 0) || (params->side == 1 && params->ray_y < 0))
			dr.tex_x = params->textures[params->tex_ind]->w - dr.tex_x - 1;
		dr.d = dr.wall_start * 2 - SCREEN_HEIGHT + height - params->pos_info.height * 2;
		dr.tex_y = ((dr.d * params->textures[params->tex_ind]->w) / height) / 2;
		if (dr.tex_x >= 0 && dr.tex_x < params->textures[params->tex_ind]->h && dr.tex_y >= 0 && dr.tex_y < params->textures[params->tex_ind]->w)
			params->wall_color = set_color(((int*)params->textures[params->tex_ind]->pixels)[params->textures[params->tex_ind]->h * dr.tex_y + dr.tex_x], params->z_buffer[x]);
		dr.pixels[dr.pos] = params->wall_color;
		dr.wall_start++;
	}
}