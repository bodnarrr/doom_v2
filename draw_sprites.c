/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 20:17:37 by abodnar           #+#    #+#             */
/*   Updated: 2019/06/29 20:17:38 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"

void	draw_sprites(t_wolf *params)
{
	double	spriteX;
	double	spriteY;
	double	invDet;
	double	transformX;
	double	transformY;
	int		spriteScreenX;
	int		spriteHeight;
	int		drawStartY;
	int		drawEndY;
	int		spriteWidth;
	int		drawStartX;
	int		drawEndX;
	int		i;
	int		j;
	int		texX;
	int		texY;
	int		pos;
	int		d;
	Uint32	color;

	spriteX = params->sprite.x - params->pos_info.pos_x;
	spriteY = params->sprite.y - params->pos_info.pos_y;
	invDet = 1.0 / (params->pos_info.plane_x * params->pos_info.dir_y
			- params->pos_info.dir_x * params->pos_info.plane_y);
	transformX = invDet * (params->pos_info.dir_y * spriteX
								- params->pos_info.dir_x * spriteY);
	transformY = invDet * (-params->pos_info.plane_y * spriteX
								+ params->pos_info.plane_x * spriteY);
	spriteScreenX = (int)((SCREEN_WIDTH / 2) * (1 + transformX / transformY));
	spriteHeight = abs((int)(SCREEN_HEIGHT / (transformY)));
	drawStartY = -spriteHeight / 2 + SCREEN_HEIGHT / 2;
	if (drawStartY < 0)
		drawStartY = 0;
	drawEndY = spriteHeight / 2 + SCREEN_HEIGHT / 2;
	if (drawEndY >= SCREEN_HEIGHT)
		drawEndY = SCREEN_HEIGHT - 1;
	spriteWidth = abs((int)(SCREEN_HEIGHT / (transformY)));
	drawStartX = -spriteWidth / 2 + spriteScreenX;
	if (drawStartX < 0)
		drawStartX = 0;
	drawEndX = spriteWidth / 2 + spriteScreenX;
	if (drawEndX >= SCREEN_WIDTH)
		drawEndX = SCREEN_WIDTH - 1;
	i = drawStartX;
	while (i < drawEndX)
	{
		texX = (int)(256 * (i - (-spriteWidth / 2 + spriteScreenX))
							* params->sprite.texture->w / spriteWidth) / 256;
		if (transformY > 0 && i > 0 && i < SCREEN_WIDTH
							&& transformY < params->z_buffer[i])
		{
			j = drawStartY;
			while (j < drawEndY)
			{
				pos = i + (j * SCREEN_WIDTH);
				d = j * 256 - SCREEN_HEIGHT * 128 + spriteHeight * 128;
				texY = ((d * params->sprite.texture->h) / spriteHeight) / 256;
				color = ((Uint32*)params->sprite.texture->pixels)
						[params->sprite.texture->w * texY + texX];
				if ((color & 0x00FFFFFF) != 0)
					((Uint32*)params->sdl.surface->pixels)[pos] = color;
				j++;
			}
		}
		i++;
	}
}
