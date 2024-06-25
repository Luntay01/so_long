/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmordaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:26:44 by kmordaun          #+#    #+#             */
/*   Updated: 2023/09/14 14:17:03 by kmordaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <SDL.h>
# include <SDL_mixer.h>
# include "get_next_line.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	int		param;
	int		selected;
	int		current_frame;
	int		going_to_game;
	int		difficulty;
	void	*pl[47];
	void	*gt[14];
	void	*ms[14];
	int		trans;
	int		map_selected;
	void	*pa[14];
	void	*img_splash;
}		t_mlx;

typedef enum e_walls
{
	T_FALSE,
	T_TRUE
}	t_walls;

typedef struct s_enemy
{
	float	pos_x;
	float	pos_y;
	float	rotation;
	int		current_frame;
}		t_enemy;

typedef struct s_map
{
	void	*img;
	void	*imgfont;
	char	tile;
	int		visited;
	int		pos_x;
	int		pos_y;
}		t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*par[4];
	void		*pal[4];
	void		*p_a_r[5];
	void		*p_a_l[5];
	void		*la[19];
	void		*e_a[26];
	void		*b_e[25];
	void		*o_a[122];
	void		*e360[4];
	void		*e22[4];
	void		*e45[4];
	void		*e67[4];
	void		*e90[4];
	void		*e112[4];
	void		*e135[4];
	void		*e157[4];
	void		*e180[4];
	void		*e202[4];
	void		*e225[4];
	void		*e247[4];
	void		*e270[4];
	void		*e292[4];
	void		*e315[4];
	void		*e337[4];
	void		*o_d;
	int			w;
	int			h;	
	int			pp;
	int			facing_r;
	int			attack_on;
	int			win_game;
	int			end_pos;
	int			old_men;
	int			e_i;
	int			num_enemies;
	int			max_enemies;
	int			player_steps;
	int			most_eff;
	int			map_width;
	int			map_height;
	int			map_nbr;
	int			becoming_frame;
	int			current_frame;
	int			old_man_frame;
	int			enemy_frame;
	int			lantern_frame;
	int			difficulty;
	int			fd;
	char		*gnl_temp;
	char		*gnl_str;
	char		*gnl_line;
	float		angle;
	float		speed;
	t_enemy		*enemy;	
	t_map		*map;
	Mix_Music	*music;
}		t_game;
//	Mix_Music	*music;

void	render_enemies(t_game *game);
void	run_intro(void *mlx);
void	init_images_intro(t_mlx *intro);
int		update_intro(t_mlx *intro);
int		keyboard_event_splash(int keycode, t_mlx *splash);
int		handle_close_event_splash(t_mlx *splash, int screen);
void	init_images(t_mlx *splash);
int		update_splash(t_mlx *splash);
int		run_splash(void *mlx, int difficulty);
void	load_game(int selected, t_mlx *splash);
void	run_game(char *filename, void *mlx, int map_selected, int difficulty);
int		create_map(char *filename, t_game *game);
void	check_wall_surrounds_2(int p, t_map *map, t_game *game);
void	check_wall_surrounds_3(int p, t_map *map, t_game *game);
void	check_wall_surrounds_4(int p, t_map *map, t_game *game);
void	check_wall_surrounds_5(int p, t_map *map, t_game *game);
void	check_wall_surrounds_6(int p, t_map *map, t_game *game);
char	check_open(char c);
char	*get_next_line(int fd);
char	*get_next_line(int fd);
size_t	mod_strlen(char *s);
char	*mod_strchr(char *s, int c);
char	*mod_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
int		check_map_error(char *s, t_map *map, t_game *game);
int		check_valid_path(t_map *map, t_game *game);
void	finalize_map(t_map *map, t_game *game);
void	game_images11(t_game *game);
void	game_images06(t_game *game);
void	game_images01(t_game *game);
size_t	mod_get_digits(int n);
char	*mod_ft_itoa(int n);
float	c_angle(float startX, float startY, float targetX, float targetY);
int		keyboard_event_game(int keycode, t_game *game);
int		handle_close_event_game(t_game *game, int screen);
int		update_game(t_game *game);
void	update_enemies(t_game *game);
void	put_background(t_game *game);
int		run_end(void *mlx, int map_selected, int win, int difficulty);
int		keyboard_event_end(int keycode, t_mlx *end);
void	init_images_end(t_mlx *end);
int		handle_close_event_end(t_mlx *end, int screen);
int		run_options(void *mlx, int difficulty);
void	init_images_options(t_mlx *options);
int		keyboard_event_options(int keycode, t_mlx *options);
int		handle_close_event_options(t_mlx *options, int screen);
void	load_game(int selected, t_mlx *splash);
void	*xf(void *mlx_ptr, char *filename, int *width, int *height);

#endif
