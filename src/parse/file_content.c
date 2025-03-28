/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:22:35 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/26 10:52:38 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup mandatory Mandatory
 * @{
 * @file file_content.c
 * @brief Check the order of the file and if there is any random content.
 */

#include "cub3d.h"

/**
 * @brief Check if the line is a texture.
 * @param line Line to check.
 * @return int Return 1 if the line is a texture, 0 otherwise.
*/
int	is_texture(char *line)
{
	int	i;

	i = 0;
	while (ft_is_wspace(line[i]))
		i++;
	if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
		return (1);
	if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
		return (1);
	if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
		return (1);
	if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
		return (1);
	if (line[i] == 'F' && line[i + 1] == ' ')
		return (1);
	if (line[i] == 'C' && line[i + 1] == ' ')
		return (1);
	return (0);
}

/**
 * @brief Check the order of the file.
 * 
 * @param fd File descriptor.
 * @param game Struct with the game information.
*/
void	check_order2(int fd, t_game *game)
{
	int		map_start;
	bool	flag;
	char	*tmp;
	char	*ptr;

	tmp = get_next_line(fd);
	map_start = 0;
	flag = false;
	while (tmp != NULL)
	{
		ptr = tmp;
		while (ft_is_wspace(*ptr) && *tmp != '\n')
			ptr++;
		if (ft_isdigit(*ptr) && flag == false)
			map_start = 1;
		if (is_texture(ptr) && map_start == 1 && flag == false)
			flag = true;
		free(tmp);
		tmp = get_next_line(fd);
	}
	free(tmp);
	if (flag)
		sepuku(game, ERROR_ORDER);
}

/**
 * @brief Continue checking for random content.
 * 
 * @param fd File descriptor.
 * @param tmp Temporary string.
*/
void	check_random2(int fd, char *tmp)
{
	int	i;

	i = 0;
	while (tmp && (is_texture(tmp) || *tmp == '\n'))
	{
		free(tmp);
		tmp = get_next_line(fd);
	}
	while (ft_is_wspace(tmp[i]))
		i++;
	while (tmp && ft_isdigit(tmp[i]))
	{
		free(tmp);
		tmp = get_next_line(fd);
		i = 0;
		while (tmp != NULL && ft_is_wspace(tmp[i]) && tmp[i] != '\n')
			i++;
	}
	free(tmp);
}

/**
 * @brief Check if there is any random content in the file.
 * @param fd File descriptor.
 * @param game Struct with the game information.
*/
void	check_random(int fd, t_game *game)
{
	char	*tmp;

	tmp = get_next_line(fd);
	check_random2(fd, tmp);
	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
		if (ft_isdigit(*tmp) || ft_isalpha(*tmp))
		{
			while (tmp != NULL)
			{
				free(tmp);
				tmp = get_next_line(fd);
			}
			free(tmp);
			sepuku(game, ERROR_ORDER);
		}
		free(tmp);
		tmp = get_next_line(fd);
	}
	free(tmp);
}

/**
 * @brief Check the order of the file.
 * 
 * @param file File to check.
 * @param game Struct with the game information.
*/
void	check_order(char *file, t_game *game)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		sepuku(game, ERROR_FILE);
	check_order2(fd, game);
	close(fd);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		sepuku(game, ERROR_FILE);
	check_random(fd, game);
	close(fd);
}

/**@} */