/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:57:01 by gude-jes          #+#    #+#             */
/*   Updated: 2024/10/24 11:39:54 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game *game;

	if(argc == 2)
	{
		check_extension(argv[1]);
		game = init();
		parse(game);
	}
	return(EXIT_SUCCESS);
}