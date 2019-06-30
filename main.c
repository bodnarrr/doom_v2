/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonischu <vonischu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:45:41 by abodnar           #+#    #+#             */
/*   Updated: 2019/06/30 10:16:23 by vonischu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"

int			main(int ac, char **av)
{
	t_wolf	params;

	ft_bzero(&params, sizeof(t_wolf));
	if (!check_arguments(ac, &params))
		return (handle_error(&params));
	init_parameters(&params);
	if (!read_map(&params, av[1]))
		return (handle_map_error(&params));
	if (!init_sdl(&params))
		return (handle_error(&params));
	init_position(&params);
	make_calculations(&params);
	draw_hud(&params);
	Mix_PlayMusic(params.sounds.music, 1);
	while (params.is_working)
	{
			check_event(&params);
			route_events(&params);
			if (params.move_ev.code.type == SDL_MOUSEMOTION)
				route_mouse_move(&params);
			// if (params.move_ev.code.type == SDL_MOUSEMOTION)
			// 	route_mouse_move(&params);
			make_calculations(&params);
			draw_sprites(&params);
			draw_hud(&params);
			SDL_UpdateWindowSurface(params.sdl.window);
		}
	return (0);
}
