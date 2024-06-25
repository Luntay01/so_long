NAME = so_long

SRCS =  splash_run.c\
        splash_input.c\
        splash_images.c\
		splash_close.c\
		splash_update.c\
        main.c\
        map_make.c\
        map_check.c\
		map_check_path.c\
        map_final_image.c\
		map_final_image_2.c\
        game_run.c\
        game_images.c\
        game_images_2.c\
        game_images_3.c\
        game_input.c\
		game_update.c\
		game_enemy.c\
		game_render_enemy.c\
		game_background.c\
        game_close.c\
        game_utils.c\
        get_next_line.c\
		get_next_line_utils.c\
		end_run.c\
		end_input.c\
		end_images.c\
		end_close.c\
        options_run.c\
		options_input.c\
		options_images.c\
        intro_run.c\
		intro_images.c\
		intro_update.c\
		image_control.c\

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -g -Wall -Wextra -Werror -Imlx -I./libs/Frameworks/SDL2.framework/Versions/A/Headers -I./libs/Frameworks/SDL2_mixer.framework/Versions/A/Headers 

LIBS = -L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit -F./libs/Frameworks -framework SDL2 -framework SDL2_mixer

MLX_PATH = ./mlx

MLX = $(MLX_PATH)/libmlx.a

all: $(NAME)

$(NAME): $(OBJS) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	$(MAKE) fix_library_paths

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(MLX):
	$(MAKE) -C $(MLX_PATH)

fix_library_paths:
	install_name_tool -change @rpath/SDL2.framework/Versions/A/SDL2 @executable_path/libs/Frameworks/SDL2.framework/Versions/A/SDL2 ./so_long
	install_name_tool -change @rpath/SDL2_mixer.framework/Versions/A/SDL2_mixer @executable_path/libs/Frameworks/SDL2_mixer.framework/Versions/A/SDL2_mixer ./so_long

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	make -C $(MLX_PATH) clean

re: fclean all

.PHONY: all clean fclean re
