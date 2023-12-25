/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_calculations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou <mkhellou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:56:03 by mkhellou          #+#    #+#             */
/*   Updated: 2023/07/25 12:05:06 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

mlx_texture_t	*texture_selection(t_ray *ray, t_cub *cub)
{
	if (ray->type == WALL)
	{
		if (ray->direction_of_ray == VERTICAL && is_left(ray->ra))
			return (cub->textures->west);
		else if (ray->direction_of_ray == VERTICAL && is_right(ray->ra))
			return (cub->textures->east);
		else if (ray->direction_of_ray == HORIZONTAL && is_up(ray->ra))
			return (cub->textures->north);
		else if (ray->direction_of_ray == HORIZONTAL && is_down(ray->ra))
			return (cub->textures->south);
	}
	if (ray->type == CLOSED_DOOR)
		return (cub->textures->door);
	return (NULL);
}

void	fish_eye_correction(t_ray *ray, t_cub *cub)
{
	double	ca;

	ca = cub->pa - ray->ra;
	if (ca < 0)
		ca += M_PI + M_PI;
	if (ca > M_PI + M_PI)
		ca -= M_PI + M_PI;
	ray->dist_from_wall = (ray->dist_from_wall * cos(ca));
}

void	lenth_and_offset_calculations(t_strip *strip, t_ray *ray)
{
	strip->real_distance = (WIDTH / 2) / (tan((FOV_ANGLE / 2) * (M_PI / 180.0))
			+ 0.00000001);
	strip->lineh = (WALL_REZ / ray->dist_from_wall) * strip->real_distance;
	strip->text_y_step = strip->texture->height / strip->lineh;
	strip->texty_off = 0;
	if (strip->lineh > HEIGHT - 1)
	{
		strip->texty_off = (strip->lineh - HEIGHT) / 2;
		strip->lineh = (HEIGHT - 1);
	}
	strip->lineo = (HEIGHT / 2) - 1 - strip->lineh / 2;
}

void	texture_cordonates_generation(t_strip *strip, t_ray *ray)
{
	strip->ty = strip->text_y_step * strip->texty_off;
	strip->tx = 0;
	if (ray->direction_of_ray)
	{
		strip->tx = (int)(ray->rx * strip->texture->width / WALL_REZ)
			% (strip->texture->width);
		if (is_down(ray->ra))
			strip->tx = strip->texture->width - 1 - strip->tx;
	}
	else
	{
		strip->tx = (int)(ray->ry * strip->texture->width / WALL_REZ)
			% (strip->texture->width);
		if (is_left(ray->ra))
			strip->tx = strip->texture->width - 1 - strip->tx;
	}
}

void	texture_drawing(t_strip *strip, t_cub *cub, int x0)
{
	uint32_t	*text;
	int			x;
	int			y;

	text = (uint32_t *)strip->texture->pixels;
	x = -1;
	while (++x < 1)
	{
		y = -1;
		while (++y < (int)strip->lineh)
		{
			if (x0 + x > 0 && y + strip->lineo > 0 && x0 + x <= WIDTH && y
				+ strip->lineo <= HEIGHT)
				mlx_put_pixel(cub->backround, x0 - 1 + x, y + strip->lineo,
					color_selection(strip, text));
			strip->ty += strip->text_y_step;
		}
	}
}
