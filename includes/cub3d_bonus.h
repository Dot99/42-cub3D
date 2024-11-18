/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 08:31:55 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/18 09:28:18 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "libft.h"
# include "mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <limits.h>
# define SPEED 0.1
# define ROTSPEED 0.05
# define MSPEED 0.03
# define FOV 90
# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3

typedef enum e_error
{
	ERROR_ARGS,
	ERROR_FILE,
	ERROR_MAP,
	ERROR_MALLOC,
	ERROR_COLOR,
	ERROR_TEXTURE,
	ERROR_MLX,
	ERROR_ORDER,
	ERROR_DUP,
}				t_error;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}				t_img;

typedef struct s_textr
{
	char	*north;
	char	*east;
	char	*south;
	char	*west;
	char	*floor;
	char	*ceiling;
	char	*door;
	char	*enemy1;
	char	*enemy2;
	char	*enemyd1;
	char	*enemyd2;
}				t_textr;

typedef struct s_enemy
{
	int		id;
	double	x;
	double	y;
	int		health;
	int		state;
}			t_enemy;

typedef struct s_player
{
	double	x;
	double	y;
	int		angle;
	double	dir_x;
	double	dir_y;
	int		move_up;
	int		move_down;
	int		move_left;
	int		move_right;
	int		rotate_left;
	int		rotate_right;
	int		health;
}				t_player;

typedef struct s_game
{
	char		**map;

	int			x;
	int			y;
	int			tlines;
	int			mapstart;
	int			mapend;	
	int			heightmap;
	int			widthmap;
	int			screen_width;
	int			screen_height;
	void		*mlx_ptr;
	void		*window;
	char		**rgb;
	bool		mapflag;

	int			rgb_sky[3];
	int			rgb_floor[3];
	t_textr		textr;
	t_img		img[10];
	t_img		minimap;
	t_player	player;
	t_enemy		enemy;

	int			wall_end;
	int			wall_start;
	double		plane_x;
	double		plane_y;
	double		ray_dir_x;
	double		ray_dir_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		side_dist_x;
	double		side_dist_y;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	int			wall_side;
	double		walldist;
	double		cam_x;

	double		wall_x;
	int			tex_x;
	int			tex_y;
	double		tex_pos;
	double		step;
}				t_game;

void	parse(char **argv, t_game *game);
void	check_extension(char *file);
void	read_map(char *file, t_game *game);
void	check_textures(t_game *game);
void	check_map_content(t_game *game);
void	check_file(char *file, t_game *game);
void	check_duplicate_text(t_game *game);
void	check_duplicate_text2(t_game *game);
void	read_textures(char *file, t_game *game);
char	*return_no_extra_spaces(char *tmp);
void	check_text_content(t_game *game, int *i);
void	check_rgb(char *color, t_game *game, int type);
void	check_colors(t_game *game);
void	check_order(char *file, t_game *game);
void	map_content_validation(t_game *game);
void	get_map_width(t_game *game);
void	check_dup_arr(int *arr, t_game *game);
void	put_textures(t_game *game, char *tmp);
void	check_doors(t_game *game, bool **map);
void	init_enemy(t_game *game);
int		sepuku(t_game *game, enum e_error i);
void	free_map(bool **map);
int		ft_exit(t_game *game);

int		controls(t_game *game);
void	init_img(t_game *game);

int		render(t_game *game);
void	raycasting(t_game *game);
void	draw_column(t_game *game, int x);

void	put_pixel(t_game *game, int x, int y, int color);
int		get_color(t_game *game, int x, int y, int i);

int		handle_mouse(int x, int y, t_game *game);
int		handle_key_release(int keycode, t_game *game);
int		handle_key_press(int keycode, t_game *game);

void	rotate(t_game *game, double angle);
int		move_left(t_game *game, double next_x, double next_y);
int		move_right(t_game *game, double next_x, double next_y);
int		move_down(t_game *game, double next_x, double next_y);
int		move_up(t_game *game, double next_x, double next_y);

void	render_minimap(t_game *game);
void	render_player_on_minimap(t_game *game);
void	draw_minimap_square(t_game *game, int x, int y, int color);
int		handle_mouse(int x, int y, t_game *game);
#endif