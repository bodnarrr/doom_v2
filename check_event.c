/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshchuro <pshchuro@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:43:29 by abodnar           #+#    #+#             */
/*   Updated: 2019/06/29 20:59:12 by pshchuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

static bool		is_active_event(SDL_Scancode code)
{
	if (code == SDL_SCANCODE_W
		|| code == SDL_SCANCODE_A
		|| code == SDL_SCANCODE_S
		|| code == SDL_SCANCODE_D
		|| code == SDL_SCANCODE_UP
		|| code == SDL_SCANCODE_DOWN
		|| code == SDL_SCANCODE_LEFT
		|| code == SDL_SCANCODE_RIGHT
		|| code == SDL_SCANCODE_SPACE
		|| code == SDL_SCANCODE_LSHIFT
		|| code == SDL_SCANCODE_LCTRL)
		return (TRUE);
	return (FALSE);
}

bool	check_event(SDL_Event event, t_wolf *params)
{
	SDL_Scancode	code;

	code = event.key.keysym.scancode;
	if ((event.type == SDL_QUIT) || (event.type == SDL_KEYDOWN
		&& code == SDL_SCANCODE_ESCAPE))
	{
		params->is_working = 0;
		return (true);
	}
	else if (event.type == SDL_KEYDOWN
				&& is_active_event(code))
	{
		route_events(code, params);
		return (true);
	}
	else if (event.type == SDL_MOUSEMOTION)
	{
		route_mouse_move(event.motion, params);
		return (true);
	}
	return (false);
}
