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

#include "doom_nukem.h"

static void	load_hud_textures(t_doom *params)
{
	params->hud.main_hud = IMG_Load("./media/pics/hud.jpg");
	params->hud.face = IMG_Load("./media/pics/Aladdin.png");
	params->hud.logo = IMG_Load("./media/pics/aladdin_small.png");
	params->menu.menu_tex = IMG_Load("./media/textures/menu.jpg");
	params->menu.lose_tex = IMG_Load("./media/textures/lose.jpg");
}

static void	load_sounds(t_doom *params)
{
	params->media.music = Mix_LoadMUS("./media/sounds/Prince_Outfit.mp3");
	params->media.sound1 = Mix_LoadWAV("./media/sounds/sound.mp3");
	params->media.sound2 = Mix_LoadWAV("./media/sounds/tiger.mp3");
}

static void	load_wall_textures(t_doom *params)
{
	params->media.textures[0] = IMG_Load("./media/textures/fire_smart5.jpg");
	params->media.textures[1] = IMG_Load("./media/textures/fire_smart1.jpg");
	params->media.textures[2] = IMG_Load("./media/textures/green_smart1.jpg");
	params->media.textures[3] = IMG_Load("./media/textures/fire_smart3.jpg");
	params->media.textures[4] = IMG_Load("./media/textures/fire_smart4.jpg");
	params->media.textures[5] = IMG_Load("./media/textures/water.jpg");
	params->media.textures[6] = IMG_Load("./media/textures/sky_smart1.jpg");
	params->media.textures[7] = IMG_Load("./media/textures/sky_smart2.jpg");
	params->media.textures[8] = IMG_Load("./media/textures/sky_smart3.jpg");
	params->media.floor_tex = IMG_Load("./media/textures/sky_smart4.jpg");
	params->media.ceil_tex = IMG_Load("./media/textures/fire_smart.jpg");
}

static void	load_media(t_doom *params)
{
	load_wall_textures(params);
	load_sounds(params);
	load_hud_textures(params);
}

bool		init_sdl(t_doom *params)
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
	load_media(params);
	return (TRUE);
}
