# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pshchuro <pshchuro@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/16 12:17:53 by abodnar           #+#    #+#              #
#    Updated: 2019/06/29 20:13:12 by vonischu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = doom-nukem

LIB = libftprintf.a

SRCS =	add_perimeter_walls.c check_arguments.c check_event.c handle_error.c \
        handle_map_error.c height_for_column.c init_params.c init_position.c \
        init_sdl.c main.c make_calculations.c parse_map.c read_map.c \
        route_events.c mouse_move.c draw_sprites.c \
        draw_textured_wall.c draw_textured_floor.c \
        draw_hud.c load_sprites_textures.c sprites_pickup.c process_finish.c \
        fly_jump.c load_wall_textures.c calc_cam_ray.c key_down.c clear_all.c

OBJECTS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror -O3

CGFLAGS = -framework OpenGL -framework AppKit

INCLUDES = 		-I frameworks/SDL2.framework/Versions/A/Headers \
				-I frameworks/SDL2_ttf.framework/Versions/A/Headers \
				-I frameworks/SDL2_image.framework/Versions/A/Headers \
				-I frameworks/SDL2_mixer.framework/Versions/A/Headers \
				-F ./frameworks 

FRAMEWORKS	=	-F ./frameworks \
				-rpath @loader_path/frameworks \
				-framework SDL2 -framework SDL2_image -framework SDL2_ttf -framework SDL2_mixer

HEADERS = *.h

all: $(NAME)

%.o : %.c
	@gcc $(FLAGS) -I. -I./libftprintf $(FLAGS) -c $< -o $@ $(INCLUDES) 

$(NAME): $(LIB) $(OBJECTS) $(HEADERS)
	@gcc $(FLAGS) $(CGFLAGS) $(FRAMEWORKS) -o $@ -I. -I./libftprintf $(OBJECTS) $(LIB) 
	@echo "\033[1;32mDoom-Nukem is ready\033[0m"

$(LIB):
	@make -C ./libftprintf/
	@cp ./libftprintf/libftprintf.a .

clean:
	@make fclean -C ./libftprintf
	@rm -f *.o
	@rm -f libftprintf.a
	@echo "\033[1;32mObject files were removed\033[0m"

fclean: clean
	@rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re