/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:46:15 by abodnar           #+#    #+#             */
/*   Updated: 2019/05/01 17:46:16 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOM_NUKEM_H
# define DOOM_NUKEM_H

# include "libftprintf/libftprintf.h"
# include "frameworks/SDL2/SDL.h"
# include "frameworks/SDL2/SDL_image.h"
# include "frameworks/SDL2/SDL_ttf.h"
# include "frameworks/SDL2/SDL_mixer.h"
# include <math.h>
# include <stdlib.h>

# include <math.h>

# include <stdbool.h>

# define SCREEN_WIDTH 1200
# define SCREEN_HEIGHT 800
# define TRUE 1
# define FALSE 0
# define READ_SIZE 32

# define MIN_SPEED 0
# define MAX_SPEED 0.25

# define MIN_ROTATE_SPEED 0
# define MAX_ROTATE_SPEED 0.12

# define TX_COUNT 3

# define SPEED_RIGHT -1.5
# define SPEED_LEFT 1.5

# define JUMP_HEIGHT 80

typedef struct	s_sdl
{
	SDL_Window	*window;
	SDL_Surface	*surface;
	SDL_Event	event;
	Mix_Music	*music;
    double		ray_dir_x;
    double		ray_dir_y;
    int			map_x;
    int			map_y;
}				t_sdl;

typedef struct	s_sprite
{
    SDL_Surface	*texture;
    int 		x;
    int 		y;
}				t_sprite;

typedef struct	s_hud
{
	SDL_Surface	*main_HUD;
	SDL_Surface	*face;
	int 		x;
	int 		y;
}				t_hud;

typedef struct	s_draw_wall
{
	int			wall_start;
	int 		wall_end;
	Uint32		*pixels;
	int 		tex_x;
	int 		tex_y;
	int 		d;
	int         pos;
}				t_draw_wall;

typedef struct 	s_draw_floor
{
	int 		wall_start;
	int 		wall_end;
	Uint32		*pixels;
	double		floor_x;
	double 		floor_y;
	int 		pos;
	double 		dist_wall;
	double		dist_pl;
	double		cur_dist;
	double 		weight;
	double 		cur_floor_x;
	double 		cur_floor_y;
	int 		floor_tex_x;
	int 		floor_tex_y;
	int 		ceil_pos;
}				t_draw_floor;

typedef struct	s_position
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		move_speed;
	double		rotate_speed;
	int 		height;
	double		jump;
	double		perp_wall_dist;
}				t_position;

typedef struct	s_wolf
{
	t_sdl		sdl;
	t_position	pos_info;
	int			**map;
	int			map_height;
	bool		is_working;
	bool		did_read_map;
	char		*error;
	int			side;
	Uint32		wall_color;
	SDL_Surface *texture;
	SDL_Surface *textures[TX_COUNT];
	int 		tex_ind;
	t_hud		hud;
	t_sprite	sprite;
	double 		wall_x;
	double 		ray_x;
	double 		ray_y;
	double		z_buffer[SCREEN_WIDTH];
	SDL_Surface	*ceil_tex;
	SDL_Surface	*floor_tex;
}				t_wolf;

typedef struct	s_iteration
{
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
}				t_iterations;

bool			check_arguments(int ac, t_wolf *params);
int				handle_error(t_wolf *params);
void			init_parameters(t_wolf *params);
bool			read_map(t_wolf *params, char *input);
int				handle_map_error(t_wolf *params);
bool			init_sdl(t_wolf *params);
void			init_position(t_wolf *params);
bool			check_event(SDL_Event event, t_wolf *params);
void			make_calculations(t_wolf *params);
int				height_for_column(int x, t_wolf *params);
void			route_events(SDL_Scancode code, t_wolf *params);
void			parse_map(t_wolf *params, char *raw_map);
void			add_perimeter_walls(int **map);
void			set_wall_color(t_wolf *params, int value);
void			route_mouse_move(SDL_MouseMotionEvent event, t_wolf *params);
void			draw_sprites(t_wolf *params);
void            hud(t_wolf *params);
void			draw_textured_wall(int x, int height, t_wolf *params);
void			draw_textured_floor(int x, int height, t_wolf *params);
void			draw_text(t_wolf *params);
void			draw_hud(t_wolf *params);

#endif
