/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonischu <vonischu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:43:29 by abodnar           #+#    #+#             */
/*   Updated: 2019/06/29 21:43:26 by vonischu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"

void	key_down(int key, t_wolf *params)
{
	if (key == SDLK_UP || key == SDLK_w)
		params->move_ev.ws = 1;
	else if (key == SDLK_DOWN || key == SDLK_s)
		params->move_ev.ws = -1;
	else if (key == SDLK_RIGHT || key == SDLK_d)
		params->move_ev.ad = -1;
	else if (key == SDLK_LEFT || key == SDLK_a)
		params->move_ev.ad = 1;
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
	SDL_Event	code;
	int				i;

	if (SDL_PollEvent(&code) != 0)
	{
	if ((code.type == SDL_QUIT) || (code.type == SDL_KEYDOWN
		&& code.key.keysym.sym == SDLK_ESCAPE))
	{
		params->is_working = 0;
		return (true);
	}
	else if (code.type == SDL_KEYDOWN)
	{
		key_down(code.key.keysym.sym, params);
		return (true);
	}
	else if (code.type == SDL_KEYUP)
	{
		key_up(code.key.keysym.sym, params);
		return (true);
	}
	else if (code.type == SDL_MOUSEMOTION)
	{
		route_mouse_move(code.motion, params);
		return (true);
	}
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
	}
	return (false);
}
