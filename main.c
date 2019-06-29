/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:45:41 by abodnar           #+#    #+#             */
/*   Updated: 2019/05/01 17:45:42 by abodnar          ###   ########.fr       */
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
	draw_text(&params);
	Mix_PlayMusic(params.sdl.music, 1);
	while (params.is_working && SDL_WaitEvent(&params.sdl.event))
		if (check_event(params.sdl.event, &params))
		{
			make_calculations(&params);
			draw_sprites(&params);
			draw_hud(&params);
			draw_text(&params);
			SDL_UpdateWindowSurface(params.sdl.window);
		}
	return (0);
}
