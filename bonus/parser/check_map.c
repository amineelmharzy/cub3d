/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou <mkhellou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 10:55:34 by ael-mhar          #+#    #+#             */
/*   Updated: 2023/07/25 15:51:57 by ael-mhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_extention(char *file_name)
{
	int	i;

	i = ft_strlen(file_name);
	if (i < 4)
		return (write_error(0), 0);
	if (file_name[0] == '.')
		return (write_error(8), 0);
	while (i > 0)
	{
		if (ft_strlen(&file_name[i]) == 4)
			break ;
		i--;
	}
	if (ft_strncmp(&file_name[i], ".cub", 4))
		return (0);
	return (1);
}

int	check_map_elements(t_cub *cub)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	count = 0;
	while (++i < cub->map_height)
	{
		j = -1;
		while (++j < cub->map_width)
		{
			if (!ft_strchr(" 01NSEWOCI", cub->map[i][j]))
				return (write_error(5), 0);
			if (ft_strchr("NSEW", cub->map[i][j]))
			{
				cub->px = j;
				cub->py = i;
				cub->player_direction = cub->map[i][j];
				count++;
			}
		}
	}
	if (count != 1)
		return (write_error(6), 0);
	return (1);
}

int	check_edges(t_cub *cub)
{
	int	i;
	int	j;

	i = -1;
	while (++i < cub->map_height)
	{
		j = -1;
		while (++j < cub->map_width)
		{
			if (cub->map[i][j] != '1' && cub->map[i][j] != ' ' && (j == 0
					|| i == 0 || j == cub->map_width - 1 || i == cub->map_height
					- 1 || cub->map[i][j - 1] == ' ' || cub->map[i][j
					+ 1] == ' ' || cub->map[i + 1][j] == ' ' || cub->map[i
					- 1][j] == ' '))
				return (write_error(7), 0);
		}
	}
	return (1);
}

int	check_map(t_cub *cub)
{
	if (!check_map_elements(cub))
		return (0);
	if (!check_edges(cub))
		return (0);
	return (1);
}

int	check_textures(t_cub *cub)
{
	int	fd;

	if (!cub->texture_files[0] || !cub->texture_files[1]
		|| !cub->texture_files[2] || !cub->texture_files[3])
		return (0);
	fd = open(cub->texture_files[0], O_RDONLY);
	if (fd == -1)
		return (perror("Error\n"), 0);
	close(fd);
	fd = open(cub->texture_files[1], O_RDONLY);
	if (fd == -1)
		return (perror("Error\n"), 0);
	close(fd);
	fd = open(cub->texture_files[2], O_RDONLY);
	if (fd == -1)
		return (perror("Error\n"), 0);
	close(fd);
	fd = open(cub->texture_files[3], O_RDONLY);
	if (fd == -1)
		return (perror("Error\n"), 0);
	return (close(fd), 1);
}
