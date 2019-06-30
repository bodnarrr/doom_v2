/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 14:10:32 by abodnar           #+#    #+#             */
/*   Updated: 2019/05/05 14:10:32 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

static void	parse_sprites(t_wolf *params)
{
	ft_printf("Sprites amount: %d\n", params->sprite_amount);
}

static int	*line_to_int_arr(char *line, t_wolf *params)
{
	char	**splt;
	int		i;
	int		j;
	int		*res;

	splt = ft_strsplit(line, ' ');
	i = 0;
	while (splt[i])
		i++;
	res = (int*)ft_memalloc(sizeof(int) * (i + 1));
	j = -1;
	while (++j < i)
	{
		res[j] = ft_atoi(splt[j]);
		if (res[j] > 9 && res[j] < 20)
			params->sprite_amount++;
	}
	res[j] = -1;
	i = 0;
	while (splt[i])
		free(splt[i++]);
	free(splt);
	return (res);
}

void		parse_map(t_wolf *params, char *raw_map)
{
	int		i;
	char	*map_cpy;
	char	*line;

	params->map = (int**)ft_memalloc(sizeof(int*) * (params->map_height + 1));
	map_cpy = raw_map;
	i = 0;
	while (i < params->map_height)
	{
		line = ft_strsub_chr(map_cpy, '\n');
		params->map[i] = line_to_int_arr(line, params);
		ft_strdel(&line);
		map_cpy = ft_strchr(map_cpy, '\n') + 1;
		i++;
	}
	params->map[i] = NULL;
	parse_sprites(params);
	params->did_read_map = TRUE;
}
