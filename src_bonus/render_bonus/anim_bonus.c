/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 08:30:14 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/20 12:54:21 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
suseconds_t ft_get_time(void)
{
    struct timeval  now;
    gettimeofday(&now, NULL);
    return ((now.tv_sec * 1000) + (now.tv_usec / 1000));
}

void	update_enemy_frame_mov(t_game *game,t_timer *timer, double curr_time)
{
	double delta_time;
	int i;

	delta_time = curr_time - timer->last_time;
	timer->elapsed_time += delta_time;
	i = 0;
	while(i < game->enemy_count)
	{
		if(timer->elapsed_time >= FRAME_DURATION)
		{
			game->enemy[i].curr_frame = (game->enemy[i].curr_frame + 1) % NUM_FRAME;
			timer->elapsed_time = 0;
		}
		timer->last_time = curr_time;
		i++;
	}
}