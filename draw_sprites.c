/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 20:17:37 by abodnar           #+#    #+#             */
/*   Updated: 2019/06/29 20:17:38 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	draw_sprites(t_wolf *params)
{
	double	spr_x;
	double	spr_y;
	double	inv_det;
	double	transf_x;
	double	transf_y;
	int		spr_scr_x;
	int		spr_h;
	int		draw_start_y;
	int		draw_end_y;
	int		spr_w;
	int		draw_start_x;
	int		draw_end_x;
	int		i;
	int		j;
	int		tex_x;
	int		tex_y;
	int		pos;
	int		d;
	Uint32	color;

	spr_x = params->sprite.x - params->pos_info.pos_x;
	spr_y = params->sprite.y - params->pos_info.pos_y;
	inv_det = 1.0 / (params->pos_info.plane_x * params->pos_info.dir_y
			- params->pos_info.dir_x * params->pos_info.plane_y);
	transf_x = inv_det * (params->pos_info.dir_y * spr_x
								- params->pos_info.dir_x * spr_y);
	transf_y = inv_det * (-params->pos_info.plane_y * spr_x
								+ params->pos_info.plane_x * spr_y);
	spr_scr_x = (int)((SCREEN_WIDTH / 2) * (1 + transf_x / transf_y));
	spr_h = abs((int)(SCREEN_HEIGHT / (transf_y)));
	draw_start_y = -spr_h / 2 + SCREEN_HEIGHT / 2;
	if (draw_start_y < 0)
		draw_start_y = 0;
	draw_end_y = spr_h / 2 + SCREEN_HEIGHT / 2;
	if (draw_end_y >= SCREEN_HEIGHT)
		draw_end_y = SCREEN_HEIGHT - 1;
	spr_w = abs((int)(SCREEN_HEIGHT / (transf_y)));
	draw_start_x = -spr_w / 2 + spr_scr_x;
	if (draw_start_x < 0)
		draw_start_x = 0;
	draw_end_x = spr_w / 2 + spr_scr_x;
	if (draw_end_x >= SCREEN_WIDTH)
		draw_end_x = SCREEN_WIDTH - 1;
	i = draw_start_x;
	while (i < draw_end_x)
	{
		tex_x = (int)(256 * (i - (-spr_w / 2 + spr_scr_x))
							* params->sprite.texture->w / spr_w) / 256;
		if (transf_y > 0 && i > 0 && i < SCREEN_WIDTH
							&& transf_y < params->z_buffer[i])
		{
			j = draw_start_y;
			while (j < draw_end_y)
			{
				pos = i + (j * SCREEN_WIDTH);
				d = j * 256 - SCREEN_HEIGHT * 128 + spr_h * 128;
				tex_y = ((d * params->sprite.texture->h) / spr_h) / 256;
				color = ((Uint32*)params->sprite.texture->pixels)
						[params->sprite.texture->w * tex_y + tex_x];
				if ((color & 0x00FFFFFF) != 0)
					((Uint32*)params->sdl.surface->pixels)[pos] = color;
				j++;
			}
		}
		i++;
	}
}
