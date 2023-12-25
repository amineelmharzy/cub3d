/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou <mkhellou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:58:59 by mkhellou          #+#    #+#             */
/*   Updated: 2023/07/25 12:19:40 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_map(t_cub *cub)
{
	int			x;
	int			y;

	x = -1;
	while (++x < cub->map_width * WALL_REZ)
	{
		y = -1;
		while (++y < cub->map_height * WALL_REZ)
		{
			if (ft_strchr("1", cub->map[y / WALL_REZ][x / WALL_REZ]))
				draw_pixel_map(x, y, cub, ft_pixel(0, 0, 0, 255));
			else if (ft_strchr("0NSEW", cub->map[y / WALL_REZ][x / WALL_REZ]))
				draw_pixel_map(x, y, cub, ft_pixel(255, 255, 255, 255));
			else if (ft_strchr("C", cub->map[y / WALL_REZ][x / WALL_REZ]))
				draw_pixel_map(x, y, cub, ft_pixel(255, 0, 0, 255));
			else if (ft_strchr("O", cub->map[y / WALL_REZ][x / WALL_REZ]))
				draw_pixel_map(x, y, cub, ft_pixel(0, 255, 0, 255));
		}
	}
}
