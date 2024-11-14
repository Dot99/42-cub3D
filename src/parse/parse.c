/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:32:53 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/14 08:57:24 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse(char **argv, t_game *game)
{
	check_order(argv[1], game);
	read_textures(argv[1], game);
	check_colors(game);
	check_textures(game);
	read_map(argv[1], game);
	check_map_content(game);
	//TODO:PRECISO DO WIDTHMAP
	game->heightmap = game->mapend;
	map_content_validation(game);
}
