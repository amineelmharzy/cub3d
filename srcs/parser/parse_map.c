/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou <mkhellou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 10:55:16 by ael-mhar          #+#    #+#             */
/*   Updated: 2023/07/20 21:16:30 by ael-mhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	parse_map(t_cub *cub, int fd)
{
	cub->map_height = 0;
	cub->map_width = 0;
	cub->texture_files = ft_calloc(5, sizeof(char *));
	if (!cub->texture_files)
		return (0);
	cub->texture_files[4] = 0;
	cub->colors = ft_calloc(2, sizeof(t_color));
	if (!cub->colors)
		return (_free(cub->texture_files), 0);
	if (!parse_textures(cub, fd, 0) || !check_textures(cub))
		return (_free(cub->texture_files), free(cub->colors), 0);
	cub->map = read_map(cub, fd);
	if (!cub->map)
		return (_free(cub->texture_files), free(cub->colors), 0);
	if (!check_map(cub))
		return (_free(cub->texture_files), free(cub->colors),
			_free(cub->map), 0);
	return (1);
}
