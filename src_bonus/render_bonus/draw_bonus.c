/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 01:16:57 by maugusto          #+#    #+#             */
/*   Updated: 2024/12/10 10:34:01 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup bonus Bonus
 * @{
 * @file draw_bonus.c
 * @brief Functions to draw the walls and textures.
*/

#include "cub3d_bonus.h"

/**
 * @brief Draw the pixel in the screen.
 * @param game Pointer to the game structure.
 * @param x X coordinate of the pixel.
 * @param texture Texture to draw.
*/
void	draw(t_game *game, int x, int texture)
{
	int	color;

	color = get_color(game, game->tex_x, game->tex_y, texture);
	if (game->wall_side == 1)
		color = (color >> 1) & 8355711;
	put_pixel(game, x, game->wall_start, color);
}

/**
 * @brief Define what to draw.
 * @param game Pointer to the game structure.
 * @param x X coordinate of the column.
*/
void	what_draw(t_game *game, int x)
{
	if (game->door_flag)
		draw(game, x, DOOR);
	else
	{
		if (game->wall_side == 1 && game->ray_dir_y < 0)
			draw(game, x, SOUTH);
		else if (game->wall_side == 1 && game->ray_dir_y > 0)
			draw(game, x, NORTH);
		else if (game->wall_side == 0 && game->ray_dir_x < 0)
			draw(game, x, WEST);
		else if (game->wall_side == 0 && game->ray_dir_x > 0)
			draw(game, x, EAST);
	}
}

/**
 * @brief Define the texture to draw.
 * @param game Pointer to the game structure.
 * @param start Start of the wall.
 * @param line_height Line height of the wall.
*/
void	define_texture(t_game *game, int start, int line_height)
{
	if (game->wall_side == 0)
		game->wall_x = game->player.y + game->walldist * game->ray_dir_y;
	else
		game->wall_x = game->player.x + game->walldist * game->ray_dir_x;
	game->wall_x -= floor(game->wall_x);
	game->tex_x = game->wall_x * 64;
	if (game->wall_side == 0 && game->ray_dir_x > 0)
		game->tex_x = 64 - game->tex_x - 1;
	if (game->wall_side == 1 && game->ray_dir_y < 0)
		game->tex_x = 64 - game->tex_x - 1;
	game->step = 1.0 * 64 / line_height;
	game->tex_pos = (start - SCREEN_HEIGHT / 2
			+ line_height / 2) * game->step;
}

/**
 * @brief Set the column size object
 * @param game Pointer to the game structure.
 * @param line_height Line height of the column.
 * @return int Returns the line height.
*/
int	set_column_size(t_game *game, int line_height)
{
	line_height = SCREEN_HEIGHT / game->walldist;
	game->wall_start = -line_height / 2 + SCREEN_HEIGHT / 2;
	if (game->wall_start < 0)
		game->wall_start = 0;
	game->wall_end = line_height / 2 + SCREEN_HEIGHT / 2;
	if (game->wall_end >= SCREEN_HEIGHT)
		game->wall_end = SCREEN_HEIGHT - 1;
	return (line_height);
}

/**
 * @brief Draw the column of the wall.
 * @param game Pointer to the game structure.
 * @param x X coordinate of the column.
*/
void	draw_column(t_game *game, int x)
{
	int	line_height;

	line_height = 0;
	line_height = set_column_size(game, line_height);
	define_texture(game, game->wall_start, line_height);
	while (game->wall_start < game->wall_end)
	{
		game->tex_y = (int)game->tex_pos;
		game->tex_pos += game->step;
		what_draw(game, x);
		game->wall_start++;
	}
}

/**@} */