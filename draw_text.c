//
// Created by Olenka on 2019-06-28.
//

#include "wolf3d.h"

void	draw_text(t_wolf *params)
{
	(void)params;
	SDL_Surface *text_surface;

	SDL_Rect dest = {20, 30, 200, 100};

	SDL_Color color = {255, 255, 255, 255};
	char *font_path = "./media/fonts/sumkin_freetype_mrfrukta.ttf";
	TTF_Font *font = TTF_OpenFont(font_path, 39);
	if (font == NULL)
		params->error = ft_strdup(SDL_GetError());
	if (!(text_surface = TTF_RenderText_Solid(font,"Hello World!", color)))
		printf("error\n");
	else
		SDL_BlitSurface(text_surface, NULL, params->sdl.surface, &dest);
	TTF_CloseFont(font);
	SDL_FreeSurface(text_surface);
	SDL_UpdateWindowSurface(params->sdl.window);
}


