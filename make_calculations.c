/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_calculations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshchuro <pshchuro@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:45:46 by abodnar           #+#    #+#             */
/*   Updated: 2019/06/30 11:36:05 by pshchuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"

static void	draw_column(int x, int height, t_wolf *params)
{
    draw_textured_wall(x, height, params);
    draw_textured_floor(x, height, params);
	draw_textured_ceiling(x, height, params);
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
}
