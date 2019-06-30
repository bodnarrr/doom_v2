/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshchuro <pshchuro@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:43:29 by abodnar           #+#    #+#             */
/*   Updated: 2019/06/30 13:00:47 by vonischu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	jump(t_wolf *params)
{
	int height;
	int delta_height;

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

void	define_mouse(t_wolf *params)
{
	if (params->move_ev.code.motion.xrel > 0)
		params->move_ev.mws = -1;
	else if (params->move_ev.code.motion.xrel < 0)
		params->move_ev.mws = 1;
	if (params->move_ev.code.motion.yrel > 0)
		params->move_ev.mad = 1;
	else if (params->move_ev.code.motion.yrel < 0)
		params->move_ev.mad = -1;
}

void	check_event(t_wolf *params)
{
	if (SDL_WaitEvent(&params->move_ev.code))
	{
		if ((params->move_ev.code.type == SDL_QUIT)
			|| (params->move_ev.code.type == SDL_KEYDOWN
				&& params->move_ev.code.key.keysym.sym == SDLK_ESCAPE))
		{
			params->is_working = 0;
			SDL_FlushEvent(params->move_ev.code.type);
			return ;
		}
		else if (params->move_ev.code.type == SDL_KEYDOWN)
		{
			SDL_FlushEvent(params->move_ev.code.type);
			return (key_down(params->move_ev.code.key.keysym.sym, params));
		}
		else if (params->move_ev.code.type == SDL_KEYUP)
		{
			SDL_FlushEvent(params->move_ev.code.type);
			return (key_up(params->move_ev.code.key.keysym.sym, params));
		}
		else if (params->move_ev.code.type == SDL_MOUSEMOTION)
		{
			define_mouse(params);
			SDL_FlushEvent(params->move_ev.code.type);
			return ;
		}
		else if (params->move_ev.mouse.xrel == 0
			&& params->move_ev.mouse.yrel == 0)
		{
			params->move_ev.mad = 0;
			params->move_ev.mws = 0;
			SDL_FlushEvent(params->move_ev.code.type);
			return ;
		}
		params->move_ev.mouse = params->move_ev.code.motion;
	}
}
