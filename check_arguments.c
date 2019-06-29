/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:43:09 by abodnar           #+#    #+#             */
/*   Updated: 2019/05/01 17:43:13 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

bool	check_arguments(int ac, t_wolf *params)
{
	if (ac != 2)
	{
		params->error = ft_strdup("Usage: ./wolf3d <map_name>");
		return (FALSE);
	}
	return (TRUE);
}
