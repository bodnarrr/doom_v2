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

#include "wolf3d.h"

int			main(int ac, char **av)
{
	t_wolf	params;

	if (!check_arguments(ac, &params))
		return (handle_error(&params));
	init_parameters(&params);
	if (!read_map(&params, av[1]))
		return (handle_map_error(&params));
	if (!init_sdl(&params))
		return (handle_error(&params));
	init_position(&params);
	make_calculations(&params);
	while (params.is_working && SDL_WaitEvent(&params.sdl.event))
		check_event(params.sdl.event, &params);
	return (0);
}
