/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonischu <vonischu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:43:29 by abodnar           #+#    #+#             */
/*   Updated: 2019/06/30 10:11:37 by vonischu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"

void  jump(t_wolf *params)
{
 int height;
 int delta_height;

 // if (!params->squat && !params->fly)
 height = params->pos_info.height;
 delta_height = 0;
 while (delta_height < 100)
 {
  params->pos_info.height = height + delta_height;
  make_calculations(params);
  draw_sprites(params);
  draw_hud(params);
  SDL_UpdateWindowSurface(params->sdl.window);
  delta_height += 10;
 }
 while (delta_height >= 0)
 {
  params->pos_info.height = height + delta_height;
  make_calculations(params);
  draw_sprites(params);
  draw_hud(params);
  SDL_UpdateWindowSurface(params->sdl.window);
  delta_height -= 10;
 }
}

void	key_down(int key, t_wolf *params)
{
	if (key == SDLK_UP || key == SDLK_w)
		params->move_ev.ws = 1;
	else if (key == SDLK_DOWN || key == SDLK_s)
		params->move_ev.ws = -1;
	if (key == SDLK_RIGHT || key == SDLK_d)
		params->move_ev.ad = -1;
	else if (key == SDLK_LEFT || key == SDLK_a)
		params->move_ev.ad = 1;
	else if (key == SDLK_SPACE)
		jump(params);
}

void	key_up(int key, t_wolf *params)
{
	if (key == SDLK_UP || key == SDLK_w)
		params->move_ev.ws = 0;
	else if (key == SDLK_DOWN || key == SDLK_s)
		params->move_ev.ws = 0;
	else if (key == SDLK_RIGHT || key == SDLK_d)
		params->move_ev.ad = 0;
	else if (key == SDLK_LEFT || key == SDLK_a)
		params->move_ev.ad = 0;
}

bool	check_event(t_wolf *params)
{
	int				i;

	if (SDL_WaitEvent(&params->move_ev.code) != 0)
	{
	if ((params->move_ev.code.type == SDL_QUIT) || (params->move_ev.code.type == SDL_KEYDOWN
		&& params->move_ev.code.key.keysym.sym == SDLK_ESCAPE))
	{
		params->is_working = 0;
		return (true);
	}
	else if (params->move_ev.code.type == SDL_KEYDOWN)
	{
		key_down(params->move_ev.code.key.keysym.sym, params);
		return (true);
	}
	else if (params->move_ev.code.type == SDL_KEYUP)
	{
		key_up(params->move_ev.code.key.keysym.sym, params);
		return (true);
	}
	// else if (params->move_ev.code.type == SDL_MOUSEMOTION)
	// {
	// 	route_mouse_move(params);
	// 	return (true);
	// }
	if (params->pos_info.jump > 0)
	{
		Mix_PlayChannel(-1, params->sounds.sound1, 0);
		i = -1;
		while (++i < JUMP_HEIGHT)
		{
			params->pos_info.jump -= 1;
			make_calculations(params);
			draw_hud(params);
			SDL_UpdateWindowSurface(params->sdl.window);
		}
		return (true);
	}
	SDL_FlushEvent(params->move_ev.code.type);
	}
	return (false);
}
