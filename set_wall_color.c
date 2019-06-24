/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_wall_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 14:17:37 by abodnar           #+#    #+#             */
/*   Updated: 2019/05/05 14:17:38 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	set_wall_color(t_wolf *params, int value)
{
	if (value == 1)
		params->wall_color = HONEYFLOWER;
	else if (value == 2)
		params->wall_color = BLUMINE;
	else if (value == 3)
		params->wall_color = ATOLL;
	else if (value == 4)
		params->wall_color = BORDEAUX;
	else if (value == 5)
		params->wall_color = DELRIO;
	else if (value == 6)
		params->wall_color = CAMARONE;
	else if (value == 7)
		params->wall_color = WASABI;
	else if (value == 8)
		params->wall_color = LYNCH;
	else
		params->wall_color = JUNIPER;
}
