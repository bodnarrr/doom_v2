# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abodnar <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/16 12:17:53 by abodnar           #+#    #+#              #
#    Updated: 2018/05/22 12:21:33 by abodnar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = doom-nukem

LIB = libftprintf.a

SRCS =	add_perimeter_walls.c check_arguments.c check_event.c handle_error.c \
        handle_map_error.c height_for_column.c init_params.c init_position.c \
        init_sdl.c main.c make_calculations.c parse_map.c read_map.c \
        route_events.c set_wall_color.c mouse_move.c draw_sprites.c \
        draw_textured_wall.c draw_textured_floor.c draw_text.c \
        draw_hud.c

OBJECTS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror -O3

CGFLAGS = -framework OpenGL -framework AppKit

INCLUDES = -I./frameworks/SDL2.framework/Versions/A/Headers \
           -F./frameworks/

FRAMEWORKS = -F./frameworks \
               -rpath ./frameworks \
               -framework OpenGL -framework AppKit -framework SDL2 \
               -framework SDL2_image -framework SDL2_ttf -framework SDL2_mixer

HEADERS = *.h

all: $(NAME)

%.o : %.c
	@gcc $(FLAGS) -I. -I./libftprintf $(FLAGS) -c $< -o $@

$(NAME): $(LIB) $(OBJECTS) $(HEADERS)
	@gcc $(FLAGS) $(CGFLAGS) $(FRAMEWORKS) -o $@ -I. -I./libftprintf $(OBJECTS) $(LIB) $(INCLUDES)
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