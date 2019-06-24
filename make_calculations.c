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

	start = (SCREEN_HEIGHT - height) / 2 + params->pos_info.height;
	pixels = (int*)params->sdl.surface->pixels;
	i = -1;
	while (++i < SCREEN_HEIGHT)
	{
		pos = x + (i * SCREEN_WIDTH);
		if (i < start)
			pixels[pos] = SKY;
		else if (i > start + height)
			pixels[pos] = GROUND;
		else
			pixels[pos] = params->wall_color;
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
		wall_height = (wall_height < SCREEN_HEIGHT && wall_height > 0)
				? wall_height
				: SCREEN_HEIGHT;
		draw_column(i, wall_height, params);
	}
	SDL_UpdateWindowSurface(params->sdl.window);
}
