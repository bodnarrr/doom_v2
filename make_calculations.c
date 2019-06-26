/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_calculations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:45:46 by abodnar           #+#    #+#             */
/*   Updated: 2019/05/01 17:45:47 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	draw_column(int x, int height, t_wolf *params)
{
	int	start;
	int *pixels;
	int i;
	int pos;
	Uint32 color;

	start = (SCREEN_HEIGHT - height) / 2 + params->pos_info.height + (int)params->pos_info.jump;
	pixels = (int*)params->sdl.surface->pixels;
	color = 0;
	i = -1;
	while (++i < SCREEN_HEIGHT)
	{
		pos = x + (i * SCREEN_WIDTH);
		if (i < start)
			pixels[pos] = SKY;
		else if (i > start + height)
			pixels[pos] = GROUND;
//		else
//			pixels[pos] = params->wall_color;
		else
		{
			int texX = (int)(params->wall_x * (double)params->texture->w);
			if(params->side == 0 && params->ray_x > 0)
				texX = params->texture->w - texX - 1;
			if(params->side == 1 && params->ray_y < 0)
				texX = params->texture->w - texX - 1;

			int d = i * 2 - SCREEN_HEIGHT + height;
			int texY = ((d * params->texture->w) / height) / 2;
			(void)texX;
			(void)texY;

			if (texX >= 0 && texX < params->texture->h && texY >= 0 && texY < params->texture->w)
				color = ((Uint32*)params->texture->pixels)[params->texture->h * texY + texX];

			pixels[pos] = color;
		}
	}
}

void		make_calculations(t_wolf *params)
{
	int	i;
	int wall_height;

	ft_bzero(params->sdl.surface->pixels, sizeof(int)
										* SCREEN_HEIGHT * SCREEN_WIDTH);
	i = -1;
	while (++i < SCREEN_WIDTH)
	{
		wall_height = height_for_column(i, params);
		draw_column(i, wall_height, params);
	}
	SDL_UpdateWindowSurface(params->sdl.window);
}
