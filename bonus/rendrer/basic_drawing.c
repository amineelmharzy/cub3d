/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_drawing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou <mkhellou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:58:16 by mkhellou          #+#    #+#             */
/*   Updated: 2023/07/24 14:39:27 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_pixel_map(uint32_t x, uint32_t y, t_cub *cub, uint32_t color)
{
	if (x * MAP_SCALE >= 0 && y * MAP_SCALE >= 0 && x * MAP_SCALE <= WIDTH && y
		* MAP_SCALE <= HEIGHT)
		mlx_put_pixel(cub->backround, x * MAP_SCALE, y * MAP_SCALE, color);
}

void	draw_pixel(uint32_t x, uint32_t y, t_cub *cub, uint32_t color)
{
	if (x >= 0 && y >= 0 && x <= WIDTH && y <= HEIGHT)
		mlx_put_pixel(cub->backround, x, y, color);
}

void	draw_floor_and_celling(t_cub *cub)
{
	uint32_t	x;
	uint32_t	y;
	uint32_t	color;

	x = -1;
	while (++x < cub->backround->width)
	{
		y = -1;
		while (++y < cub->backround->height / 2)
		{
			color = ft_pixel(cub->colors[CL].red, cub->colors[CL].green,
					cub->colors[CL].blue, 255);
			draw_pixel(x, y, cub, color);
		}
		y = cub->backround->height / 2 - 1;
		while (++y < cub->backround->height)
		{
			color = ft_pixel(cub->colors[FL].red, cub->colors[FL].green,
					cub->colors[FL].blue, 255);
			draw_pixel(x, y, cub, color);
		}
	}
}

void	draw_player(t_cub *cub)
{
	int				player_resolution;
	unsigned int	player_color;
	int				x;
	int				y;

	player_resolution = 10;
	player_color = ft_pixel(0, 0, 255, 255);
	x = (int)(cub->px - player_resolution / 2) - 1;
	while (++x < (int)(cub->px + player_resolution / 2))
	{
		y = (int)(cub->py - player_resolution / 2) - 1;
		while (++y < (int)(cub->py + player_resolution / 2))
		{
			draw_pixel_map(x, y, cub, player_color);
		}
	}
}
