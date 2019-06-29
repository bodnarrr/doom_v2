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

#include "doom-nukem.h"

static void	prepare_textures(t_wolf *params)
{
	params->texture = IMG_Load("./media/textures/fire_smart5.jpg");
	params->sprite.texture = IMG_Load("./media/pics/parrot.png");
	params->ceil_tex = IMG_Load("./media/textures/sky_smart4.jpg");
	params->floor_tex = IMG_Load("./media/textures/fire_smart.jpg");

	params->sdl.music = Mix_LoadMUS("./media/sounds/Prince_Outfit.mp3");

	params->textures[0] = IMG_Load("./media/textures/fire_smart5.jpg");
	params->textures[1] = IMG_Load("./media/textures/fire_smart1.jpg");
	params->textures[2] = IMG_Load("./media/textures/fire_smart2.jpg");
//	params->textures[3] = IMG_Load("./media/textures/water.jpg");

	params->hud.profile = IMG_Load("./media/pics/Aladdin.png");

	params->sprite.y = 2;
	params->sprite.x = 5;
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

	if (TTF_Init() < 0)
	{
		params->error = ft_strdup(SDL_GetError());
		return (FALSE);
	}
	if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 4096) < 0)
	{
		params->error = ft_strdup(SDL_GetError());
		return (FALSE);
	}
	SDL_SetRelativeMouseMode(SDL_TRUE);
	params->sdl.surface = SDL_GetWindowSurface(params->sdl.window);
	prepare_textures(params);
	return (TRUE);
}
