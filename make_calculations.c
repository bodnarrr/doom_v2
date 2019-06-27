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
    int wall_end;
    int *pixels;
    int pos;
    Uint32 color1;

    draw_textured_wall(x, height, params);

	wall_end = (SCREEN_HEIGHT + height) / 2 + params->pos_info.height + (int) params->pos_info.jump;
	pixels = params->sdl.surface->pixels;
    // FLOOR

    double floorXWall, floorYWall;

    if(params->side == 0 && params->sdl.ray_dir_x > 0)
    {
        floorXWall = params->sdl.map_x;
        floorYWall = params->sdl.map_y + params->wall_x;
    }
    else if(params->side == 0 && params->sdl.ray_dir_x < 0)
    {
        floorXWall = params->sdl.map_x + 1.0;
        floorYWall = params->sdl.map_y + params->wall_x;
    }
    else if(params->side == 1 && params->sdl.ray_dir_y > 0)
    {
        floorXWall = params->sdl.map_x + params->wall_x;
        floorYWall = params->sdl.map_y;
    }
    else
    {
        floorXWall = params->sdl.map_x + params->wall_x;
        floorYWall = params->sdl.map_y + 1.0;
    }

    double distWall, distPlayer, currentDist;

    distWall = params->sdl.perp_wall_dist;
    distPlayer = 0.0;
    if (wall_end < 0)
        wall_end = SCREEN_HEIGHT;

    for(int y = wall_end + 1; y < SCREEN_HEIGHT; y++)
    {
        pos = x + (y * SCREEN_WIDTH);

        currentDist = SCREEN_HEIGHT / (2.0 * y - SCREEN_HEIGHT);
        double weight = (currentDist - distPlayer) / (distWall - distPlayer);

        double currentFloorX = weight * floorXWall + (1.0 - weight) * params->pos_info.pos_x;
        double currentFloorY = weight * floorYWall + (1.0 - weight) * params->pos_info.pos_y;

        int floorTexX, floorTexY;
        floorTexX = (int)(currentFloorX * params->texture->w) % params->texture->w;
        floorTexY = (int)(currentFloorY * params->texture->h) % params->texture->h;

        color1 = ((Uint32 *) params->texture->pixels)[params->texture->w * floorTexY + floorTexX];
        pixels[pos] = color1;


        //ceiling (symmetrical!)
//        buffer[SCREEN_HEIGHT - y][x] = texture[6][texWidth * floorTexY + floorTexX];
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
