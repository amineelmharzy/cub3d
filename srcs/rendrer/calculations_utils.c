/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou <mkhellou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:58:34 by mkhellou          #+#    #+#             */
/*   Updated: 2023/07/20 14:34:14 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_pixel(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

double	distance_between_tow_points(double x1, double y1, double x2, double y2)
{
	double	dx;
	double	dy;
	double	distance;

	dx = x2 - x1;
	dy = y2 - y1;
	distance = sqrt((dx * dx) + (dy * dy));
	return (distance);
}

double	degree(double angle)
{
	return ((M_PI / 180.0) * angle);
}

int	is_in_wall(t_cub *cub, double x, double y)
{
	if (x < 0 || x > (cub->map_width) * WALL_REZ || y < 0
		|| y > (cub->map_height) * WALL_REZ)
		return (0);
	if (cub->map[(int)(y / WALL_REZ)][(int)(x / WALL_REZ)] == '1')
		return (1);
	return (0);
}

uint32_t	color_selection(t_strip *strip, uint32_t *text)
{
	int	a;
	int	b;
	int	g;
	int	r;

	a = (text[((int)(strip->ty) * (strip->texture->width)
				+ (int)(strip->tx))] >> 24) & 0xFF;
	b = (text[((int)(strip->ty) * (strip->texture->width)
				+ (int)(strip->tx))] >> 16) & 0xFF;
	g = (text[((int)(strip->ty) * (strip->texture->width)
				+ (int)(strip->tx))] >> 8) & 0xFF;
	r = text[((int)(strip->ty) * (strip->texture->width)
			+ (int)(strip->tx))] & 0xFF;
	return (ft_pixel(r, g, b, a));
}
