/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sdl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:45:27 by abodnar           #+#    #+#             */
/*   Updated: 2019/05/01 17:45:28 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	prepare_textures(t_wolf *params)
{
	(void)params;

	SDL_Surface *texture1 = IMG_Load("./media/textures/fall.jpg");

	ft_printf("Width: %d Height: %d\n", texture1->w, texture1->h);
}

bool		init_sdl(t_wolf *params)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		params->error = ft_strdup(SDL_GetError());
		return (FALSE);
	}
	params->sdl.window = SDL_CreateWindow("Wolf3d", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
			SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (!params->sdl.window)
	{
		params->error = ft_strdup(SDL_GetError());
		return (FALSE);
	}
	SDL_SetRelativeMouseMode(SDL_TRUE);
	params->sdl.surface = SDL_GetWindowSurface(params->sdl.window);
	prepare_textures(params);
	return (TRUE);
}
