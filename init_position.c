/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshchuro <pshchuro@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:45:20 by abodnar           #+#    #+#             */
/*   Updated: 2019/06/30 11:44:20 by pshchuro         ###   ########.fr       */
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
	params->pos_info.height = 0;
}
