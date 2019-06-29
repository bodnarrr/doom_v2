//
// Created by Andrii Bodnar on 2019-06-29.
//

#include "doom-nukem.h"

void	draw_hud(t_wolf *params)
{
	SDL_Rect dest = {100, SCREEN_HEIGHT - 100, 100, 100};
	SDL_BlitSurface(params->hud.profile, NULL, params->sdl.surface, &dest);
	SDL_UpdateWindowSurface(params->sdl.window);
//}
}