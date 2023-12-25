/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou <mkhellou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 10:55:16 by ael-mhar          #+#    #+#             */
/*   Updated: 2023/07/25 15:00:31 by ael-mhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	count_sprites(char **map)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = -1;
	while (map[++i] != 0)
	{
		j = -1;
		while (map[i][++j] != 0)
		{
			if (map[i][j] == 'I')
				count++;
		}
	}
	return (count);
}

void	set_sprites(t_cub *cub)
{
	int	i;
	int	j;
	int	z;

	i = 0;
	z = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j] != 0)
		{
			if (cub->map[i][j] == 'I')
			{
				cub->map[i][j] = '0';
				cub->sprites[z].x = (j + 0.5) * WALL_REZ;
				cub->sprites[z++].y = (i + 0.5) * WALL_REZ;
			}
			j++;
		}
		i++;
	}
}

int	parse_map(t_cub *cub, int fd)
{
	cub->map_height = 0;
	cub->map_width = 0;
	cub->texture_files = ft_calloc(5, sizeof(char *));
	if (!cub->texture_files)
		return (perror("Error\n"), 0);
	cub->texture_files[4] = 0;
	cub->colors = ft_calloc(2, sizeof(t_color));
	if (!cub->colors)
		return (perror("Error\n"), free_array(cub->texture_files), 0);
	if (!parse_textures(cub, fd, 0) || !check_textures(cub))
		return (free_array(cub->texture_files), free(cub->colors), 0);
	cub->map = read_map(cub, fd);
	if (!cub->map)
		return (perror("Error\n"), free_array(cub->texture_files),
			free(cub->colors), 0);
	if (!check_map(cub))
		return (free_array(cub->texture_files), free(cub->colors),
			free_array(cub->map), 0);
	cub->count_sprites = count_sprites(cub->map);
	cub->sprites = ft_calloc(sizeof(t_sprite), cub->count_sprites);
	if (!cub->sprites)
		return (perror("Error\n"), 0);
	set_sprites(cub);
	return (1);
}
