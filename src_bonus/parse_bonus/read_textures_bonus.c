/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_textures_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:51:55 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/28 10:54:19 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	check_dup2(int *arr, int fd, char **temp)
{
	char	*tmp;

	tmp = return_no_extra_spaces(*temp);
	if (tmp[0] == 'N' && tmp[1] == 'O')
		arr[0]++;
	else if (tmp[0] == 'S' && tmp[1] == 'O')
		arr[1]++;
	else if (tmp[0] == 'W' && tmp[1] == 'E')
		arr[2]++;
	else if (tmp[0] == 'E' && tmp[1] == 'A')
		arr[3]++;
	else if (tmp[0] == 'F' && tmp[1] == ' ')
		arr[4]++;
	else if (tmp[0] == 'C' && tmp[1] == ' ')
		arr[5]++;
	else if (tmp[0] == 'D' && tmp[1] == ' ')
		arr[6]++;
	else if (tmp[0] == 'X' && tmp[1] == ' ')
		arr[7]++;
	free(tmp);
	*temp = get_next_line(fd);
}

void	check_dup(int fd, t_game *game, int *arr)
{
	char	*tmp;

	tmp = get_next_line(fd);
	while (tmp != NULL)
		check_dup2(arr, fd, &tmp);
	free(tmp);
	check_dup_arr(arr, game);
}

void	read_textures3(t_game *game, char **temp, int *i, int fd)
{
	char	*tmp;

	tmp = *temp;
	tmp = return_no_extra_spaces(tmp);
	put_textures(game, tmp);
	free(tmp);
	*temp = get_next_line(fd);
	tmp = *temp;
	(*i)++;
	check_text_content(game, i);
}

void	read_textures2(int fd, t_game *game)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = get_next_line(fd);
	while (tmp != NULL && game->mapflag == false)
		read_textures3(game, &tmp, &i, fd);
	while (tmp != NULL)
	{
		free(tmp);
		tmp = get_next_line(fd);
	}
	free(tmp);
}

void	read_textures(char *file, t_game *game)
{
	int		fd;
	int		arr[6];
	int		i;

	i = 0;
	game->mapflag = false;
	while (i < 8)
		arr[i++] = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		sepuku(game, ERROR_FILE);
	check_dup(fd, game, arr);
	close(fd);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		sepuku(game, ERROR_FILE);
	read_textures2(fd, game);
	close(fd);
}
