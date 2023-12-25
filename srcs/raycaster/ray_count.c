/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou <mkhellou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:29:33 by ael-mhar          #+#    #+#             */
/*   Updated: 2023/07/26 17:31:03 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ray_count(t_ray *ray)
{
	ray->direction_of_ray = 0;
	ray->dist_from_wall = 0;
	if (ray->hd == 0)
		ray->dist_from_wall = ray->vd;
	else if (ray->vd == 0)
		ray->dist_from_wall = ray->hd;
	else if (ray->vd <= ray->hd)
	{
		ray->rx = ray->vx;
		ray->ry = ray->vy;
		ray->dist_from_wall = ray->vd;
		ray->direction_of_ray = VERTICAL;
	}
	else if (ray->vd >= ray->hd)
	{
		ray->rx = ray->hx;
		ray->ry = ray->hy;
		ray->dist_from_wall = ray->hd;
		ray->direction_of_ray = HORIZONTAL;
	}
}

void	init_ray(t_ray *ray, t_cub *cub)
{
	ray->vd = 0;
	ray->hd = 0;
	ray->x_step = 0;
	ray->y_step = 0;
	ray->stop_ray = 0;
	ray->hy = cub->py;
	ray->hx = cub->px;
	ray->vy = cub->py;
	ray->vx = cub->px;
	ray->rx = cub->px;
	ray->ry = cub->py;
	ray->ra = cub->pa - degree(FOV_ANGLE / 2);
	if (ray->ra < 0)
		ray->ra += M_PI + M_PI;
	if (ray->ra > M_PI + M_PI)
		ray->ra -= M_PI + M_PI;
}

void	draw_wall(int x0, t_ray *ray, t_cub *cub)
{
	t_strip	strip;

	strip.texture = texture_selection(ray, cub);
	fish_eye_correction(ray, cub);
	lenth_and_offset_calculations(&strip, ray);
	texture_cordonates_generation(&strip, ray);
	texture_drawing(&strip, cub, x0);
}

int	draw_ray(t_cub *cub)
{
	int		x;
	t_ray	ray;

	init_ray(&ray, cub);
	x = -1;
	while (++x < WIDTH)
	{
		horizontal_count(&ray, cub);
		vertical_count(&ray, cub);
		ray_count(&ray);
		draw_wall(x, &ray, cub);
		ray.ra += degree(FOV_ANGLE / WIDTH);
		if (ray.ra < 0.0 || cub->pa < -0.0)
			ray.ra += M_PI + M_PI;
		else if (ray.ra > M_PI + M_PI)
			ray.ra -= M_PI + M_PI;
	}
	return (1);
}
