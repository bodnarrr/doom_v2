/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:43:29 by abodnar           #+#    #+#             */
/*   Updated: 2019/05/01 17:43:30 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static bool	is_active_event(SDL_Scancode code)
{
	if (code == SDL_SCANCODE_W
		|| code == SDL_SCANCODE_A
		|| code == SDL_SCANCODE_S
		|| code == SDL_SCANCODE_D
		|| code == SDL_SCANCODE_UP
		|| code == SDL_SCANCODE_DOWN
		|| code == SDL_SCANCODE_LEFT
		|| code == SDL_SCANCODE_RIGHT
		|| code == SDL_SCANCODE_SPACE)
		return (TRUE);
	return (FALSE);
}

void		check_event(SDL_Event event, t_wolf *params)
{
	SDL_Scancode	code;

	code = event.key.keysym.scancode;
	if ((event.type == SDL_QUIT) || (event.type == SDL_KEYDOWN
		&& code == SDL_SCANCODE_ESCAPE))
		params->is_working = 0;
	else if (event.type == SDL_KEYDOWN
				&& is_active_event(code))
	{
		route_events(code, params);
		make_calculations(params);
		draw_sprites(params);
	}
	else if (event.type == SDL_MOUSEMOTION)
	{
		route_mouse_move(event.motion, params);
		make_calculations(params);
		draw_sprites(params);
	}
	if (params->pos_info.jump > 0)
	{
		int i = -1;
		while (++i < JUMP_HEIGHT)
		{
			params->pos_info.jump -= 1;
			make_calculations(params);
		}
	}
}
