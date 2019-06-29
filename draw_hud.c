//
// Created by Andrii Bodnar on 2019-06-29.
//

#include "doom-nukem.h"

void	draw_hud(t_wolf *params)
{
	SDL_Rect	main_rect;
	SDL_Rect	face_rect;

	main_rect = (SDL_Rect){0, 700, SCREEN_WIDTH, 100};
	SDL_BlitSurface(params->hud.main_HUD, NULL, params->sdl.surface, &main_rect);
	face_rect = (SDL_Rect){100, SCREEN_HEIGHT - 100, 100, 100};
	SDL_BlitSurface(params->hud.face, NULL, params->sdl.surface, &face_rect);
	SDL_UpdateWindowSurface(params->sdl.window);
}