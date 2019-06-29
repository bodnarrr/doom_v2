//
// Created by Andrii Bodnar on 2019-06-26.
//

#include "doom-nukem.h"

void	draw_sprites(t_wolf *params)
{
//	ft_bzero(params->sdl.surface->pixels, params->sdl.surface->w * params->sdl.surface->h);


	double spriteX = params->sprite.x - params->pos_info.pos_x;

	double spriteY = params->sprite.y - params->pos_info.pos_y;

	double invDet = 1.0 / (params->pos_info.plane_x * params->pos_info.dir_y
			- params->pos_info.dir_x * params->pos_info.plane_y);

	double transformX = invDet * (params->pos_info.dir_y * spriteX - params->pos_info.dir_x * spriteY);

	double transformY = invDet * (-params->pos_info.plane_y * spriteX + params->pos_info.plane_x * spriteY);



	int spriteScreenX = (int)((SCREEN_WIDTH / 2) * (1 + transformX / transformY));

	//calculate height of the sprite on screen
	int spriteHeight = abs((int)(SCREEN_HEIGHT / (transformY)));

	//calculate lowest and highest pixel to fill in current stripe
	int drawStartY = -spriteHeight / 2 + SCREEN_HEIGHT / 2;
	if (drawStartY < 0)
		drawStartY = 0;
	int drawEndY = spriteHeight / 2 + SCREEN_HEIGHT / 2;
	if (drawEndY >= SCREEN_HEIGHT)
		drawEndY = SCREEN_HEIGHT - 1;

	//calculate width of the sprite
	int spriteWidth = abs((int)(SCREEN_HEIGHT / (transformY)));

	int drawStartX = -spriteWidth / 2 + spriteScreenX;
	if (drawStartX < 0)
		drawStartX = 0;
	int drawEndX = spriteWidth / 2 + spriteScreenX;
	if (drawEndX >= SCREEN_WIDTH)
		drawEndX = SCREEN_WIDTH - 1;

	//loop through every vertical stripe of the sprite on screen
	for(int stripe = drawStartX; stripe < drawEndX; stripe++)
	{
		int texX = (int)(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * params->sprite.texture->w / spriteWidth) / 256;


		if(transformY > 0 && stripe > 0 && stripe < SCREEN_WIDTH && transformY < params->z_buffer[stripe])
			for(int y = drawStartY; y < drawEndY; y++) //for every pixel of the current stripe
			{
				int pos = stripe + (y * SCREEN_WIDTH);

				int d = (y) * 256 - SCREEN_HEIGHT * 128 + spriteHeight * 128; //256 and 128 factors to avoid floats
				int texY = ((d * params->sprite.texture->h) / spriteHeight) / 256;
				Uint32 color = ((Uint32*)params->sprite.texture->pixels)[params->sprite.texture->w * texY + texX]; //get current color from the texture
				if((color & 0x00FFFFFF) != 0)
					((Uint32*)params->sdl.surface->pixels)[pos] = color; //paint pixel if it isn't black, black is the invisible color
			}
	}
}
