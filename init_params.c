/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:45:13 by abodnar           #+#    #+#             */
/*   Updated: 2019/05/01 17:45:14 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"

void	init_parameters(t_wolf *params)
{
	ft_bzero(params, sizeof(t_wolf));
	params->is_working = 1;
	params->map_height = 1;
	params->wall_x = 0.0;
	params->ray_x = 0;
	params->ray_y = 0;
}
