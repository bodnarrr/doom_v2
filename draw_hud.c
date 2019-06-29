//
// Created by Andrii Bodnar on 2019-06-29.
//

#include "doom-nukem.h"

static void	draw_sprites_text(t_wolf *params)
{
	SDL_Surface	*text_surface;
	SDL_Rect	sprites_rect;
	TTF_Font	*font;
	SDL_Color	color;

	sprites_rect = (SDL_Rect){900, SCREEN_HEIGHT - 62, 100, 50};
	color = (SDL_Color){0, 0, 0, 255};
	font = TTF_OpenFont("./media/fonts/dark_uvenal_full.otf", 26);
	if (font == NULL)
		params->error = ft_strdup(SDL_GetError());
	if (!(text_surface = TTF_RenderText_Solid(font, "Collection: X/X", color)))
		ft_printf("error\n");
	else
		SDL_BlitSurface(text_surface, NULL, params->sdl.surface, &sprites_rect);
	TTF_CloseFont(font);
	SDL_FreeSurface(text_surface);
}

static void	draw_jasmine_text(t_wolf *params)
{
	SDL_Surface	*text_surface;
	SDL_Rect	jasmin_rect;
	TTF_Font	*font;
	SDL_Color	color;

	jasmin_rect = (SDL_Rect){500, SCREEN_HEIGHT - 70, 200, 100};
	color = (SDL_Color){255, 255, 255, 255};
	font = TTF_OpenFont("./media/fonts/dark_uvenal_full.otf", 39);
	if (font == NULL)
		params->error = ft_strdup(SDL_GetError());
	if (!(text_surface = TTF_RenderText_Solid(font,"Find Jasmine!", color)))
		ft_printf("error\n");
	else
		SDL_BlitSurface(text_surface, NULL, params->sdl.surface, &jasmin_rect);
	TTF_CloseFont(font);
	SDL_FreeSurface(text_surface);
}

void	draw_hud(t_wolf *params)
{
	SDL_Rect	main_rect;
	SDL_Rect	face_rect;
	SDL_Rect	logo_rect;

	main_rect = (SDL_Rect){0, 700, SCREEN_WIDTH, 100};
	SDL_BlitSurface(params->hud.main_HUD, NULL, params->sdl.surface, &main_rect);
	face_rect = (SDL_Rect){100, SCREEN_HEIGHT - 100, 100, 100};
	SDL_BlitSurface(params->hud.face, NULL, params->sdl.surface, &face_rect);
	logo_rect = (SDL_Rect){face_rect.x + face_rect.w + 10, face_rect.y + 25, 129, 50};
	SDL_BlitSurface(params->hud.logo, NULL, params->sdl.surface, &logo_rect);
	draw_jasmine_text(params);
	draw_sprites_text(params);
}