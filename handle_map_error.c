/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:44:38 by abodnar           #+#    #+#             */
/*   Updated: 2019/05/01 17:44:41 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	handle_map_error(t_wolf *params)
{
	ft_printf("Error on map reading: %s\n", params->error);
	ft_strdel(&params->error);
	return (1);
}
