/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:45:20 by abodnar           #+#    #+#             */
/*   Updated: 2019/06/29 16:40:52 by pshchuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"

void	init_position(t_wolf *params)
{
	params->pos_info.dir_x = -1;
	params->pos_info.dir_y = 0;
	params->pos_info.plane_x = 0;
	params->pos_info.plane_y = 0.66;
	params->pos_info.move_speed = 0.069;
	params->pos_info.rotate_speed = 0.019;
	params->pos_info.v_rotate = 0;
	params->pos_info.height = 0;
	params->pos_info.jump = 0;
}
